cmake_minimum_required(VERSION 3.25)
project(Program_1_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(sources)

set(SOURCES
    sources/main.cpp
    sources/server.cpp
    sources/inputhandler.cpp
    sources/outputhandler.cpp
)

set(HEADERS
    sources/sharedbuffer.h
    sources/server.h
    sources/inputhandler.h
    sources/outputhandler.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})