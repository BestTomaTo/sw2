#include <string>
#include "SignUpUI.h"
#include "MemberCollection.h"
using namespace std;

class SignUp {
    private:
        SignUpUI* signUpUI;
        MemberCollection* MemCollPointer;
    public:
        SignUp(MemberCollection* MemberCollection);    
        void createMember(string id, string pw, string pnum);
};