find_package(Qt6 6.4 COMPONENTS Core Qml)

qt_add_qml_module(View
    URI core.view
    VERSION 1.0
    SOURCES
        Card/Statistics/Skill.h
        Card/Statistics/Skill.cpp
)
