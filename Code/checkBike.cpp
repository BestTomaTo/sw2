#include "checkBike.h"
using namespace std;

checkBike::checkBike(MemberCollection* MemberCollection, RentalCollection* RentalCollection, FileManager* filemanager) {
    checkbikeUI = new checkBikeUI(this);
    MemCollPointer = MemberCollection;
    RentCollPointer = RentalCollection;
    this->filemanager = filemanager;
    checkbikeUI->startUI();
}

void checkBike::showBikeInfo() {
    ofstream& out_fp = filemanager->getOutputStream();
    
    Member* loginMember = MemCollPointer->getLoginMember();
    out_fp << "5.1 자전거 대여 리스트" << endl;
    RentCollPointer->getRental(loginMember);
    out_fp << "" << endl;
}