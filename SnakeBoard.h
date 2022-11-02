#ifndef SnakeBoard_h
#define SnakeBoard_h

enum GameMode{DEBUG_MODE, EASY, NORMAL, HARD};
enum GameState{RUNNING, FINISHED_WIN, FINISHED_LOSS};

struct Field{
    bool hasFood;
    bool hasWall;
    bool snakeHead;
    bool snakeBody;
    bool snakeTail;
};

class SnakeBoard{
    Field board[100][100];
    int width;
    int height;
    GameMode mode;
    int actionCount;
    bool play;
    
public:
    SnakeBoard(int width, int height, GameMode mode);
    int getBoardWidth() const;
    int sizeWidth() const;
    int getBoardHeight() const;
    int sizeHeight() const;
    void generateFood();
    int foodX;
    int foodY;
    void generateWall();
    GameMode gameMode();
    float setDifficultyLevel() const;
    GameState gameState() const;
    GameMode gameMode() const;
};

#endif
