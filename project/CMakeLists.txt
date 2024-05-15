cmake_minimum_required(VERSION 3.5)

project(tetris_project_gui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        model/pieces/Piece.h
            model/Position.hpp
            model/pieces/LPiece.cpp
            model/pieces/TPiece.cpp
            model/pieces/JPiece.cpp
            model/pieces/SPiece.cpp
            model/pieces/SquarePiece.cpp
            model/pieces/ZPiece.cpp
            model/pieces/IPiece.cpp

            view/ConsoleView.hpp
            model/PieceBag.h
            model/PieceBag.cpp
            model/pieces/LPiece.h
            model/pieces/Piece.cpp
            model/pieces/IPiece.h
            model/pieces/IPiece.cpp
            model/pieces/ZPiece.h
            model/pieces/SPiece.h
            model/pieces/SquarePiece.h
            model/pieces/JPiece.h
            model/pieces/TPiece.h
            model/GameBoard.h
            model/GameBoard.cpp
            model/GameState.h
            model/GameState.cpp
            model/TetrisModel.h model/TetrisModel.cpp
            model/Observable.h
            model/Observable.cpp
            model/observer.h model/observer.cpp
            controller/ConsoleController.h
            controller/ConsoleController.cpp
            model/TetrisGame.h
            model/TetrisGame.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(tetris_project_gui
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        startwindow.h startwindow.cpp startwindow.ui
        GUIController.h
        GUIController.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET tetris_project_gui APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(tetris_project_gui SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(tetris_project_gui
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(tetris_project_gui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.tetris_project_gui)
endif()
set_target_properties(tetris_project_gui PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS tetris_project_gui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(tetris_project_gui)
endif()
