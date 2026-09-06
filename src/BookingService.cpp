#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>
using namespace std;

class BookingService {
private:
    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;
    vector<unique_ptr<Booking>> bookings;

    ShowSeat* findSeat(Show& show, const string& seatNumber) const {
        for (ShowSeat& showSeat : show.getShowSeats()) {
            if (showSeat.getSeat()->getSeatNumber() == seatNumber) {
                return &showSeat;
            }
        }
        return nullptr;
    }
    // RUNTIME POLYMORPHISM:
    // Payment pointer calls the selected payment class's pay().
    bool processPayment(Payment* payment, double total) const {
        if (payment == nullptr) {
            return false;
        }
        return payment->pay(total);
    }
public:
    bool bookTicket(Customer* customer,
                    Show& show,
                    const vector<string>& seatNumbers,
                    Payment* payment) {
        // Validate that at least one seat is selected.
        if (seatNumbers.empty()) {
            cout << "No seat selected. Booking cancelled.\n";
            return false;
        }
        vector<ShowSeat*> selectedSeats;
        // Check every requested seat before changing anything.
        for (size_t i = 0; i < seatNumbers.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (seatNumbers[i] == seatNumbers[j]) {
                    cout << "Seat " << seatNumbers[i]<< " selected more than once.\n";
                    cout << "Booking rejected; nothing changed.\n";
                    return false;
                }
            }
            ShowSeat* showSeat =
            findSeat(show, seatNumbers[i]);
            if (showSeat == nullptr) {
                cout << "Invalid seat number: "<< seatNumbers[i] << "\n";
                return false;
            }
            if (!showSeat->isAvailable()) {
                cout << "Seat " << seatNumbers[i]<< " is already BOOKED.\n";
                cout << "Booking rejected; nothing changed.\n";
                return false;
            }
            selectedSeats.push_back(showSeat);
        }
        // Calculate total for all selected seats.
        double total = priceCalculator.calculateTotal(selectedSeats);
        cout << "\nTotal amount: Rs. "<< fixed << setprecision(2)<< total << "\n";
        // Create booking in PENDING state.
        auto booking = make_unique<Booking>(
            customer, &show, selectedSeats, payment, total
        );
        // Process selected payment method.
        bool paid = processPayment(payment, total);
        if (!paid) {
            booking->fail();
            cout << "Payment FAILED.\n";
            cout << "Booking NOT confirmed.\n";
            // Seats were not booked yet, so they remain AVAILABLE.
            bookings.push_back(move(booking));
            return false;
        }
        // Payment successful → now book all seats.
        for (ShowSeat* showSeat : selectedSeats) {
            showSeat->bookSeat();
        }
        booking->confirm();
        // Print ticket only after successful payment.
        ticketPrinter.printTicket(*booking);
        bookings.push_back(move(booking));
        return true;
    }
    Booking* findBooking(int bookingId) const {
        for (const auto& booking : bookings) {
            if (booking->getBookingId() == bookingId) {
                return booking.get();
            }
        }
        return nullptr;
    }
    bool cancelBooking(int bookingId) {
        Booking* booking = findBooking(bookingId);
        if (booking == nullptr) {
            cout << "Booking not found.\n";
            return false;
        }
        if (booking->getStatus() != BookingStatus::CONFIRMED) {
            cout << "Only a CONFIRMED booking can be cancelled.\n";
            return false;
        }
        // Release every seat belonging to the booking.
        for (ShowSeat* showSeat : booking->getSeats()) {
            showSeat->releaseSeat();
        }
        booking->cancel();
        cout << "Booking " << bookingId<< " cancelled successfully.\n";
        cout << "All booked seats are AVAILABLE again.\n";
        return true;
    }
};