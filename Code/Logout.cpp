#include "Logout.h"
using namespace std;

Logout::Logout(MemberCollection* MemberCollection, FileManager* filemanager) {
    logoutUI = new LogoutUI(this);
    this->MemCollPointer = MemberCollection;
    this->filemanager = filemanager;
    logoutUI->startUI();
}

void Logout::getLogoutMember() {
    ofstream& out_fp = filemanager->getOutputStream();
    
    out_fp << "2.2 로그아웃" << endl;
    MemCollPointer->getLogoutMember();
    out_fp << "" << endl;
}