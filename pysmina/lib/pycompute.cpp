#include "pycompute.h"
#include <boost/program_options/variables_map.hpp>
#include <boost/python.hpp>

#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string>
#include <any>

namespace python = boost::python;

// compile time FNV-1a
constexpr uint32_t Hash32_CT(const char *str, size_t n, uint32_t basis = UINT32_C(2166136261))
{
    return n == 0 ? basis : Hash32_CT(str + 1, n - 1, (basis ^ str[0]) * UINT32_C(16777619));
}

#define TYPEID(T) Hash32_CT(#T, sizeof(#T) - 1)

static const std::map<std::string, uint32_t> get_type{
    {"int", TYPEID(long)},
    {"str", TYPEID(std::string)},
    {"float", TYPEID(double)},
    {"dict", TYPEID(std::map)},
    {"list", TYPEID(std::vector)},
};

template <typename MAP>
struct map_wrapper
{
    typedef typename MAP::key_type K;
    typedef typename MAP::mapped_type V;
    typedef typename MAP::const_iterator CIT;

    map_wrapper(const MAP &m) : m_map(m) {}

    const V &get(const K &key, const V &default_val) const
    {
        CIT it = m_map.find(key);
        if (it == m_map.end())
            return default_val;
        return it->second;
    }

private:
    const MAP &m_map;
};

template <typename MAP>
map_wrapper<MAP> wrap_map(const MAP &m)
{
    return map_wrapper<MAP>(m);
}

const std::vector<std::string> pyListToVect(const boost::python::list &pylist)
{
    std::vector<std::string> list;
    for (int i = 0; i < python::len(pylist); ++i)
    {
        python::object pyobj(pylist[i]);
        list.push_back(static_cast<std::string>(python::extract<std::string>(pyobj)));
    }
    return list;
}

const std::map<std::string, std::any> pyDictToMap(const boost::python::dict &pydict)
{
    std::map<std::string, std::any> mappy;

    python::list keys = python::list(pydict.keys());
    python::list values = python::list(pydict.values());

    for (int i = 0; i < python::len(pydict); ++i)
    {
        python::object pyobj(values[i]);
        python::object pyobjkey(keys[i]);
        std::string key = python::extract<std::string>(pyobjkey);

        switch (wrap_map(get_type).get(Py_TYPE(pyobj.ptr())->tp_name, 0))
        {
        case (TYPEID(std::string)):
        {
            mappy[key] = static_cast<std::string>(python::extract<std::string>(pyobj));
            break;
        }
        case (TYPEID(long)):
        {
            mappy[key] = static_cast<long>(python::extract<long>(pyobj));
            break;
        }
        case (TYPEID(double)):
        {
            mappy[key] = static_cast<double>(python::extract<double>(pyobj));
            break;
        }
        case (TYPEID(std::vector)):
        {
            mappy[key] = pyListToVect(python::extract<python::list>(pyobj));
            break;
        }
        case (TYPEID(std::map)):
        {
            break;
        }
        default:
            break;
        }
    };
    return mappy;
}

std::stringstream addoptions(const std::map<std::string, std::any> mappy)
{
    std::stringstream ostream;
    for (const auto &it : mappy)
    {
        bool is_char;
        try
        {
            std::any_cast<const char *>(it.second);
            is_char = true;
        }
        catch (const std::bad_any_cast &)
        {
            is_char = false;
        }
        bool is_str;
        try
        {
            std::any_cast<std::string>(it.second);
            is_str = true;
        }
        catch (const std::bad_any_cast &)
        {
            is_str = false;
        }
        if (((std::any)it.second).type() == typeid(int))
        {
            ostream << it.first << "=" << std::any_cast<int>(it.second) << std::endl;
        }
        else if (((std::any)it.second).type() == typeid(long))
        {
            ostream << it.first << "=" << std::any_cast<long>(it.second) << std::endl;
        }
        else if (((std::any)it.second).type() == typeid(bool))
        {
            ostream << it.first << "=" << std::any_cast<bool>(it.second) << std::endl;
        }
        else if (((std::any)it.second).type() == typeid(double))
        {
            ostream << it.first << "=" << std::any_cast<double>(it.second) << std::endl;
        }
        else if (is_char)
        {
            ostream << it.first << "=" << std::any_cast<const char *>(it.second) << std::endl;
        }
        else if (is_str)
        {
            std::string temp = std::any_cast<std::string>(it.second);
            if (temp.size())
            {
                ostream << it.first << "=" << temp << std::endl;
            }
            else
            {
                ostream << it.first << "="
                        << "true" << std::endl;
            }
        }
        else
        { // Assumes that the only remainder is vector<string>
            try
            {
                std::vector<std::string> vect = std::any_cast<std::vector<std::string>>(it.second);
                for (std::vector<std::string>::iterator oit = vect.begin();
                     oit != vect.end(); oit++)
                {
                    // ostream << it.first << std::endl;
                    ostream << it.first << "=" << (*oit) << std::endl;
                }
            }
            catch (const std::bad_any_cast &)
            {
                std::cerr << "UnknownType(" << ((std::any)it.second).type().name() << ")" << std::endl;
            }
        }
    }
    return ostream;
};