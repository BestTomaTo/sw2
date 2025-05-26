#include <string>
#include "Enroll.h"
using namespace std;

Enroll::Enroll(MemberCollection* MemberCollection, BikeCollection* BikeCollection) {
    enrollUI = new EnrollUI(this);
    this->MemCollPointer = MemberCollection;
    this->BikeCollPointer = BikeCollection;
    enrollUI->startUI();
}

void Enroll::addNewBike(string bikeid, string bikename) {
    if (MemCollPointer->getLoginMember() != NULL) {
        out_fp << "admin 외 등록불가" << endl;
        return;
    }
    out_fp << "3.1 자전거 등록" << endl;
    BikeCollPointer->addNewBike(bikeid, bikename);
    out_fp << "" << endl;
}