#include "objPosArrayList.h"

// Paste your Tested implementation here.
objPosArrayList::objPosArrayList(){
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;

    aList = new objPos[ARRAY_MAX_CAP];
}
objPosArrayList::~objPosArrayList(){
    delete[] aList;
}
int objPosArrayList::getSize() const{
    return listSize;
}
void objPosArrayList::insertHead(objPos thisPos){

}
void objPosArrayList::insertTail(objPos thisPos){

}
void objPosArrayList::removeHead(){

}
void objPosArrayList::removeTail(){

}
objPos objPosArrayList::getHeadElement() const{

}
objPos objPosArrayList::getTailElement() const{

}
objPos objPosArrayList::getElement(int index) const{
    
}
// Paste your Tested implementation here.
// Paste your Tested implementation here.
