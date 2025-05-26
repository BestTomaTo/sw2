#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include "allClasses.h"
using namespace std;

extern ifstream in_fp;
extern ofstream out_fp;


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
    out_fp << "> " << id << " " << pw << " " << pnum << endl;
}

void MemberCollection::checkSignUpMember(string id, string pw) {
    if(id == "admin" && pw == "admin") {
        this->admin = 1;
        out_fp << "> " << id << " " << pw << endl;
        return;
    }

    for (int i=0; i<cnt; i++) {
        if (MemArray[i].getID() == id && MemArray[i].getPW() == pw) {
            MemArray[i].doLogin();
            out_fp << "> " << MemArray[i].getID() << " " << MemArray[i].getPW() << endl;        
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
        out_fp << "> " << "admin" << endl;
        return;
    }
    for (int i=0; i<cnt; i++) {
        if (MemArray[i].getlogincheck() == 1) {
            MemArray[i].doLogout();
            out_fp << "> " << MemArray[i].getID() << endl;
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
    out_fp << "> " << bikeid << " " << bikename << endl;
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

Bike* Rental::getBike() const {
    return BikePointer;
}


// RentalCollection


RentalCollection::RentalCollection() {
    RenArray = new Rental[100];
}

void RentalCollection::createRental(Member* member, Bike* bike) {
    if (member == NULL) {
        out_fp << "Error: 로그인된 회원이 없습니다." << endl;
        return;
    }
    if (bike == NULL) {
        out_fp << "Error: 해당 자전거가 없습니다." << endl;
        return;
    }
    RenArray[cnt++] = Rental(member, bike);
    out_fp << "> "<< bike->getBikeID() << " " << bike->getBikeName() << endl;
}

void RentalCollection::getRental(Member* member) {
    if (member == NULL) {
        out_fp << "Error: 로그인된 회원이 없습니다." << endl;
        return;
    }

    vector<Rental> rentals; // 정렬을 위한 벡터

    for (int i = 0; i < cnt; i++) {
        if (RenArray[i].getMember()->getID() == member->getID()) {
            rentals.push_back(RenArray[i]);
        }
    }

    sort(rentals.begin(), rentals.end(), [](const Rental& a, const Rental& b) {
        return a.getBike()->getBikeID() < b.getBike()->getBikeID();
    });

    for (const auto& rental : rentals) {
        out_fp << "> " << rental.getBike()->getBikeID() << " " << rental.getBike()->getBikeName() << endl;
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
    out_fp << "1.1 회원가입" << endl;
    MemCollPointer->createMember(id, pw, pnum);
    out_fp << "" << endl;
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
    out_fp << "2.1 로그인" << endl;
    MemCollPointer->checkSignUpMember(id, pw);
    out_fp << "" << endl;
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
    out_fp << "2.2 로그아웃" << endl;
    MemCollPointer->getLogoutMember();
    out_fp << "" << endl;
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
        out_fp << "admin 외 등록불가" << endl;
        return;
    }
    out_fp << "3.1 자전거 등록" << endl;
    BikeCollPointer->addNewBike(bikeid, bikename);
    out_fp << "" << endl;
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

    out_fp << "4.1 자전거 대여" << endl;
    RentCollPointer->createRental(loginMember, rentBike);
    out_fp << "" << endl;
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
    out_fp << "5.1 자전거 대여 리스트" << endl;
    RentCollPointer->getRental(loginMember);
    out_fp << "" << endl;
}