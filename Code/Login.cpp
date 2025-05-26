#include <string>
#include "Login.h"
using namespace std;

Login::Login(MemberCollection* MemberCollection, FileManager* filemanager) {
    loginUI = new LoginUI(this, filemanager);
    this->MemCollPointer = MemberCollection;
    this->filemanager = filemanager;
    loginUI->startUI();
}

void Login::checkMember(string id, string pw){
    ofstream& out_fp = filemanager->getOutputStream();
    
    out_fp << "2.1 로그인" << endl;
    MemCollPointer->checkSignUpMember(id, pw);
    out_fp << "" << endl;
}