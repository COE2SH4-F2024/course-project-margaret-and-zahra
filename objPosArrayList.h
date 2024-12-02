#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
private:
    objPos *aList;
    int listSize;
    int arrayCapacity;

public:
    objPosArrayList();
    ~objPosArrayList();

<<<<<<< HEAD
    int getSize() const;
    void insertHead(objPos thisPos);
    void insertTail(objPos thisPos);
    void removeHead();
    void removeTail();

    objPos getHeadElement() const;
    objPos getTailElement() const;
    objPos getElement(int index) const;
=======
        int getSize() const;
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        objPos getHeadElement() const;
        objPos getTailElement() const;
        objPos getElement(int index) const;
        //objPos getElement(objPos &returnPos, int index);
>>>>>>> 78dd8a2b962f4426f6dd9994f35199db04668301
};

#endif