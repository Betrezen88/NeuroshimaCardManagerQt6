find_package(Qt6 6.4 COMPONENTS Core Qml)

qt_add_qml_module(Source
    URI core.source
    VERSION 1.0
    SOURCES
        Statistics/Bonus/AttributeBonusSource.h
        Statistics/Bonus/AttributeBonusSingle.h
        Statistics/Bonus/AttributeBonusSingle.cpp
        Statistics/Bonus/AttributeBonusList.h
        Statistics/Bonus/AttributeBonusList.cpp
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
        Statistics/Bonus/BonusSkillpoints.h
        Statistics/Bonus/BonusSkillpoints.cpp
        Statistics/Bonus/BonusTrick.h
        Statistics/Bonus/BonusTrick.cpp
        Statistics/FeatureSource.h
        Statistics/FeatureSource.cpp
        Statistics/OriginSource.h
        Statistics/OriginSource.cpp
        SourceDocument.h
        SourceDocument.cpp

    DEPENDENCIES
        Data
)
target_link_libraries(Source
    PRIVATE
        Data
)
