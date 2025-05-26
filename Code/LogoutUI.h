#include "Logout.h"
using namespace std;

class LogoutUI{
    private:
        Logout* logoutcontroller;
    public:
        LogoutUI(Logout* controller) : logoutcontroller(controller) {}
        void startUI();
        void doLogout();
};