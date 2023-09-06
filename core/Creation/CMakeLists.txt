find_package(Qt6 6.4 COMPONENTS Core Qml)

qt_add_qml_module(Creation
    URI core.creation
    VERSION 1.0
    SOURCES
        Statistics/AttributeCreation.h
        Statistics/AttributeCreation.cpp
        Statistics/SkillCreation.h
        Statistics/SkillCreation.cpp
        Statistics/SkillpackCreation.h
        Statistics/SkillpackCreation.cpp
        Statistics/StatisticsCreation.h
        Statistics/StatisticsCreation.cpp
)

target_include_directories(Creation
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Statistics
        ${CMAKE_CURRENT_SOURCE_DIR}/../Source/Statistics
        ${CMAKE_CURRENT_SOURCE_DIR}/../Source/Statistics/Bonus
)

target_link_libraries(Creation
    PRIVATE
        Source
)
