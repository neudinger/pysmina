#ifndef VINA_COMPUTE_H
#define VINA_COMPUTE_H
#include <string>
#include <map>
#include <any>
#include <boost/python.hpp>
#include <boost/program_options.hpp>
std::stringstream addoptions(const std::map<std::string, std::any> mappy);
const std::map<std::string, std::any> pyDictToMap(const boost::python::dict &pydict);
const std::vector<std::string> pyListToVect(const boost::python::list &pylist);
#endif
