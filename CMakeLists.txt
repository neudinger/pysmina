cmake_minimum_required(VERSION 3.20)
project(pysmina) # LANGUAGES CXX CUDA
set(TARGET "sminalib")
# set(USE_CUDA /usr/local/cuda-11.1)
# set(CUDA_HOME /usr/local/cuda-11.1/)
# set(USE_CUDA on)

set(CMAKE_EXE_LINKER_FLAGS "-Wno-non-template-friend")

if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Release)
        message("CMAKE_BUILD_TYPE is " ${CMAKE_BUILD_TYPE})
endif(NOT CMAKE_BUILD_TYPE)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake/Modules)
message("CMAKE_MODULE_PATH is " ${CMAKE_MODULE_PATH})

file(GLOB sminasrc
    "pysmina/lib/*.h"
    "pysmina/lib/*.cpp"
    # "pysmina/lib/*.cu"
)

# add_compile_definitions(SMINA_GPU=True)

message("CMAKE_CURRENT_BINARY_DIR is " ${CMAKE_CURRENT_BINARY_DIR})

find_package(PythonLibs 3.8 REQUIRED)
find_package(Boost REQUIRED  COMPONENTS
  python
  iostreams 
  timer 
  system 
  regex 
  thread 
  serialization 
  filesystem 
  program_options 
  date_time
)

set(CMAKE_SHARED_MODULE_PREFIX "")
add_library(${TARGET} MODULE
    ${sminasrc}
)

find_package(Eigen3 REQUIRED)
find_package(OpenBabel3 REQUIRED)
include_directories(${TARGET} ${OPENBABEL3_INCLUDE_DIR})
include_directories(${TARGET} ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(${TARGET} ${OPENBABEL3_LIBRARIES})

include_directories(${TARGET} ${Boost_INCLUDE_DIRS})
target_link_libraries(${TARGET} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
target_include_directories(${TARGET} PRIVATE ${PYTHON_INCLUDE_DIRS})


# find_package(CUDA 11 REQUIRED)
# target_link_libraries(${TARGET} ${CUDA_LIBRARIES})
# target_compile_definitions(sminalib PRIVATE SMINA_GPU=True)

target_compile_features(${TARGET} PRIVATE cxx_std_20)