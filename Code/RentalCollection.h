#ifndef RENTALCOLLECTION_H
#define RENTALCOLLECTION_H

#include <string>
#include "Rental.h"
#include "FileManager.h"
using namespace std;

class RentalCollection{
    private:
        Rental* RenArray;
        int cnt = 0;
        FileManager* filemanager;
    public:
        RentalCollection(FileManager* filemanager);
        void createRental(Member* member, Bike* bike);
        void getRental(Member* member);        
};

#endif