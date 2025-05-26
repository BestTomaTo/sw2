#ifndef CHECKBIKE_H
#define CHECKBIKE_H

#include "checkBikeUI.h"
#include "MemberCollection.h"
#include "RentalCollection.h"
#include "FileManager.h"
using namespace std;

class checkBikeUI;

class checkBike{
    private:
        checkBikeUI* checkbikeUI;
        MemberCollection* MemCollPointer;
        RentalCollection* RentCollPointer;
        FileManager* filemanager;
    public:
        checkBike(MemberCollection* MemberCollection, RentalCollection* RentalCollection, FileManager* filemanager);
        void showBikeInfo();
};

#endif