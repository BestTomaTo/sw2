#include "Logout.h"
using namespace std;

Logout::Logout(MemberCollection* MemberCollection) {
    logoutUI = new LogoutUI(this);
    this->MemCollPointer = MemberCollection;
    logoutUI->startUI();
}

void Logout::getLogoutMember() {
    out_fp << "2.2 로그아웃" << endl;
    MemCollPointer->getLogoutMember();
    out_fp << "" << endl;
}