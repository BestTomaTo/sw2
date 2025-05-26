#include <string>
#include "Member.h"
using namespace std;

Member::Member() {};

Member::Member(string id, string pw, string pnum){
    this->id = id;
    this->pw = pw;
    this->pnum = pnum;
}

void Member::doLogin() {
    this->logincheck = 1;
}

void Member::doLogout() {
    this->logincheck = 0;
}

int Member::getlogincheck() {
    return this->logincheck;
}

string Member::getID(){
    return this->id;
};

string Member::getPW(){
    return this->pw;
};