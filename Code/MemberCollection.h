#ifndef MEMBERCOLLECTION_H
#define MEMBERCOLLECTION_H

#include <string>
#include "Member.h"
#include "FileManager.h"
using namespace std;

class MemberCollection {
    private:
        Member* MemArray;
        int admin = 0;
        int cnt = 0; 
        FileManager* filemanager;
    public:
        MemberCollection(FileManager* filemanager);
        void createMember(string id, string pw, string pnum); 
        void checkSignUpMember(string id, string pw);
        Member* getLoginMember();
        void getLogoutMember();
};

#endif