find_package(Qt6 6.4 COMPONENTS Core Qml)

qt_add_qml_module(Managers
    URI core.managers
    VERSION 1.0
    SOURCES
)
target_link_libraries(Managers
    PUBLIC
        Data
        View
        Utils
)
