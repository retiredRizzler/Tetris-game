#include <catch2/catch_test_macros.hpp>
#include "model/PieceBag.h"

TEST_CASE("PieceBag: Constructor and getBag") {
    PieceBag bag(5);

    REQUIRE(bag.getBag().size() == 5);

    const std::vector<std::shared_ptr<Piece>>& bagContents = bag.getBag();
}
