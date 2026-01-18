cmake_minimum_required(VERSION 3.16)

# Nom du projet
project(GitCarPlAyQT VERSION 0.1 LANGUAGES CXX)

# Qt 6 automatique
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# C++ 17 obligatoire
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Modules Qt nécessaires ---
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Bluetooth)
find_package(Qt6 REQUIRED COMPONENTS Widgets Bluetooth)

# --- Liste des fichiers source ---
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    wifi.cpp
    wifi.h
    bluetooth.cpp
    bluetooth.h
    accueille.cpp
    accueille.h
)

# --- Création de l'exécutable Qt 6 ---
qt_add_executable(GitCarPlAyQT
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

# --- Lier les modules Qt nécessaires ---
target_link_libraries(GitCarPlAyQT
    PRIVATE Qt6::Widgets Qt6::Bluetooth
)

# --- Propriétés pour macOS / Windows ---
set_target_properties(GitCarPlAyQT PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

# --- Installation ---
include(GNUInstallDirs)
install(TARGETS GitCarPlAyQT
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# --- Finaliser l'exécutable Qt 6 ---
qt_finalize_executable(GitCarPlAyQT)
