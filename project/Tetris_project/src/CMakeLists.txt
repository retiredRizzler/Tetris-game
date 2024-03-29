cmake_minimum_required(VERSION 3.5)


add_executable(Tetris_project
    main.cpp

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
    model/GameSate.h
    model/GameState.cpp




)

install(TARGETS Tetris_project
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
