#include "Rent.h"
using namespace std;

Rent::Rent(MemberCollection* MemberCollection, BikeCollection* BikeCollection, RentalCollection* RentalCollection) {
    rentUI = new RentUI(this);
    MemCollPointer = MemberCollection;
    BikeCollPointer = BikeCollection;
    RentCollPointer = RentalCollection;
    rentUI->startUI();
}

void Rent::createRent() {
    string bikeid;
    in_fp >> bikeid;
    Member* loginMember = MemCollPointer->getLoginMember();
    Bike* rentBike = BikeCollPointer->getBike(bikeid);

    out_fp << "4.1 자전거 대여" << endl;
    RentCollPointer->createRental(loginMember, rentBike);
    out_fp << "" << endl;
}