#ifndef LOGOUTUI_H
#define LOGOUTUI_H

#include "Logout.h"
using namespace std;

class Logout;

class LogoutUI{
    private:
        Logout* logoutcontroller;
    public:
        LogoutUI(Logout* controller) : logoutcontroller(controller) {}
        void startUI();
        void doLogout();
};

#endif