#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Show {
private:
    Movie* movie;
    Screen* screen;
    string startTime;

    // COMPOSITION: Show owns ShowSeat objects for this screening.
    vector<ShowSeat> showSeats;

public:
    Show(Movie* movie, Screen* screen, const string& startTime)
        : movie(movie), screen(screen), startTime(startTime) {

        for (Seat& seat : screen->getSeats()) {
            showSeats.emplace_back(&seat);
        }
    }

    void displaySeats() const {
        cout << "\nSeat Layout (A=Available, B=Booked)\n";

        for (const ShowSeat& ss : showSeats) {
            cout << left << setw(6)<< ss.getSeat()->getSeatNumber()<< setw(10)<< (ss.isAvailable() ? "AVAILABLE" : "BOOKED")<< "Type: ";
            switch (ss.getSeat()->getSeatType()) {
                case SeatType::SILVER:
                    cout << "SILVER";
                    break;

                case SeatType::GOLD:
                    cout << "GOLD";
                    break;

                case SeatType::PLATINUM:
                    cout << "PLATINUM";
                    break;
            }
            cout << "\n";
        }
    }
    Movie* getMovie() const {
        return movie;
    }
    Screen* getScreen() const {
        return screen;
    }
    string getStartTime() const {
        return startTime;
    }
    vector<ShowSeat>& getShowSeats() {
        return showSeats;
    }
    const vector<ShowSeat>& getShowSeats() const {
        return showSeats;
    }
};