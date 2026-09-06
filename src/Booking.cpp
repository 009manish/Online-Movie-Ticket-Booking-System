#include <vector>
using namespace std;

class Booking {
private:
    int bookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> seats;
    // ENCAPSULATION: bookingAmount is private.
    double bookingAmount;
    BookingStatus status;
    // STATIC MEMBER: generates unique booking IDs.
    static int nextBookingId;

public:
    Booking(Customer* customer,
            Show* show,
            const vector<ShowSeat*>& seats,
            double amount)
        : bookingId(nextBookingId++),
        customer(customer),
        show(show),
        seats(seats),
        bookingAmount(amount),
        status(BookingStatus::PENDING) {}
    // this KEYWORD: refers to the current Booking object.
    void confirm() {
        this->status = BookingStatus::CONFIRMED;
    }
    void fail() {
        this->status = BookingStatus::FAILED;
    }
    void cancel() {
        this->status = BookingStatus::CANCELLED;
    }
    int getBookingId() const {
        return bookingId;
    }
    Customer* getCustomer() const {
        return customer;
    }
    Show* getShow() const {
        return show;
    }
    const vector<ShowSeat*>& getSeats() const {
        return seats;
    }
    double getAmount() const {
        return bookingAmount;
    }
    BookingStatus getStatus() const {
        return status;
    }
    static int getNextBookingId() {
        return nextBookingId;
    }
};
// First booking ID will be 1001.
int Booking::nextBookingId = 1001;