#include "LogoutUI.h"
using namespace std;

void LogoutUI::doLogout() {
   this->logoutcontroller->getLogoutMember();
}

void LogoutUI::startUI() {
    this->doLogout();
}