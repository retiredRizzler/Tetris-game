#include <catch2/catch_test_macros.hpp>
#include "model/GameBoard.h"
#include "model/pieces/TPiece.h"
#include "model/pieces/IPiece.h"
#include "model/pieces/ZPiece.h"

TEST_CASE( "Test of the isInsideBoard function") {

    SECTION("testIsInsideBoard"){
        GameBoard board(5, 8);
        // Valid positions within board boundaries
        REQUIRE(board.isInsideBoard(2, 4) == true);
        REQUIRE(board.isInsideBoard(0, 0) == true);
        REQUIRE(board.isInsideBoard(4, 7) == true);

        // Invalid positions outside board boundaries
        REQUIRE(board.isInsideBoard(-1, 3) == false);
        REQUIRE(board.isInsideBoard(5, 1) == false);
        REQUIRE(board.isInsideBoard(2, 8) == false);
    }
}

TEST_CASE("GameBoard: setPieceAt and getPieceAt") {

}

TEST_CASE("getOccupiedPositions") {
    GameBoard board(10,20);
    SECTION("No occupied positions") {
        REQUIRE(board.getOccupiedPositions().empty() == true);
    }
    SECTION("Occupied positions") {
        std::shared_ptr<Piece> iPiece = std::make_shared<Piece>(IPiece());
        std::shared_ptr<Piece> tPiece = std::make_shared<Piece>(TPiece());
        std::shared_ptr<Piece> zPiece = std::make_shared<Piece>(ZPiece());

        board.setPieceAt(3, 3, iPiece);
        board.setPieceAt(6, 6, tPiece);
        board.setPieceAt(7, 15, zPiece);

        REQUIRE(board.getOccupiedPositions().size() == 12);
    }
}


