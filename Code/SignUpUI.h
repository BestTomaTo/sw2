#ifndef SIGNUPUI_H
#define SIGNUPUI_H

#include "SignUp.h"
#include "FileManager.h"
using namespace std;

class SignUp;
class FileManager;

class SignUpUI {
    private: 
        SignUp* signUpController;
        FileManager* filemanager;
    public:
        SignUpUI(SignUp* controller, FileManager* filemanager) : signUpController(controller), filemanager(filemanager) {}
        void startUI();
        void insertInfo();
};

#endif