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
        Statistics/Bonus/BonusHealth.h
        Statistics/Bonus/BonusHealth.cpp
        Statistics/Bonus/BonusReputation.h
        Statistics/Bonus/BonusReputation.cpp
        Statistics/Bonus/BonusSkills.h
        Statistics/Bonus/BonusSkills.cpp
        Statistics/Bonus/BonusSkillpack.h
        Statistics/Bonus/BonusSkillpack.cpp
        Statistics/Bonus/BonusSkillpackDL.h
        Statistics/Bonus/BonusSkillpackDL.cpp
        SourceDocument.h
        SourceDocument.cpp

    DEPENDENCIES
        Data
)
target_link_libraries(Source
    PRIVATE
        Data
)
