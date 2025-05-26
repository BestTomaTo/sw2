#include <string>
#include "SignUp.h"
using namespace std;

SignUp::SignUp(MemberCollection* MemberCollection) {
    signUpUI = new SignUpUI(this);
    this->MemCollPointer = MemberCollection;
    signUpUI->startUI();
}

void SignUp::createMember(string id, string pw, string pnum){
    out_fp << "1.1 회원가입" << endl;
    MemCollPointer->createMember(id, pw, pnum);
    out_fp << "" << endl;
}