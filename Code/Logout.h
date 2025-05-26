#ifndef LOGOUT_H
#define LOGOUT_H

#include "LogoutUI.h"
#include "MemberCollection.h"
#include "FileManager.h"
using namespace std;

class LogoutUI;

class Logout {
    private:
        LogoutUI* logoutUI;
        MemberCollection* MemCollPointer;
        FileManager* filemanager;
    public:
        Logout(MemberCollection* MemberCollection, FileManager* filemanager);
        void getLogoutMember();
};

#endif