#include <SFML/Graphics.hpp>
#include <time.h>
#include <cmath>
#include <iostream>
#include "SnakeBoard.h"
#include "SnakePlayer.h"
#include "SnakeGame.h"
using namespace std;
using namespace sf;

SnakeGame::SnakeGame(SnakeBoard board, SnakePlayer player): board(board), player(player){
    
    int row = board.getBoardWidth();
    int col = board.getBoardHeight();
    
    RenderWindow window(VideoMode(row*blockSize,col*blockSize+blockSize*3),"Snake");
    window.setFramerateLimit(board.setDifficultyLevel()*10);
    Font arcade;
    CircleShape foodBlock(1,8);
    RectangleShape snakeBlock;
    RectangleShape scoreBoard;
    Texture texture;
    Sprite snakeHead, snakeBody, snakeBodyTurn, snakeTail, food, heart;
    
    arcade.loadFromFile("/Users/matt/Documents/ProgramowanieObiektowe/Snake/Snake/Arcade.ttf");
    texture.loadFromFile("/Users/matt/Documents/ProgramowanieObiektowe/Snake/Snake/snakeSprite.png");
    snakeHead.setTexture(texture);
    snakeHead.setTextureRect(IntRect(0, 0, 32, 32));
    snakeBody.setTexture(texture);
    snakeBody.setTextureRect(IntRect(32, 0, 32, 32));
    snakeBodyTurn.setTexture(texture);
    snakeBodyTurn.setTextureRect(IntRect(32, 32, 32, 32));
    snakeTail.setTexture(texture);
    snakeTail.setTextureRect(IntRect(0, 32, 32, 32));
    
    Text playerScore;
    playerScore.setFont(arcade);
    playerScore.setCharacterSize(((row+blockSize)*(col+blockSize)/blockSize)-blockSize*0.5);
    playerScore.setOrigin(playerScore.getGlobalBounds().width*0.5, playerScore.getGlobalBounds().height*0.5);
    playerScore.setPosition(blockSize*row*0.37, blockSize*0.5);
    playerScore.setString("Score: 0");
    playerScore.setFillColor(Color(211, 236, 167));
    
    foodBlock.setRadius(blockSize/2);
    foodBlock.setOrigin(0, -blockSize*3);
    foodBlock.setFillColor(Color(196, 115, 127));
    
    snakeBlock.setSize(Vector2f(blockSize, blockSize));
    snakeBlock.setOrigin(0, -blockSize*3);
    snakeBlock.setFillColor(Color(174, 219, 92));
    
    scoreBoard.setSize(Vector2f(blockSize*row, blockSize*3));
    scoreBoard.setFillColor(Color(161, 181, 125));
    
    while (window.isOpen())
        {
            sf::Event event;
            
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            
            if (Keyboard::isKeyPressed(sf::Keyboard::D)) {
                if (player.direction!=2) {
                    player.direction=1;
                }
            }
            
            else if (Keyboard::isKeyPressed(sf::Keyboard::A)) {
                if (player.direction!=1) {
                    player.direction=2;
                }
            }
            
            else if (Keyboard::isKeyPressed(sf::Keyboard::S)) {
                if (player.direction!=4) {
                    player.direction=3;
                }
            }
            
            else if (Keyboard::isKeyPressed(sf::Keyboard::W)) {
                if (player.direction!=3) {
                    player.direction=4;
                }
            }
            if ((player.snake[0].x == board.foodX) && (player.snake[0].y == board.foodY)) {
                player.bodyLength++;
                score++;
                playerScore.setString("Score: "+to_string(score));
                for (int i = 1; i<=player.snakeBodyLength(); i++) {
                    if ((player.snake[0].x != board.foodX) && (player.snake[0].y != board.foodY)) {
                        board.generateFood();
                    }
                    else{
                        board.generateFood();
                    }
                }
            }
            
            if (board.gameMode()==EASY) {
                if (player.snake[0].x>row-1) {
                    player.snake[0].x=0;
                }
                if (player.snake[0].x<0) {
                    player.snake[0].x=row-1;
                }
                if (player.snake[0].y>col-1) {
                    player.snake[0].y=0;
                }
                if (player.snake[0].y<0) {
                    player.snake[0].y=col-1;
                }
            }
            else {
                if (player.snake[0].x>row-1 || player.snake[0].x<0 || player.snake[0].y>col-1 || player.snake[0].y<0) {
                    player.snake[0].x=0;
                    player.snake[0].y=0;
                    player.direction=1;
                    player.bodyLength=3;
                    if (score>bestScore) {
                        bestScore=score;
                    }
                    score=0;
                    playerScore.setString("Best: "+to_string(bestScore));
                }
            }
            player.update();
            player.turn();
            window.clear(Color(211, 236, 167));
            foodBlock.setPosition(board.foodX*blockSize, board.foodY*blockSize);
            window.draw(foodBlock);
            for (int i=4; i<=player.snakeBodyLength(); i++) {
                if ((player.snake[0].x == player.snake[i].x) && (player.snake[0].y == player.snake[i].y)) {
                    player.bodyLength=3;
                    if (score>bestScore) {
                        bestScore=score;
                    }
                    score=0;
                    playerScore.setString("Best: "+to_string(bestScore));
                }
            }
            for (int i=0; i<=player.snakeBodyLength(); i++) {
                snakeBlock.setPosition(player.snake[i].x*blockSize, player.snake[i].y*blockSize);
                snakeBlock.setFillColor(Color(174-i*4, 219-i*2, 92-i));
                window.draw(snakeBlock);
            }
            window.draw(scoreBoard);
            window.draw(playerScore);
            window.display();
        }
}


