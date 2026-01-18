cmake_minimum_required(VERSION 3.16)

project(GitCarPlAyQT VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Trouver les modules Qt nécessaires ---
# Core, GUI, Widgets, et Bluetooth
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Bluetooth)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Bluetooth)

# --- Liste de tous les fichiers sources ---
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    wifi.cpp wifi.h
    bluetooth.cpp bluetooth.h
)

# --- Création de l'exécutable ---
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GitCarPlAyQT
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(GitCarPlAyQT SHARED ${PROJECT_SOURCES})
    else()
        add_executable(GitCarPlAyQT ${PROJECT_SOURCES})
    endif()
endif()

# --- Lier les modules Qt nécessaires (Widgets + Bluetooth) ---
target_link_libraries(GitCarPlAyQT
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Bluetooth
)

# --- Propriétés pour macOS / Windows ---
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.GitCarPlAyQT)
endif()

set_target_properties(GitCarPlAyQT PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# --- Installation ---
include(GNUInstallDirs)
install(TARGETS GitCarPlAyQT
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# --- Finaliser l'exécutable Qt 6 ---
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GitCarPlAyQT)
endif()

