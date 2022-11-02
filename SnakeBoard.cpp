#include <iostream>
#include <cmath>
#include "SnakeBoard.h"
#include "SnakePlayer.h"
SnakePlayer player;

using namespace std;

SnakeBoard::SnakeBoard(int width, int height, GameMode mode){
    this->width=width;
    this->height=height;
    this->mode=mode;
    this->actionCount=0;
    this->play=true;
    for (int row=0; row<width; row++){
        for (int col=0; col<height; col++){
            board[row][col].hasFood=false;
            board[row][col].hasWall=false;
        }
    }
    srand((unsigned)time(0));
    for (int wallsLeft=0; wallsLeft<=rand()%5; wallsLeft++) {
        generateWall();
    }
    generateFood();
}
int SnakeBoard::getBoardWidth() const{
    return width;
}
int SnakeBoard::getBoardHeight() const{
    return height;
}

void SnakeBoard::generateFood(){
    bool emptyField=true;
    do {
        int row=rand()%width;
        int col=rand()%height;
        for (int i = 1; i<=player.snakeBodyLength(); i++) {
            if (!board[row][col].hasWall) {
                board[row][col].hasFood=true;
                foodX=row;
                foodY=col;
                emptyField=false;
            }
        }
    } while (emptyField);
}

void SnakeBoard::generateWall(){
    int row=rand()%width;
    int col=rand()%height;
    if (!board[row][col].hasWall && !board[row][col].hasFood) {
        board[row][col].hasWall=true;

    }
}

GameMode SnakeBoard::gameMode(){
    switch (mode) {
        case EASY:
            return EASY;
            break;
        case NORMAL:
            return NORMAL;
            break;
        case HARD:
            return HARD;
            break;
        default:
            break;
    }
    return DEBUG_MODE;
}

float SnakeBoard::setDifficultyLevel() const{
    if (mode==EASY) {
        return 1;
    }
    else if (mode==NORMAL){
        return 1.5;
    }
    else if (mode==HARD){
        return 2;
    }
    return 1;
}
