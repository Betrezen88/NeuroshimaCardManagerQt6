find_package(Qt6 6.4 COMPONENTS Core Qml)

qt_add_qml_module(Source
    URI core.source
    VERSION 1.0
    SOURCES
        Statistics/Bonus/BonusSource.h
        Statistics/Bonus/BonusBeast.h
        Statistics/Bonus/BonusBeast.cpp
        Statistics/Bonus/BonusFame.h
        Statistics/Bonus/BonusFame.cpp
        Statistics/Bonus/BonusFeatures.h
        Statistics/Bonus/BonusFeatures.cpp
        Statistics/Bonus/BonusFriend.h
        Statistics/Bonus/BonusFriend.cpp
        SourceDocument.h
        SourceDocument.cpp

    DEPENDENCIES
        Data
)
target_link_libraries(Source
    PRIVATE
        Data
)
