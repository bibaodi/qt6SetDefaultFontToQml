cmake_minimum_required(VERSION 3.16)

project(qt6-i18n-demo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appqt6-i18n-demo
    main.cpp
)

qt_add_qml_module(appqt6-i18n-demo
    URI qt6-i18n-demo
    VERSION 1.0
    QML_FILES main.qml
    SOURCES htmldocumentitem.h htmldocumentitem.cpp
)

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
