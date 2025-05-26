#include <string>
#include "SignUpUI.h"
using namespace std;

void SignUpUI::insertInfo() {
    string id, pw, pnum;
    in_fp >> id >> pw >> pnum;
    this->signUpController->createMember(id, pw, pnum);
}

void SignUpUI::startUI() {
    this->insertInfo();
}