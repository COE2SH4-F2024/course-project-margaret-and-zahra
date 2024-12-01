#include "Food.h"
#include "MacUILib.h"

Food::Food()
{

    foodPos.pos->x = -10;
    foodPos.pos->y = -10;
    foodPos.symbol = 'o';
}

// Food::Food(int foodBoardX, int foodBoardY)
// {
//     foodPos.pos->x = -10;
//     foodPos.pos->y = -10;
//     foodPos.symbol = 'o';

//     boardX = foodBoardX;
//     boardY = foodBoardY;
// }

Food::~Food()
{

}

void Food::generateFood(objPosArrayList* blockOff)
{
    srand(static_cast<unsigned int>(time(0))); // Seed random num gen
    int size = blockOff->getSize();
    bool isValid = false;

    int sizeX = 20;
    int sizeY = 10;

    while (!isValid){
        isValid = true;

        foodPos.pos->x=(rand() % ((sizeX)-2))+1;
        foodPos.pos->y=(rand() % ((sizeY)-2))+1;
        
        for (int i=0; i < size; i++){
            if (foodPos.pos->x==blockOff->getElement(i).pos->x
                && foodPos.pos->y==blockOff->getElement(i).pos->y){
                    isValid = false; // Wrong food coords
                }
        }

        
        foodPos.setObjPos(foodPos.pos->x, foodPos.pos->y, 'o');
    }
}

objPos Food::getFoodPos(/*objPos &returnPos*/) const
{
    foodPos.pos->x=2;
    foodPos.pos->y=14;
    return foodPos;
    //return returnPos.setObjPos(foodPos.pos->x, foodPos.pos->y, foodPos.symbol);
}
