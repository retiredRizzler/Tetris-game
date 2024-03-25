cmake_minimum_required(VERSION 3.5)


add_executable(Tetris_project
    main.cpp
    MyClass.h
    MyClass.cpp

    ZPiece.cpp
    Piece.h
    Position.hpp
    LPiece.cpp
    TPiece.cpp
    JPiece.cpp
    SPiece.cpp
    SquarePiece.cpp

    ConsoleView.hpp
    PieceBag.h
    PieceBag.cpp
    LPiece.h
    Piece.cpp
    IPiece.h
    IPiece.cpp
    ZPiece.h
    SPiece.h
    SquarePiece.h
    JPiece.h
    TPiece.h
    GameBoard.h
    GameBoard.cpp
    GameSate.h
    GameState.cpp



)

install(TARGETS Tetris_project
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
