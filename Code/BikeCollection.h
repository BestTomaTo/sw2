#ifndef BIKECOLLECTION_H
#define BIKECOLLECTION_H

#include <string>
#include "FileManager.h"
#include "Bike.h"
using namespace std;

class BikeCollection {
    private:
        Bike* BikeArray;
        int cnt = 0; 
        FileManager* filemanager;
    public:
        BikeCollection(FileManager* filemanager);
        void addNewBike(string bikeid, string bikename);
        Bike* getBike(string bikeid); 
        
};

#endif