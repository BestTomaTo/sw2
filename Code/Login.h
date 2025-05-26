#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include "LoginUI.h"
#include "MemberCollection.h"
#include "FileManager.h"
using namespace std;

class LoginUI;

class Login {
    private:
        LoginUI* loginUI;
        MemberCollection* MemCollPointer;
        FileManager* filemanager;
    public:
        Login(MemberCollection* MemberCollection, FileManager* filemanager);
        void checkMember(string id, string pw);
};

#endif