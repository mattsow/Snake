#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "SnakePlayer.h"

using namespace std;
using namespace sf;

SnakePlayer::SnakePlayer(){
}

int SnakePlayer::snakeBodyLength(){
    return bodyLength-1;
}

void SnakePlayer::update(){
    for (int i = snakeBodyLength(); i>0; --i) {
        snake[i].x = snake[i-1].x;
        snake[i].y = snake[i-1].y;
    }
}

void SnakePlayer::turn(){
    if(direction == 1){
        snake[0].x+=1;
    }
    if(direction == 2){
        snake[0].x-=1;
    }
    if(direction == 3){
        snake[0].y+=1;
    }
    if(direction == 4){
        snake[0].y-=1;
    }
}
