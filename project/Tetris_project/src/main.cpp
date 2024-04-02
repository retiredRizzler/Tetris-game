#include "model/GameBoard.h"
#include "view/ConsoleView.hpp"
#include "model/pieces/TPiece.h"
#include "model/pieces/JPiece.h"
#include "model/pieces/LPiece.h"

int main()
{
    GameBoard board(10, 20);

    std::shared_ptr<Piece> tPiece = std::make_shared<Piece>(TPiece());
    std::shared_ptr<Piece> jPiece = std::make_shared<Piece>(JPiece());
    std::shared_ptr<Piece> lPiece = std::make_shared<Piece>(LPiece());
    board.setPieceAt(5, 10, tPiece);
    board.setPieceAt(3,2,jPiece);
    board.setPieceAt(1,5, lPiece);

    ConsoleView::displayBoard(board);

    return 0;
}
