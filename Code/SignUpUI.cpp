#include <string>
#include "SignUpUI.h"
using namespace std;

void SignUpUI::insertInfo() {
    ifstream& in_fp = filemanager->getInputStream();
    
    string id, pw, pnum;
    in_fp >> id >> pw >> pnum;
    this->signUpController->createMember(id, pw, pnum);
}

void SignUpUI::startUI() {
    this->insertInfo();
}