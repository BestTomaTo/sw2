#include <string>
#include "LoginUI.h"
#include "MemberCollection.h"
using namespace std;

class Login {
    private:
        LoginUI* loginUI;
        MemberCollection* MemCollPointer;
    public:
        Login(MemberCollection* MemberCollection);
        void checkMember(string id, string pw);
};