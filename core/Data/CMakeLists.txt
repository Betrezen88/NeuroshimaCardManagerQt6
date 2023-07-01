find_package(Qt6 6.4 COMPONENTS Core Quick)

qt_add_qml_module(Data
    URI core.data
    VERSION 1.0
    SOURCES
        Common/Types.h
        Statistics/SkillData.h
)
