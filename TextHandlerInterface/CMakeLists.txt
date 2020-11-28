cmake_minimum_required(VERSION 3.5)

project(SmartReference LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(EJDB_DIR "/apps/ejdb/release")
include_directories(${EJDB_DIR}/include)

find_package(Threads REQUIRED)
find_package(ZLIB REQUIRED)

add_executable(SmartReference
    main.cpp
    nlohmann/json.hpp
    ejdbcontroller.h ejdbcontroller.cpp
    handlerengine.h handlerengine.cpp)

target_link_libraries(SmartReference
    PRIVATE ${EJDB_DIR}/lib/libejdb-1.a
    Threads::Threads
    ZLIB::ZLIB)
