#include <string>
#include "Bike.h"
using namespace std;

class BikeCollection {
    private:
        Bike* BikeArray;
        int cnt = 0; 
    public:
        BikeCollection();
        void addNewBike(string bikeid, string bikename);
        Bike* getBike(string bikeid); 
        
};