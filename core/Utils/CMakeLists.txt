project(Utils VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 6.4 COMPONENTS Core)

add_library(Utils
    CardWriter.h
    CardWriter.cpp
    CardConverter.h
    CardConverter.cpp
    JsonLoader.h
    JsonLoader.cpp
)

target_link_libraries(Utils
    PRIVATE
        Qt6::Core
)
