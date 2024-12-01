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
        objPos foodPos; //

    public: 
        Food();
        ~Food(); 

        void generateFood(objPosArrayList* blockoff);
        objPos getFoodPos() const; 
        //void setGameMechs( GameMechs* gameMechs);

};

#endif