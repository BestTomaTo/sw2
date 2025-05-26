#include <string>
#include "Bike.h"
using namespace std;

Bike::Bike() {};

Bike::Bike(string bikeid, string bikename) {
    this->bikeid = bikeid;
    this->bikename = bikename;
}

string Bike::getBikeID() {
    return this->bikeid;
}

string Bike::getBikeName() {
    return this->bikename;
}