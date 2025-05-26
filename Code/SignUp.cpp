#include <string>
#include "SignUp.h"
using namespace std;

SignUp::SignUp(MemberCollection* MemberCollection, FileManager* filemanager) {
    signUpUI = new SignUpUI(this, filemanager);
    this->MemCollPointer = MemberCollection;
    this->filemanager = filemanager;
    signUpUI->startUI();
}

void SignUp::createMember(string id, string pw, string pnum){
    ofstream& out_fp = filemanager->getOutputStream();
    
    out_fp << "1.1 회원가입" << endl;
    MemCollPointer->createMember(id, pw, pnum);
    out_fp << "" << endl;
}