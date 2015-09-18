#include "google/gtest/include/gtest/gtest.h"
#include "../src/board.h"
#include <numeric>
#include <utility>
#include <algorithm>

std::array<std::array<SquareState,8>,8> initialBoardState();

TEST(Board, Init) {
  auto state = initialBoardState();
  Board board(state);
}

TEST(Board, WhiteMovesAvailable) {
  auto state = initialBoardState();
  Board board(state);

  auto moves = board.movesAvailable();
  auto expectedExample = std::make_pair(std::make_pair(5, 4), White);

  ASSERT_EQ(moves[std::make_pair(5, 4)], White); 
}

TEST(Board, BlackMovesAvailable) {
  auto state = initialBoardState();
  Board board(state);

  auto moves = board.movesAvailable();

  ASSERT_EQ(moves[std::make_pair(3, 4)], Black); 
}

TEST(Board, OccupiedMovesUnavailable) {
  auto state = initialBoardState();
  Board board(state);

  auto moves = board.movesAvailable();

  ASSERT_EQ(moves[std::make_pair(3, 4)], Black); 
}

TEST(Board, CornersMovesUnavailable) {
  auto state = initialBoardState();
  Board board(state);

  auto moves = board.movesAvailable();

  ASSERT_EQ(moves[std::make_pair(1, 1)], Black); 
}

std::array<std::array<SquareState,8>,8> initialBoardState(){
  std::array<std::array<SquareState,8>,8> state;
  int boardSize = 8;
  for( int x = 0; x < boardSize; x = x + 1 ){
	  for( int y = 0; y < boardSize; y = y + 1 ){
		  state[x][y] = Empty;
    }
  }
  state[4][4] = White;
  state[5][5] = White;
  state[4][5] = Black;
  state[5][4] = Black;

  return state;
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}