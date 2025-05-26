#include "checkBike.h"
using namespace std;

checkBike::checkBike(MemberCollection* MemberCollection, RentalCollection* RentalCollection) {
    checkbikeUI = new checkBikeUI(this);
    MemCollPointer = MemberCollection;
    RentCollPointer = RentalCollection;
    checkbikeUI->startUI();
}

void checkBike::showBikeInfo() {
    Member* loginMember = MemCollPointer->getLoginMember();
    out_fp << "5.1 자전거 대여 리스트" << endl;
    RentCollPointer->getRental(loginMember);
    out_fp << "" << endl;
}