#include <vector>
using namespace std;

class Booking {
private:
    int bookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> seats;
    Payment* payment;                 // Association with Payment
    double bookingAmount;
    BookingStatus status;
    static int nextBookingId;

public:
    Booking(Customer* customer, Show* show, const vector<ShowSeat*>& seats, Payment* payment, double amount)
        : bookingId(nextBookingId++),
        customer(customer),
        show(show),
        seats(seats),
        payment(payment),
        bookingAmount(amount),
        status(BookingStatus::PENDING) {}

    void confirm() { this->status = BookingStatus::CONFIRMED; }
    void fail() { this->status = BookingStatus::FAILED; }
    void cancel() { this->status = BookingStatus::CANCELLED; }

    int getBookingId() const { return bookingId; }
    Customer* getCustomer() const { return customer; }
    Show* getShow() const { return show; }
    const vector<ShowSeat*>& getSeats() const { return seats; }
    Payment* getPayment() const { return payment; }
    double getAmount() const { return bookingAmount; }
    BookingStatus getStatus() const { return status; }

    static int getNextBookingId() { return nextBookingId; }
};

int Booking::nextBookingId = 1001;