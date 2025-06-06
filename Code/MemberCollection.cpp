#include <string>
#include "MemberCollection.h"
using namespace std;

MemberCollection::MemberCollection(FileManager* filemanager) {
    MemArray = new Member[100];
    this->filemanager = filemanager;
}

void MemberCollection::createMember(string id, string pw, string pnum){
    ofstream& out_fp = filemanager->getOutputStream();
    
    MemArray[cnt++] = Member(id, pw, pnum);
    out_fp << "> " << id << " " << pw << " " << pnum << endl;
}

void MemberCollection::checkSignUpMember(string id, string pw) {
    ofstream& out_fp = filemanager->getOutputStream();
    
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
    ofstream& out_fp = filemanager->getOutputStream();
    
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