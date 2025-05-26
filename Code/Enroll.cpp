#include <string>
#include "Enroll.h"
using namespace std;

Enroll::Enroll(MemberCollection* MemberCollection, BikeCollection* BikeCollection, FileManager* filemanager) {
    enrollUI = new EnrollUI(this, filemanager);
    this->MemCollPointer = MemberCollection;
    this->BikeCollPointer = BikeCollection;
    this->filemanager = filemanager;
    enrollUI->startUI();
}

void Enroll::addNewBike(string bikeid, string bikename) {
    ofstream& out_fp = filemanager->getOutputStream();
    
    if (MemCollPointer->getLoginMember() != NULL) {
        out_fp << "admin 외 등록불가" << endl;
        return;
    }
    out_fp << "3.1 자전거 등록" << endl;
    BikeCollPointer->addNewBike(bikeid, bikename);
    out_fp << "" << endl;
}