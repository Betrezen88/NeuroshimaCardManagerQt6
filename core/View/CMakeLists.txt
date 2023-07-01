find_package(Qt6 6.4 COMPONENTS Core Qml)

qt_add_qml_module(View
    URI core.view
    VERSION 1.0
    SOURCES
        Card/Statistics/Experience.h
        Card/Statistics/Experience.cpp
        Card/Statistics/Feature.h
        Card/Statistics/Feature.cpp
        Card/Statistics/Origin.h
        Card/Statistics/Origin.cpp
        Card/Statistics/Otherskill.h
        Card/Statistics/Otherskill.cpp
        Card/Statistics/Place.h
        Card/Statistics/Place.cpp
        Card/Statistics/Profession.h
        Card/Statistics/Profession.cpp
        Card/Statistics/Skill.h
        Card/Statistics/Skill.cpp
        Card/Statistics/Specialization.h
        Card/Statistics/Specialization.cpp
)
