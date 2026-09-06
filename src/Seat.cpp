#include <string>
using namespace std;

class Seat {
private:
    string seatNumber;
    SeatType seatType;
    double price;

    double calculatePrice(SeatType type) const {
        if (type == SeatType::SILVER)
            return SILVER_PRICE;

        if (type == SeatType::GOLD)
            return GOLD_PRICE;

        return PLATINUM_PRICE;
    }
    
public:
    // this KEYWORD: distinguishes attributes from constructor parameters.
    Seat(const string& seatNumber, SeatType seatType)
        : seatNumber(seatNumber),
        seatType(seatType),
        price(calculatePrice(seatType)) {}

    string getSeatNumber() const {
        return seatNumber;
    }
    SeatType getSeatType() const {
        return seatType;
    }
    double getPrice() const {
        return price;
    }
};