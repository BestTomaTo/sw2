#include <string>
#include "Member.h"
using namespace std;

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