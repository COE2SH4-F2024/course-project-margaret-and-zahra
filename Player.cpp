#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    playerPosList = new objPosArrayList();
    myDir = STOP;

    objPos headPos(thisGMRef->getBoardSizeX() / 2,
                    thisGMRef->getBoardSizeY() / 2,
                    '@');
    playerPosList->insertHead(headPos);
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
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
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    //Iter 3: create a temp objPos to calculate the new head position
    //        probably should get the head element of the playerPoslist as a starting point.

    // (in switch) calculate the new position of the head
    //      using the tempposition

    // (after switch) insert temp onjPos to the head of the list
    // feature 2: check if the new temp objPos overlaps the food pos (get it from GameMechs)
    //            use isPosEqual() method from objPos class
    //            if overlapped, food consumed, DON'T REMOVE SNAKE TAIL
    //            if no overlap, remove tail, complete movement

}

// More methods to be added