#ifndef SIGNUP_H
#define SIGNUP_H

#include <string>
#include "SignUpUI.h"
#include "MemberCollection.h"
#include "FileManager.h"
using namespace std;

class SignUpUI;

class SignUp {
    private:
        SignUpUI* signUpUI;
        MemberCollection* MemCollPointer;
        FileManager* filemanager;
    public:
        SignUp(MemberCollection* MemberCollection, FileManager* filemanager);    
        void createMember(string id, string pw, string pnum);
};

#endif