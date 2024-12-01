#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include "MacUILib.h"

Player::Player(GameMechs* thisGMRef, Food* thisFRef)
{
    mainGameMechsRef = thisGMRef;
    playerPosList = new objPosArrayList();
    mainFoodRef = thisFRef;
    myDir = STOP;

    objPos headPos(thisGMRef->getBoardSizeY() / 2,
                    thisGMRef->getBoardSizeX() / 2,
                    'O');
    playerPosList->insertHead(headPos);
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here

    //delete FoodPtr; 
    delete playerPosList; 
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic 
        char input = mainGameMechsRef->getInput();

        switch (input){
            case 'w':
            case 'W':
                if (myDir != DOWN)
                {
                    myDir=UP;
                }
                break; 

            case 's':
            case 'S':
                if (myDir != UP)
                {
                    myDir=DOWN;
                }
                break;

            case 'a':
            case 'A':
                if (myDir != RIGHT)
                {
                    myDir=LEFT; 
                }
                break; 
            
            case 'd':
            case 'D':
                if (myDir != LEFT)
                {
                    myDir= RIGHT;
                }
                break;


        }         
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    objPos first(playerPosList->getHeadElement().pos->x, playerPosList->getHeadElement().pos->y, playerPosList->getElement(0).getSymbol());
     
    // first.pos->x = playerPosList->getHeadElement().pos->x;
    // first.pos->y = playerPosList->getHeadElement().pos->y;
    //playerPosList->getHeadElement(first);

    switch(myDir){

        case LEFT:
            first.pos->y--;
            break; 

        case RIGHT:
            first.pos->y++;
            break;
        
        case DOWN:
            first.pos->x++;
            break;
        
        case UP: 
            first.pos->x--;
            break; 

        default:
            break; 
    }


    if(first.pos->y <1){ // Wrap around logic
        first.pos->y = mainGameMechsRef-> getBoardSizeX() - 2;
    } else if (first.pos->y >= mainGameMechsRef -> getBoardSizeX()-1){
        first.pos->y=1; 
    }
    if (first.pos->x >= mainGameMechsRef-> getBoardSizeY()-1){
        first.pos->x=1;
    } else if (first.pos->x < 1){
        first.pos->x= mainGameMechsRef->getBoardSizeY()-2; 
    } 
    
    playerPosList->insertHead(first);
    
    if (playerPosList->getHeadElement().pos->x == mainFoodRef->getFoodPos().pos->x 
        && playerPosList->getHeadElement().pos->y==mainFoodRef->getFoodPos().pos->y){ // check for food collision
            mainFoodRef->generateFood(playerPosList);
            mainGameMechsRef->incrementScore();
    } else{ // moving mech
        playerPosList->removeTail();
    }
    
    objPos playerTemp; 
    for (int i = 1; i < playerPosList->getSize(); i++){ // check for overlap
        playerTemp = playerPosList->getElement(i);
        if (first.pos->x == playerTemp.pos->x && first.pos->y == playerTemp.pos->y){
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }
}



// More methods to be added