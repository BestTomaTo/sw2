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
        int admin = 0;
        int cnt = 0; 
    public:
        MemberCollection();
        void createMember(string id, string pw, string pnum); 
        void checkSignUpMember(string id, string pw);
        Member* getLoginMember();
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
        Bike* getBike(string bikeid); 
        
};

class Rental{
    private:
        Member* MemPointer;
        Bike* BikePointer;
    public:
        Rental();
        Rental(Member* member, Bike* bike);
        Member* getMember();
        Bike* getBike();
};

class RentalCollection{
    private:
        Rental* RenArray;
        int cnt = 0;
    public:
        RentalCollection();
        void createRental(Member* member, Bike* bike);
        void getRental(Member* member);        
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
        BikeCollection* BikeCollPointer;
    public:
        Enroll(MemberCollection* MemberCollection, BikeCollection* BikeCollection);
        void addNewBike(string bikeid, string bikename);
};

class Rent;
class RentUI;

class RentUI {
    private:
        Rent* rentcontroller;
    public:
        RentUI(Rent* controller) : rentcontroller(controller) {}
        void startUI();
        void rentBike();
};

class Rent{
    private:
        RentUI* rentUI;
        MemberCollection* MemCollPointer;
        BikeCollection* BikeCollPointer;
        RentalCollection* RentCollPointer;
    public: 
        Rent(MemberCollection* MemberCollection, BikeCollection* BikeCollection, RentalCollection* RentalCollection);
        void createRent();
};

class checkBike;
class checkBikeUI;

class checkBikeUI{
    private:
        checkBike* checkrentcontroller;
    public:
        checkBikeUI(checkBike* controller) : checkrentcontroller(controller) {}
        void startUI();
        void checkBikeList();
};

class checkBike{
    private:
        checkBikeUI* checkbikeUI;
        MemberCollection* MemCollPointer;
        RentalCollection* RentCollPointer;
    public:
        checkBike(MemberCollection* MemberCollection, RentalCollection* RentalCollection);
        void showBikeInfo();
};