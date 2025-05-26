#include "Rental.h"
using namespace std;

Rental::Rental() {}

Rental::Rental(Member* member, Bike* bike) {
    MemPointer = member;
    BikePointer = bike;
}

Member* Rental::getMember() {
    return MemPointer;
}

Bike* Rental::getBike() const {
    return BikePointer;
}