cmake_minimum_required(VERSION 3.19)
project(TP_I)

set(CMAKE_CXX_STANDARD 98)

add_executable(TP_I main.cpp lib/Employee.cpp lib/Employee.h lib/Admin.cpp lib/Admin.h lib/utils.cpp lib/utils.h lib/inputs.cpp lib/inputs.h)