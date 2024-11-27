#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"
using namespace std;

#define DELAY_CONST 100000

GameMechs *myGM;
Player *myPlayer;

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
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    
    int boardX = myGM -> getBoardSizeX(); // 30
    int boardY = myGM -> getBoardSizeY(); // 15
    MacUILib_printf("####################\n");
    for (int i=0; i<boardY; i++){
        for(int j=0; j<boardX; j++){
            if (j==0 || j==(boardX-1))
                MacUILib_printf("#");
            else
                MacUILib_printf(" ");
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("####################\n");
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    delete myGM;
    delete myPlayer;
    MacUILib_uninit();
}
