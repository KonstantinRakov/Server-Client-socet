cmake_minimum_required(VERSION 3.25)
project(Program_2_client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(source)

set(SOURCES
    sources/main.cpp
    sources/client.cpp
)

set(HEADERS
    sources/client.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})