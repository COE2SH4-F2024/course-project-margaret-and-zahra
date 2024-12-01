#include <iostream>
#include "MacUILib.h"
//#include "objPos.h"

#include "Food.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs *myGM;
Player *myPlayer;
Food *myFood; 

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    
    MacUILib_init();
    MacUILib_clearScreen();

    myFood=new Food();
    myGM = new GameMechs();
    myPlayer = new Player(myGM, myFood);

    myFood->generateFood(myPlayer->getPlayerPos());
}

void GetInput(void)
{
   myGM->collectAsyncInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    //myGM->clearInput();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    objPosArrayList* playerPos = myPlayer->getPlayerPos();
    int playerSize = playerPos->getSize();
    
    
    int foodPosX = myFood->getFoodPosX();
    int foodPosY = myFood->getFoodPosY();

    objPos foodPos = myFood->getFoodPos();
    
    int boardX = myGM -> getBoardSizeX(); // 30
    int boardY = myGM -> getBoardSizeY(); // 15

    int isValid=0;
    MacUILib_printf("%c = [%d, %d]\n", foodPos.symbol, foodPosX, foodPosY);
    for (int i=0; i<boardY; i++){
        for(int j=0; j<boardX; j++){
            for(int k=0; k<playerSize; k++){
                objPos thisSeg = playerPos->getElement(k);
                isValid = 0;
                if (i==thisSeg.pos->y && j==thisSeg.pos->x){
                    if (k==0)
                        MacUILib_printf("%c", thisSeg.symbol);
                    else
                        MacUILib_printf("~");
                    isValid=1;
                    break;
                }
                // check if the current g=segment x,y pos matches the (j,i) coordinate
                // if yes, print the symbol
            }
            if (i==foodPosY && j==foodPosX){
                MacUILib_printf("o");
            }
            else if (j==0 || j==boardX - 1 || i==0 || i==boardY - 1)
                MacUILib_printf("%c", '#');
            else if (isValid==0)
                MacUILib_printf("%c", ' ');
            
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Score: %d\n", myGM->getScore());

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    delete myGM;
    delete myPlayer;
    delete myFood;
    //MacUILib_clearScreen();    
    MacUILib_uninit();
}
