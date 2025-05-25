#include <iostream>
#include <string>
using namespace std;

class SignUp;
class SignUpUI;

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

class MemberCollection {
    private:
        Member* MemArray;
        int cnt = 0; 
    public:
        MemberCollection();
        void createMember(string id, string pw, string pnum); 
        void checkMember(string id, string pw);
        void getLogoutMember();
};

class Bike {
    private:
        string bikeid, bikename;
    public:
        Bike();
        Bike(string bikeid, string bikename);
        string getBikeID();
        string getBikeName();
};

class BikeCollection {
    private:
        Bike* BikeArray;
        int cnt = 0; 
    public:
        BikeCollection();
        void addNewBike(string bikeid, string bikename); 
        void getBike();
};

class SignUpUI {
    private: 
        SignUp* signUpController;
    public:
        SignUpUI(SignUp* controller) : signUpController(controller) {}
        void startUI();
        void insertInfo();
};

class SignUp {
    private:
        SignUpUI* signUpUI;
        MemberCollection* MemCollPointer;
    public:
        SignUp(MemberCollection* MemberCollection);    
        void createMember(string id, string pw, string pnum);
};

class LoginUI;
class Login;

class LoginUI {
    private:
        Login* logincontroller;
    public:
        LoginUI(Login* controller) : logincontroller(controller) {}
        void startUI();
        void doLogin();
};

class Login {
    private:
        LoginUI* loginUI;
        MemberCollection* MemCollPointer;
    public:
        Login(MemberCollection* MemberCollection);
        void checkMember(string id, string pw);
};

class Logout;
class LogoutUI;

class LogoutUI{
    private:
        Logout* logoutcontroller;
    public:
        LogoutUI(Logout* controller) : logoutcontroller(controller) {}
        void startUI();
        void doLogout();
};

class Logout {
    private:
        LogoutUI* logoutUI;
        MemberCollection* MemCollPointer;
    public:
        Logout(MemberCollection* MemberCollection);
        void getLogoutMember();
};

class Enroll;
class EnrollUI;

class EnrollUI {
    private:
        Enroll* enrollcontroller;
    public:
        EnrollUI(Enroll* controller) : enrollcontroller(controller) {}
        void startUI();
        void insertBikeInfo();
};

class Enroll {
    private:
        EnrollUI* enrollUI;
        MemberCollection* MemCollPointer;
    public:
        Enroll(MemberCollection* MemberCollection);
        void addNewBike();
};
