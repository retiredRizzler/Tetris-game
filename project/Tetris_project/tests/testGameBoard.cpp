#include <catch2/catch_test_macros.hpp>
#include "model/GameBoard.h"

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
