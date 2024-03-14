cmake_minimum_required(VERSION 3.5)


add_executable(ProjectStructure
    main.cpp
    MyClass.h
    MyClass.cpp

    ZPiece.cpp
    Piece.hpp
    Position.hpp
    IPiece.cpp
    TPiece.cpp
    JPiece.cpp
    SPiece.cpp
    SquarePiece.cpp

)

install(TARGETS ProjectStructure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
