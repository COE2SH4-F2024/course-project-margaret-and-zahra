#include "GameMechs.h"

GameMechs::GameMechs()
{
    // z = 30, y = 15
    boardSizeX = 30;
    boardSizeY = 15;
    board = new int*[boardSizeX];

    for (int i=0; i<boardSizeX; i++)
        board[i] = new int[boardSizeY];

}

GameMechs::GameMechs(int boardX, int boardY)
{
    if (boardX<=0)
        boardX = 30;
    if (boardY<=0)
        boardY=15;
    
    boardSizeX = boardX;
    boardSizeY = boardY;

    board = new int*[boardSizeX];

    for (int i=0; i<boardSizeX; i++)
        board[i] = new int[boardSizeY];
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    for (int i=0; i<boardSizeX; i++)
        delete[] board[i];
    delete[] board;
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score += 1;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = false;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here