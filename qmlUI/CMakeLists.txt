cmake_minimum_required(VERSION 3.16)

project(QmlUI VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 6.4 COMPONENTS Quick REQUIRED)

qt_add_executable(appQmlUI
    main.cpp
)

qt_add_qml_module(appQmlUI
    URI QmlUI
    VERSION 1.0
    QML_FILES
        main.qml

        Pages/Card/Beast.qml
        Pages/Card/Statistics.qml
        Pages/Card/Equipment.qml
        Pages/Card/Notes.qml
        Pages/Creation/Attributes.qml
        Pages/Creation/Origin.qml
        Pages/Creation/Profession.qml
        Pages/Creation/Specialization.qml
        Pages/Creation/Skills.qml
        Pages/Creation/Tricks.qml

        Views/Card.qml
        Views/Cards.qml
        Views/Creation.qml
        Views/Pets.qml
        Views/Welcome.qml

        Common/TooltipPopup.qml
        Common/FormPopup.qml

        Forms/ExperienceForm.qml
        Forms/WoundForm.qml

        Delegates/Card/Beast/CombatAction.qml
        Delegates/Card/Beast/Command.qml
        Delegates/Card/Beast/Condition.qml
        Delegates/Card/Beast/Maneuver.qml
        Delegates/Card/Equipment/BackpackItem.qml
        Delegates/Card/Equipment/ArmorPart.qml
        Delegates/Card/Equipment/Resource.qml
        Delegates/Card/Equipment/Weapon.qml
        Delegates/Card/Notes/FormQuestion.qml
        Delegates/Card/Statistics/Symptom.qml
        Delegates/Card/Statistics/Trick.qml
        Delegates/Card/Statistics/Modifiers/ModifierCategory.qml
        Delegates/Card/Statistics/OtherSkill.qml
        Delegates/Card/Statistics/Wound.qml
        Delegates/Creation/AttributeDescription.qml
        Delegates/Creation/AttributeValue.qml
        Delegates/Creation/Feature.qml

        Elements/Card/Common/DataField.qml
        Elements/Card/Common/HeaderLabel.qml
        Elements/Card/Common/List.qml
        Elements/Card/Common/Portrait.qml
        Elements/Card/Common/ScrollTextArea.qml
        Elements/Card/Common/TooltipContent.qml
        Elements/Card/Common/ValueLabel.qml

        Elements/Card/Beast/AttributeRow.qml
        Elements/Card/Beast/Damage.qml
        Elements/Card/Beast/Data.qml
        Elements/Card/Beast/Stats.qml
        Elements/Card/Beast/StatsField.qml

        Elements/Card/Equipment/Armor.qml
        Elements/Card/Equipment/Resources.qml
        Elements/Card/Equipment/StatsWeaponRanged.qml
        Elements/Card/Equipment/StatsWeaponMelee.qml
        Elements/Card/Equipment/StatsText.qml
        Elements/Card/Equipment/StatsSpinBox.qml
        Elements/Card/Equipment/StatsSpecials.qml

        Elements/Card/Statistics/Attribute.qml
        Elements/Card/Statistics/AttributeLabel.qml
        Elements/Card/Statistics/DifficultyLevels.qml
        Elements/Card/Statistics/DifficultyLevelValue.qml
        Elements/Card/Statistics/DiseaseTooltip.qml
        Elements/Card/Statistics/Experience.qml
        Elements/Card/Statistics/Modifiers.qml
        Elements/Card/Statistics/Personal.qml
        Elements/Card/Statistics/ReputationTooltip.qml
        Elements/Card/Statistics/TrickTooltip.qml
        Elements/Card/Statistics/NSSkillpack.qml
        Elements/Card/Statistics/NSSkill.qml
        Elements/Card/Statistics/Wounds.qml

        Placeholders/PagePlaceholder.qml
        Elements/Creation/Skills/Attribute.qml
        Elements/Creation/Skills/AttributeDiffcultyLevels.qml
        Elements/Creation/Skills/DifficultyLevel.qml
        Elements/Creation/Skills/OtherSkill.qml
        Elements/Creation/Skills/Skillpack.qml
        Elements/Creation/Skills/Skill.qml
        Elements/Creation/Tricks/Trick.qml
)

set_target_properties(appQmlUI PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQmlUI
    PRIVATE
        Qt6::Quick
        View
        Data
        Managers
)

install(TARGETS appQmlUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
