#include "Login.h"
using namespace std;

class LoginUI {
    private:
        Login* logincontroller;
    public:
        LoginUI(Login* controller) : logincontroller(controller) {}
        void startUI();
        void doLogin();
};