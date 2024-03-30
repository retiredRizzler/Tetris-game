#include <catch2/catch_test_macros.hpp>
#include "model/GameBoard.h"
#include "model/pieces/TPiece.h"
#include "model/pieces/IPiece.h"

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
    GameBoard board(4, 4);

    std::shared_ptr<Piece> testPiece = std::make_shared<Piece>(TPiece());

    board.setPieceAt(1, 2, testPiece);
    std::shared_ptr<Piece> retrievedPiece = board.getPieceAt(1, 2);

    REQUIRE(retrievedPiece != nullptr);
    REQUIRE(*retrievedPiece == *testPiece); // Check for piece type (assuming appropriate comparison)
}

TEST_CASE("GameBoard: isColliding") {
    GameBoard board(4, 4);

    std::shared_ptr<Piece> testPiece = std::make_shared<Piece>(IPiece());

    SECTION("No Collision - Empty Board") {
        REQUIRE(board.isColliding(testPiece, 2, 2) == false);
    }

    SECTION("Collision with Existing Piece") {
        board.setPieceAt(1, 1, testPiece);
        REQUIRE(board.isColliding(testPiece, 1, 1) == true);
    }

    SECTION("Collision with Board Edge (Right)") {
        REQUIRE(board.isColliding(testPiece, 0, 4) == true);
    }

    SECTION("Collision with Board Edge (Left)") {
        REQUIRE(board.isColliding(testPiece, 3, -1) == true);
    }


}

