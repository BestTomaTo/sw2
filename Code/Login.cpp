#include <string>
#include "Login.h"
using namespace std;

Login::Login(MemberCollection* MemberCollection) {
    loginUI = new LoginUI(this);
    this->MemCollPointer = MemberCollection;
    loginUI->startUI();
}

void Login::checkMember(string id, string pw){
    out_fp << "2.1 로그인" << endl;
    MemCollPointer->checkSignUpMember(id, pw);
    out_fp << "" << endl;
}