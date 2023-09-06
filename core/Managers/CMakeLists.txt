find_package(Qt6 6.4 COMPONENTS Core Qml)

qt_add_qml_module(Managers
    URI core.managers
    VERSION 1.0
    SOURCES
        MainManager.h
        MainManager.cpp
        CardManager.h
        CardManager.cpp
)

target_include_directories(Managers
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../View/Card/
        ${CMAKE_CURRENT_SOURCE_DIR}/../View/Card/Pages
        ${CMAKE_CURRENT_SOURCE_DIR}/../View/Card/Statistics
        ${CMAKE_CURRENT_SOURCE_DIR}/../Creation
)

target_link_libraries(Managers
    PUBLIC
        Creation
        Data
        View
        Utils
)
