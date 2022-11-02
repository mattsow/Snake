#ifndef SnakePlayer_h
#define SnakePlayer_h

struct Snake{
    int x;
    int y;
};

class SnakePlayer{
public:
    Snake snake[100];
    SnakePlayer();
    int bodyLength = 3;
    int snakeBodyLength();
    int direction = 1;
    void turn();
    void update();
};

#endif
