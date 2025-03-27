cmake_minimum_required(VERSION 3.16)

project(qt6-i18n-demo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick LinguistTools REQUIRED)

qt_add_executable(appqt6-i18n-demo
    main.cpp
)

qt_add_qml_module(appqt6-i18n-demo
    URI qt6-i18n-demo
    VERSION 1.0
    QML_FILES main.qml Qmli18n.qml
    SOURCES htmldocumentitem.h htmldocumentitem.cpp
    SOURCES languagemanager.h languagemanager.cpp
)

# qt6_add_translations(appqt6-i18n-demo
#     TS_FILES
#     i18n/base.ts
#     i18n/qml_en.ts
#     i18n/qml_en_AU.ts
#     i18n/qml_zh.ts
# )
#qt_add_lupdate(appqt6-i18n-demo TS_FILES super_calc_de.ts)

#this make 'qt_add_lrelease' write output from './' to "${CMAKE_CURRENT_BINARY_DIR}/i18n" --eton@250327
set_source_files_properties(i18n/base.ts i18n/qml_en.ts i18n/qml_zh.ts
     PROPERTIES OUTPUT_LOCATION "${CMAKE_CURRENT_BINARY_DIR}/i18n")
#this generate .ts to .qm --eton@250327
qt_add_lrelease(appqt6-i18n-demo
    TS_FILES i18n/base.ts i18n/qml_en.ts i18n/qml_zh.ts
    QM_FILES_OUTPUT_VARIABLE qm_files)

#this add rcc to app bin-file, but depend on `set(CMAKE_AUTORCC ON)` --eton@250327
qt6_add_resources(appqt6-i18n-demo "RESOURCE_NAME_translations"
    PREFIX "/i18n"
    BASE "${CMAKE_CURRENT_BINARY_DIR}"
    FILES "${qm_files}") #after this qml file canbe accessed by ":i18n/i18n/xx.qm" --eton@250327

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appqt6-i18n-demo PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appqt6-i18n-demo
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appqt6-i18n-demo
    PRIVATE Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS appqt6-i18n-demo
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
# this make app deploy success. --eton@250327
qt_generate_deploy_qml_app_script(
    TARGET appqt6-i18n-demo
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
