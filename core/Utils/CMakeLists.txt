project(Utils VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 6.4 COMPONENTS Core)

add_library(Utils
    CardReader.h
    CardReader.cpp
    CardWriter.h
    CardWriter.cpp
    CardConverter.h
    CardConverter.cpp
)

target_link_libraries(Utils
    PUBLIC Qt6::Core
)
