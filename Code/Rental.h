#include <string>
#include "Member.h"
#include "Bike.h"
using namespace std;

class Rental{
    private:
        Member* MemPointer;
        Bike* BikePointer;
    public:
        Rental();
        Rental(Member* member, Bike* bike);
        Member* getMember();
        Bike* getBike() const;
};