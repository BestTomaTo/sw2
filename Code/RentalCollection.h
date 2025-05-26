#include <string>
#include "Rental.h"
using namespace std;

class RentalCollection{
    private:
        Rental* RenArray;
        int cnt = 0;
    public:
        RentalCollection();
        void createRental(Member* member, Bike* bike);
        void getRental(Member* member);        
};