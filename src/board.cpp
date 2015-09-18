#include "board.h"
#include <algorithm>
#include <stdexcept>

Board::Board(std::array<std::array<SquareState, 8>, 8> _boardState): boardState(_boardState) {};

Moves  Board::movesAvailable(){
	Moves v;

  	int boardSize = 8;
    for( int x = 0; x < boardSize; x = x + 1 ){
	    for( int y = 0; y < boardSize; y = y + 1 ){
	    	for ( int s = White; s <= Black; s++ ){
	    		auto possibleState = static_cast<SquareState>(s);
		  	    if (isMoveFor(possibleState, x, y)){
		  	    	v[std::make_pair(x, y)] = possibleState;
		  	    }
	    	}
        }
    }

	return v;
};

bool Board::isMoveFor(SquareState possibleState, int x, int y){
	if (boardState[x][y] != Empty) {
		return false;
	}

	for (int xDelta = -1; xDelta <=1; xDelta++){
		for (int yDelta = -1; yDelta <=1; yDelta++){
			int n = 1;
			while (boardState[coord(x,xDelta,n)][coord(y,yDelta,n)] == otherPlayer(possibleState)){
				n++;
			}

			if (n > 1 && boardState[coord(x,xDelta,n+1)][coord(y,yDelta,n+1)] == possibleState){
				return true;
			}			
		}
	}
	return false;
}

SquareState Board::otherPlayer(SquareState player){
	if (player == White) {
		return Black;
	} else if (player == Black){
		return White;
	}
	throw std::runtime_error("should have player");
}

int Board::coord(int x, int xDelta, int n) {
	return std::min(x+(xDelta*n),7);
}