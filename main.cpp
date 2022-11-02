#include <iostream>
#include "SnakeBoard.h"
#include "SnakePlayer.h"
#include "SnakeGame.h"
#include "SnakeMenu.h"
using namespace std;

int main(){
    SnakeMenu menu;
    SnakeBoard board(20, 20, NORMAL);
    SnakePlayer player;
    SnakeGame game(board, player);
    //menu.menu();
    return 0;
}
