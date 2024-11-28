#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"



using namespace std;

#define DELAY_CONST 100000

GameMechs *myGM;
Player *myPlayer;
Food* pFood; 

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

    myGM = new GameMechs();
    myPlayer = new Player(myGM);
}

void GetInput(void)
{
   myGM->collectAsyncInput();
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    objPosArrayList* playerPos = myPlayer->getPlayerPos();
    int playerSize = playerPos->getSize();

    // objPos foodPos = myGM->getFoodPos();
    int boardX = myGM -> getBoardSizeX(); // 30
    int boardY = myGM -> getBoardSizeY(); // 15
    for (int i=0; i<boardY; i++){
        for(int j=0; j<boardX; j++){

            // for(int k=0; k<playerSize; k++){
            //     objPos thisSeg = playerPos->getElement(k);

            //     // check if the current g=segment x,y pos matches the (j,i) coordinate
            //     // if yes, print the symbol
            // }

            // at the end of the for loop, do something to 
            // determine whether to continue with the if-else statement
            // or move on to the next iteration of i-j

            if (j==0 || j==boardX - 1 || i==0 || i==boardY - 1)
                MacUILib_printf("%c", '#');
            // else if (j==playerPos.pos->x && i==playerPos.pos->y)
            //     MacUILib_printf("%c", playerPos.symbol);
            else
                MacUILib_printf("%c", ' ');
        }
        MacUILib_printf("\n");
    }

    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    delete myGM;
    delete myPlayer;
    //MacUILib_clearScreen();    
    MacUILib_uninit();
}
