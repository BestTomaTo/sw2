#ifndef MEMBER_H
#define MEMBER_H

#include <string>
using namespace std;

class Member {
    private:
        string id, pw, pnum;
        int logincheck = 0;
    public:
        Member();
        Member(string id, string pw, string pnum);
        void doLogin();
        void doLogout();
        int getlogincheck();
        string getID();
        string getPW();
};

#endif