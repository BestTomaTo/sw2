#ifndef ENROLL_H
#define ENROLL_H

#include <string>
#include "EnrollUI.h"
#include "MemberCollection.h"
#include "BikeCollection.h"
#include "FileManager.h"
using namespace std;

class EnrollUI;

class Enroll {
    private:
        EnrollUI* enrollUI;
        MemberCollection* MemCollPointer;
        BikeCollection* BikeCollPointer;
        FileManager* filemanager;
    public:
        Enroll(MemberCollection* MemberCollection, BikeCollection* BikeCollection, FileManager* filemanager);
        void addNewBike(string bikeid, string bikename);
};

#endif