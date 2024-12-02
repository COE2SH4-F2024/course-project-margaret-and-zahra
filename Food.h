#ifndef FOOD_H 
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "GameMechs.h"

using namespace std; 


class Food
{
    private:
        char input;
        objPos foodPos;

    public: 
        Food();
        ~Food(); 

        // Food(const Food &f);
        // Food& operator = (const Food &f);

        void generateFood(objPosArrayList* blockoff);
        //void generateFood(objPosArrayList* playerPosList);
        objPos getFoodPos() const; 
        
        int getFoodPosX() const;
        int getFoodPosY() const;

};

#endif