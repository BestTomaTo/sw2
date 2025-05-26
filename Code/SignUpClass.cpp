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
    cout << "> " << id << " " << pw << " " << pnum << endl;
}

void MemberCollection::checkSignUpMember(string id, string pw) {
    if(id == "admin" && pw == "admin") {
        this->admin = 1;
        cout << "> " << id << " " << pw << endl;
        return;
    }

    for (int i=0; i<cnt; i++) {
        if (MemArray[i].getID() == id && MemArray[i].getPW() == pw) {
            MemArray[i].doLogin();
            cout << "> " << MemArray[i].getID() << " " << MemArray[i].getPW() << endl;        
        }
    }    
}

Member* MemberCollection::getLoginMember() {
    for (int i=0; i<cnt; i++) {
        if (this->admin == 1) break;
        if (MemArray[i].getlogincheck() == 1) {
            return &MemArray[i];
        }
    }
    return NULL;
}

void MemberCollection::getLogoutMember() {
    if (this->admin == 1) {
        this->admin = 0;
        return;
    }
    for (int i=0; i<cnt; i++) {
        if (MemArray[i].getlogincheck() == 1) {
            MemArray[i].doLogout();
            cout << "> " << MemArray[i].getID() << endl;
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
    BikeArray = new Bike[100];
}

void BikeCollection::addNewBike(string bikeid, string bikename){
    BikeArray[cnt++] = Bike(bikeid, bikename);
    cout << "> " << bikeid << " " << bikename << endl;
}

Bike* BikeCollection::getBike(string bikeid) {
    for (int i=0; i<cnt; i++) {
        if (BikeArray[i].getBikeID() == bikeid) {        
            return &BikeArray[i];
        }
    }
    return NULL;
}


// Rental


Rental::Rental() {}

Rental::Rental(Member* member, Bike* bike) {
    MemPointer = member;
    BikePointer = bike;
}

Member* Rental::getMember() {
    return MemPointer;
}

Bike* Rental::getBike() {
    return BikePointer;
}


// RentalCollection


RentalCollection::RentalCollection() {
    RenArray = new Rental[100];
}

void RentalCollection::createRental(Member* member, Bike* bike) {
    if (member == NULL) {
        cout << "Error: 로그인된 회원이 없습니다." << endl;
        return;
    }
    if (bike == NULL) {
        cout << "Error: 해당 자전거가 없습니다." << endl;
        return;
    }
    RenArray[cnt++] = Rental(member, bike);
    cout << "> "<< bike->getBikeID() << " " << bike->getBikeName() << endl;
}

void RentalCollection::getRental(Member* member) {
    for(int i=0; i<cnt; i++){
        if(RenArray[i].getMember()->getID() == member->getID()) {
            cout << "> " << RenArray[i].getBike()->getBikeID() << " " << RenArray[i].getBike()->getBikeName() << endl;
        }
    }
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
    MemCollPointer->checkSignUpMember(id, pw);
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

void EnrollUI::startUI() {
    this->insertBikeInfo();
}

void EnrollUI::insertBikeInfo() {
    string bikeid, bikename;
    in_fp >> bikeid >> bikename;
    enrollcontroller->addNewBike(bikeid, bikename);
}


// Enroll


Enroll::Enroll(MemberCollection* MemberCollection, BikeCollection* BikeCollection) {
    enrollUI = new EnrollUI(this);
    this->MemCollPointer = MemberCollection;
    this->BikeCollPointer = BikeCollection;
    enrollUI->startUI();
}

void Enroll::addNewBike(string bikeid, string bikename) {
    if (MemCollPointer->getLoginMember() != NULL) {
        cout << "admin 외 등록불가" << endl;
        return;
    }
    BikeCollPointer->addNewBike(bikeid, bikename);
}


// RentUI


void RentUI::startUI() {
    this->rentBike();
}

void RentUI::rentBike() {
    rentcontroller->createRent();
}


// Rent


Rent::Rent(MemberCollection* MemberCollection, BikeCollection* BikeCollection, RentalCollection* RentalCollection) {
    rentUI = new RentUI(this);
    MemCollPointer = MemberCollection;
    BikeCollPointer = BikeCollection;
    RentCollPointer = RentalCollection;
    rentUI->startUI();
}

void Rent::createRent() {
    string bikeid;
    in_fp >> bikeid;
    Member* loginMember = MemCollPointer->getLoginMember();
    Bike* rentBike = BikeCollPointer->getBike(bikeid);

    RentCollPointer->createRental(loginMember, rentBike);
}


// checkBikeUI


void checkBikeUI::startUI() {
    this->checkBikeList();
}

void checkBikeUI::checkBikeList() {
    checkrentcontroller->showBikeInfo();
}


// checkBike


checkBike::checkBike(MemberCollection* MemberCollection, RentalCollection* RentalCollection) {
    checkbikeUI = new checkBikeUI(this);
    MemCollPointer = MemberCollection;
    RentCollPointer = RentalCollection;
    checkbikeUI->startUI();
}

void checkBike::showBikeInfo() {
    Member* loginMember = MemCollPointer->getLoginMember();
    RentCollPointer->getRental(loginMember);
}