#include "LogoutUI.h"
#include "MemberCollection.h"
using namespace std;

class Logout {
    private:
        LogoutUI* logoutUI;
        MemberCollection* MemCollPointer;
    public:
        Logout(MemberCollection* MemberCollection);
        void getLogoutMember();
};