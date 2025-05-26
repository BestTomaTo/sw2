#include <string>
#include "LoginUI.h"
using namespace std;

void LoginUI::doLogin() {
    ifstream& in_fp = filemanager->getInputStream();
    
    string id, pw;
    in_fp >> id >> pw;
    this->logincontroller->checkMember(id, pw);
}

void LoginUI::startUI() {
    this->doLogin();
}