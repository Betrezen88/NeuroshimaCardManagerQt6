project(Utils VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 6.4 COMPONENTS Core)

add_library(Utils
)

target_link_libraries(Utils
    PUBLIC Qt6::Core
)
