cmake_minimum_required(VERSION 3.5)

project(DummyApp1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

if(MSVC)
    include_directories(OpenLicenseModule/OpenLicenseCommunication/win64/includes)
    link_directories(OpenLicenseModule/OpenLicenseCommunication/win64)
endif()


set(PROJECT_SOURCES
        main.cpp
        mainwindow.h mainwindow.cpp mainwindow.ui
        insertkeydialog.h insertkeydialog.cpp insertkeydialog.ui
)

qt_add_executable(DummyApp1
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
)


add_subdirectory(OpenLicenseModule)

if(MSVC)
    target_link_libraries(DummyApp1 PRIVATE
        Qt6::Widgets
        OpenLicenseModule
        botan
    )
else()
    target_link_libraries(DummyApp1 PRIVATE
        Qt6::Widgets
        OpenLicenseModule
    )
endif()

set_target_properties(DummyApp1 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS DummyApp1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

qt_finalize_executable(DummyApp1)
