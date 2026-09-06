#include <vector>
using namespace std;

class Screen {
private:
    int screenNumber;
    // COMPOSITION: Screen owns its physical Seat objects.
    vector<Seat> seats;
public:
    explicit Screen(int screenNumber)
        : screenNumber(screenNumber) {}

    int getScreenNumber() const {
        return screenNumber;
    }
    void addSeat(const Seat& seat) {
        seats.push_back(seat);
    }
    vector<Seat>& getSeats() {
        return seats;
    }
    const vector<Seat>& getSeats() const {
        return seats;
    }
};