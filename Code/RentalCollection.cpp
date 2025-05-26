#include <string>
#include "RentalCollection.h"
#include <vector>
#include <algorithm>
using namespace std;

RentalCollection::RentalCollection() {
    RenArray = new Rental[100];
}

void RentalCollection::createRental(Member* member, Bike* bike) {
    if (member == NULL) {
        out_fp << "Error: 로그인된 회원이 없습니다." << endl;
        return;
    }
    if (bike == NULL) {
        out_fp << "Error: 해당 자전거가 없습니다." << endl;
        return;
    }
    RenArray[cnt++] = Rental(member, bike);
    out_fp << "> "<< bike->getBikeID() << " " << bike->getBikeName() << endl;
}

void RentalCollection::getRental(Member* member) {
    if (member == NULL) {
        out_fp << "Error: 로그인된 회원이 없습니다." << endl;
        return;
    }

    vector<Rental> rentals; // 정렬을 위한 벡터

    for (int i = 0; i < cnt; i++) {
        if (RenArray[i].getMember()->getID() == member->getID()) {
            rentals.push_back(RenArray[i]);
        }
    }

    sort(rentals.begin(), rentals.end(), [](const Rental& a, const Rental& b) {
        return a.getBike()->getBikeID() < b.getBike()->getBikeID();
    });

    for (const auto& rental : rentals) {
        out_fp << "> " << rental.getBike()->getBikeID() << " " << rental.getBike()->getBikeName() << endl;
    }
}