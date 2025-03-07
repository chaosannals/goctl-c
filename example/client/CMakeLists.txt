cmake_minimum_required(VERSION 3.22)

project(goctl_c_example)

include("cmake/cJSON.cmake")
include("cmake/curl.cmake")

FetchCJSON()
FetchCURL()

add_subdirectory(demo)
