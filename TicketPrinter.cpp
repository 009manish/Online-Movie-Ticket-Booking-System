#include <iostream>
#include <iomanip>
using namespace std;

class TicketPrinter {
public:
    void printTicket(const Booking& booking) const {
        cout << "\n================ TICKET ================\n";
        cout << "Booking ID : "<< booking.getBookingId() << "\n";
        cout << "Customer   : "<< booking.getCustomer()->getName() << "\n";
        cout << "Movie      : "<< booking.getShow()->getMovie()->getTitle() << "\n";
        cout << "Screen     : "<< booking.getShow()->getScreen()->getScreenNumber() << "\n";
        cout << "Show Time  : "<< booking.getShow()->getStartTime() << "\n";
        cout << "Seats      : ";
        for (const ShowSeat* ss : booking.getSeats()) {
            cout << ss->getSeat()->getSeatNumber() << " ";
        }
        cout << "\nTotal      : Rs. "<< fixed << setprecision(2)<< booking.getAmount() << "\n";
        cout << "Status     : CONFIRMED\n";
        cout << "========================================\n";
    }
};