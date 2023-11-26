find_package(Qt6 6.4 COMPONENTS Core Qml)

qt_add_qml_module(Source
    URI core.source
    VERSION 1.0
    SOURCES
        Common/ModifierSource.cpp
        Common/ModifierSource.h
        Common/RequirementSource.cpp
        Common/RequirementSource.h

        Model/RequirementSourceModel.h
        Model/RequirementFilterProxyModel.cpp
        Model/RequirementFilterProxyModel.h
        Model/RequirementSourceModel.cpp
        Model/TrickSourceModel.h
        Model/TrickSourceModel.cpp
        Model/TrickSourceItem.h
        Model/TrickSourceItem.cpp

        Statistics/AttributeSource.cpp
        Statistics/AttributeSource.h
        Statistics/Bonus/AttributeBonusList.cpp
        Statistics/Bonus/AttributeBonusList.h
        Statistics/Bonus/AttributeBonusSingle.cpp
        Statistics/Bonus/AttributeBonusSingle.h
        Statistics/Bonus/AttributeBonusSource.h
        Statistics/Bonus/BonusBeast.cpp
        Statistics/Bonus/BonusBeast.h
        Statistics/Bonus/BonusFame.cpp
        Statistics/Bonus/BonusFame.h
        Statistics/Bonus/BonusFeatures.cpp
        Statistics/Bonus/BonusFeatures.h
        Statistics/Bonus/BonusFriend.cpp
        Statistics/Bonus/BonusFriend.h
        Statistics/Bonus/BonusHealth.cpp
        Statistics/Bonus/BonusHealth.h
        Statistics/Bonus/BonusReputation.cpp
        Statistics/Bonus/BonusReputation.h
        Statistics/Bonus/BonusSkillpack.cpp
        Statistics/Bonus/BonusSkillpack.h
        Statistics/Bonus/BonusSkillpackDL.cpp
        Statistics/Bonus/BonusSkillpackDL.h
        Statistics/Bonus/BonusSkillpoints.cpp
        Statistics/Bonus/BonusSkillpoints.h
        Statistics/Bonus/BonusSkills.cpp
        Statistics/Bonus/BonusSkills.h
        Statistics/Bonus/BonusSource.h
        Statistics/Bonus/BonusTrick.cpp
        Statistics/Bonus/BonusTrick.h
        Statistics/DiseaseSource.cpp
        Statistics/DiseaseSource.h
        Statistics/FeatureSource.cpp
        Statistics/FeatureSource.h
        Statistics/OriginSource.cpp
        Statistics/OriginSource.h
        Statistics/OtherSkillSource.cpp
        Statistics/OtherSkillSource.h
        Statistics/ProfessionSource.cpp
        Statistics/ProfessionSource.h
        Statistics/QuestionSource.cpp
        Statistics/QuestionSource.h
        Statistics/SkillSource.cpp
        Statistics/SkillSource.h
        Statistics/SkillpackSource.cpp
        Statistics/SkillpackSource.h
        Statistics/SpecializationSource.cpp
        Statistics/SpecializationSource.h
        Statistics/StatisticsSource.cpp
        Statistics/StatisticsSource.h
        Statistics/SymptomSource.cpp
        Statistics/SymptomSource.h
        Statistics/TrickSource.cpp
        Statistics/TrickSource.h

        SourceConverter.cpp
        SourceConverter.h
        SourceDocument.cpp
        SourceDocument.h
        SourceLoader.cpp
        SourceLoader.h
)

target_include_directories(Source
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Common
        ${CMAKE_CURRENT_SOURCE_DIR}/Model
        ${CMAKE_CURRENT_SOURCE_DIR}/Statistics
        ${CMAKE_CURRENT_SOURCE_DIR}/Statistics/Bonus
)

target_link_libraries(Source
    PRIVATE
        Data
        Utils
)
