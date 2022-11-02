#include "SnakeMenu.h"
#include <SFML/Graphics.hpp>
#include "SnakeBoard.h"
#include "SnakePlayer.h"
#include "SnakeGame.h"

using namespace sf;

SnakeMenu::SnakeMenu(){}

void SnakeMenu::menu(){
    RenderWindow menu(VideoMode(600,800),"Snake");
    
    while (menu.isOpen())
        {
            sf::Event event;
            
            while (menu.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    menu.close();
            }
            
            menu.clear();
            menu.display();
        }
    
}
