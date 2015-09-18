#include "square_state.h"
#include <array>
#include <utility>
#include <vector>
#include <map>

typedef std::map<std::pair<int,int>,SquareState> Moves;

class Board {
	public:
		Board(std::array<std::array<SquareState, 8>, 8> boardState); 
		Moves movesAvailable();
	private:
		const std::array<std::array<SquareState, 8>, 8> boardState;
		bool isMoveFor(SquareState state, int x, int y);
		SquareState otherPlayer(SquareState player);
		int coord(int x, int xdelta, int n);
};