cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(uvr 
	uvr_base.cpp
	uvr_base.hpp
	uvr_implementation_base.hpp
)