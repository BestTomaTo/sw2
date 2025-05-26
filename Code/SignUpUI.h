#include "SignUp.h"
using namespace std;

class SignUpUI {
    private: 
        SignUp* signUpController;
    public:
        SignUpUI(SignUp* controller) : signUpController(controller) {}
        void startUI();
        void insertInfo();
};