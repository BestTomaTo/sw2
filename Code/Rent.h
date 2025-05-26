#include "RentUI.h"
#include "MemberCollection.h"
#include "BikeCollection.h"
#include "RentalCollection.h"
using namespace std;

class Rent{
    private:
        RentUI* rentUI;
        MemberCollection* MemCollPointer;
        BikeCollection* BikeCollPointer;
        RentalCollection* RentCollPointer;
    public: 
        Rent(MemberCollection* MemberCollection, BikeCollection* BikeCollection, RentalCollection* RentalCollection);
        void createRent();
};