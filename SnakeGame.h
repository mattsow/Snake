#ifndef SnakeGame_h
#define SnakeGame_h
#include "SnakeBoard.h"
#include "SnakePlayer.h"

class SnakeGame{
    SnakeBoard board;
    SnakePlayer player;
public:
    SnakeGame(SnakeBoard board, SnakePlayer player);
    int blockSize = 50;
    int score=0;
    int bestScore;
};

#endif
