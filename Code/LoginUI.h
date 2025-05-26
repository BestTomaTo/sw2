#ifndef LOGINUI_H
#define LOGINUI_H

#include "Login.h"
#include "FileManager.h"
using namespace std;

class Login;

class LoginUI {
    private:
        Login* logincontroller;
        FileManager* filemanager;
    public:
        LoginUI(Login* controller, FileManager* filemanager) : logincontroller(controller), filemanager(filemanager) {}
        void startUI();
        void doLogin();
};

#endif