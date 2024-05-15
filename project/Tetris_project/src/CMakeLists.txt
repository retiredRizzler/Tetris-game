cmake_minimum_required(VERSION 3.5)
set(CMAKE_PREFIX_PATH "C:/Qt/6.6.2/mingw_64/lib/cmake")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_executable(Tetris_project
        model/pieces/ZPiece.cpp
    model/pieces/Piece.h
    model/Position.hpp
    model/pieces/LPiece.cpp
    model/pieces/TPiece.cpp
    model/pieces/JPiece.cpp
    model/pieces/SPiece.cpp
    model/pieces/SquarePiece.cpp

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
        TetrisApp.cpp
        gui/GameBoardWidget.cpp
        gui/GameWindow.cpp
        gui/mainwindow.cpp
        gui/ConfigWindow.cpp
        gui/ConfigWindow.h


)

target_link_libraries(Tetris_project PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS Tetris_project
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
