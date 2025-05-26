#ifndef BIKE_H
#define BIKE_H

#include <string>
using namespace std;

class Bike {
    private:
        string bikeid, bikename;
    public:
        Bike();
        Bike(string bikeid, string bikename);
        string getBikeID();
        string getBikeName();
};

#endif