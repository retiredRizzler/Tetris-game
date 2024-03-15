cmake_minimum_required(VERSION 3.5)


add_executable(ProjectStructure
    main.cpp
    MyClass.h
    MyClass.cpp

    ZPiece.cpp
    Piece.hpp
    Position.hpp
    LPiece.cpp
    TPiece.cpp
    JPiece.cpp
    SPiece.cpp
    SquarePiece.cpp
    GameState.hpp
    ConsoleView.hpp
    PieceBag.h
    PieceBag.cpp
    LPiece.h

)

install(TARGETS ProjectStructure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
