#ifndef RENT_H
#define RENT_H

#include "RentUI.h"
#include "MemberCollection.h"
#include "BikeCollection.h"
#include "RentalCollection.h"
#include "FileManager.h"
using namespace std;

class RentUI;

class Rent{
    private:
        RentUI* rentUI;
        MemberCollection* MemCollPointer;
        BikeCollection* BikeCollPointer;
        RentalCollection* RentCollPointer;
        FileManager* filemanager;
    public: 
        Rent(MemberCollection* MemberCollection, BikeCollection* BikeCollection, RentalCollection* RentalCollection, FileManager* filemanager);
        void createRent();
};

#endif