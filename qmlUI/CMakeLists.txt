cmake_minimum_required(VERSION 3.16)

project(QmlUI VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appQmlUI
    main.cpp
)

qt_add_qml_module(appQmlUI
    URI QmlUI
    VERSION 1.0
    QML_FILES
        main.qml

        Pages/Card/Statistics.qml
        Pages/Card/Equipment.qml
        Pages/Card/Notes.qml

        Views/Card.qml
        Views/Cards.qml
        Views/Creation.qml
        Views/Welcome.qml

        Delegates/Card/Equipment/BackpackItem.qml
        Delegates/Card/Equipment/ArmorPart.qml
        Delegates/Card/Equipment/Resource.qml
        Delegates/Card/Equipment/Weapon.qml
        Delegates/Card/Notes/FormQuestion.qml
        Delegates/Card/Statistics/Modifiers/ModifierCategory.qml
        Delegates/Card/Statistics/OtherSkill/OtherSkill.qml
        Delegates/Card/Statistics/Wounds/Wound.qml

        Elements/Card/Common/DataField.qml
        Elements/Card/Common/HeaderLabel.qml
        Elements/Card/Common/List.qml
        Elements/Card/Common/Portrait.qml
        Elements/Card/Common/ScrollTextArea.qml
        Elements/Card/Common/ValueLabel.qml

        Elements/Card/Beast/AttributeRow.qml
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
        Elements/Card/Statistics/Experience.qml
        Elements/Card/Statistics/Modifiers.qml
        Elements/Card/Statistics/OtherSkills.qml
        Elements/Card/Statistics/Personal.qml
        Elements/Card/Statistics/Tricks.qml
        Elements/Card/Statistics/Skillpack.qml
        Elements/Card/Statistics/Skill.qml
        Elements/Card/Statistics/Wounds.qml

        Placeholders/PagePlaceholder.qml
)

set_target_properties(appQmlUI PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQmlUI
    PRIVATE Qt6::Quick)

install(TARGETS appQmlUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
