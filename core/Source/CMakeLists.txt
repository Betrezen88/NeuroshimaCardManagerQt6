find_package(Qt6 6.4 COMPONENTS Core Qml)

qt_add_qml_module(Source
    URI core.source
    VERSION 1.0
    SOURCES
        Common/ModifierSource.h
        Common/ModifierSource.cpp
        Common/RequirementSource.h
        Common/RequirementSource.cpp

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
        Statistics/AttributeSource.h
        Statistics/AttributeSource.cpp
        Statistics/DiseaseSource.h
        Statistics/DiseaseSource.cpp
        Statistics/FeatureSource.h
        Statistics/FeatureSource.cpp
        Statistics/OriginSource.h
        Statistics/OriginSource.cpp
        Statistics/ProfessionSource.h
        Statistics/ProfessionSource.cpp
        Statistics/SkillSource.h
        Statistics/SkillSource.cpp
        Statistics/SkillpackSource.h
        Statistics/SkillpackSource.cpp
        Statistics/SpecializationSource.h
        Statistics/SpecializationSource.cpp
        Statistics/StatisticsSource.h
        Statistics/StatisticsSource.cpp
        Statistics/SymptomSource.h
        Statistics/SymptomSource.cpp
        Statistics/TrickSource.h
        Statistics/TrickSource.cpp

        SourceConverter.h
        SourceConverter.cpp
        SourceLoader.h
        SourceLoader.cpp
        SourceDocument.h
        SourceDocument.cpp

    DEPENDENCIES
        Data
)

target_include_directories(Source
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Common
        ${CMAKE_CURRENT_SOURCE_DIR}/Statistics
        ${CMAKE_CURRENT_SOURCE_DIR}/Statistics/Bonus
)

target_link_libraries(Source
    PRIVATE
        Data
        Utils
)
