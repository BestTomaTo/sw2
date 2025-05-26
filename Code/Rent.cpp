#include "Rent.h"
using namespace std;

Rent::Rent(MemberCollection* MemberCollection, BikeCollection* BikeCollection, RentalCollection* RentalCollection, FileManager* filemanager) {
    rentUI = new RentUI(this);
    MemCollPointer = MemberCollection;
    BikeCollPointer = BikeCollection;
    RentCollPointer = RentalCollection;
    this->filemanager = filemanager;
    rentUI->startUI();
}

void Rent::createRent() {
    ifstream& in_fp = filemanager->getInputStream();
    ofstream& out_fp = filemanager->getOutputStream();

    string bikeid;
    in_fp >> bikeid;
    Member* loginMember = MemCollPointer->getLoginMember();
    Bike* rentBike = BikeCollPointer->getBike(bikeid);

    out_fp << "4.1 자전거 대여" << endl;
    RentCollPointer->createRental(loginMember, rentBike);
    out_fp << "" << endl;
}