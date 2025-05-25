#include <string.h>
#include <fstream>
#include "allClasses.h"
using namespace std;

extern ifstream in_fp;


// Member


Member::Member() {};

Member::Member(string id, string pw, string pnum){
    this->id = id;
    this->pw = pw;
    this->pnum = pnum;
}

void Member::doLogin() {
cout << "debug doLogin" << endl;
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


// MemberCollection


MemberCollection::MemberCollection() {
    MemArray = new Member[100];
}

void MemberCollection::createMember(string id, string pw, string pnum){
    MemArray[cnt++] = Member(id, pw, pnum);
    cout << id << pw << pnum << endl;
}

void MemberCollection::checkMember(string id, string pw) {
cout << "debug MemColl checkMem" << endl;
cout << "debug cnt : " << cnt << endl; 
    for (int i = 0; i < cnt; i++) {
        if (MemArray[i].getID() == id && MemArray[i].getPW() == pw) {
            MemArray[i].doLogin();
cout << "debug login success" << endl;
            cout << MemArray[i].getID() << " " << MemArray[i].getPW() << endl;        
        }
    }    
}

void MemberCollection::getLogoutMember() {
    for (int i = 0; i < cnt; i++) {
        if (MemArray[i].getlogincheck() == 1) {
            MemArray[i].doLogout();
cout << "debug logout success" << endl;
            cout << MemArray[i].getID() << endl;
        }
    }
}


// Bike


Bike::Bike() {};

Bike::Bike(string bikeid, string bikename) {
    this->bikeid = bikeid;
    this->bikename = bikename;
}

string Bike::getBikeID() {
    return this->bikeid;
}

string Bike::getBikeName() {
    return this->bikename;
}


// BikeCollection


BikeCollection::BikeCollection() {
    this->BikeArray = new Bike[100];
}

void BikeCollection::addNewBike(string bikeid, string bikename){

}



// SignUpUI


void SignUpUI::insertInfo() {
    string id, pw, pnum;
    in_fp >> id >> pw >> pnum;
    this->signUpController->createMember(id, pw, pnum);
}

void SignUpUI::startUI() {
    this->insertInfo();
}


// SignUp


SignUp::SignUp(MemberCollection* MemberCollection) {
    signUpUI = new SignUpUI(this);
    this->MemCollPointer = MemberCollection;
    signUpUI->startUI();
}

void SignUp::createMember(string id, string pw, string pnum){
    MemCollPointer->createMember(id, pw, pnum);
}


// LoginUI


void LoginUI::doLogin() {
    string id, pw;
    in_fp >> id >> pw;
cout << "debug doLogin id pw : " << id << pw << endl;
    this->logincontroller->checkMember(id, pw);
}

void LoginUI::startUI() {
    this->doLogin();
}


// Login


Login::Login(MemberCollection* MemberCollection) {
    loginUI = new LoginUI(this);
    this->MemCollPointer = MemberCollection;
    loginUI->startUI();
}

void Login::checkMember(string id, string pw){
    MemCollPointer->checkMember(id, pw);
}


// LogoutUI


void LogoutUI::doLogout() {
   this->logoutcontroller->getLogoutMember();
}

void LogoutUI::startUI() {
    this->doLogout();
}


// Logout


Logout::Logout(MemberCollection* MemberCollection) {
    logoutUI = new LogoutUI(this);
    this->MemCollPointer = MemberCollection;
    logoutUI->startUI();
}

void Logout::getLogoutMember() {
    MemCollPointer->getLogoutMember();
}


// EnrollUI

EnrollUI



