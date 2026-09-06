# Online Movie Ticket Booking System

A small menu-driven C++ console application for booking movie tickets in a single cinema.

## Features
- List movies with title, language and duration
- List shows with screen and time
- Display seat number, type and AVAILABLE/BOOKED status
- Book one or more seats
- Reject invalid, duplicate and already-booked seats without changing seat state
- Silver ₹150, Gold ₹250, Platinum ₹400 pricing
- UPI, Card and Cash payment
- Failed payment does not confirm a booking
- Print ticket after successful payment
- Cancel confirmed bookings and release seats
- Input validation

## Project Structure
```text
Online-Movie-Ticket-Booking-System/
├── README.md
├── .gitignore
├── src/
│   ├── Booking.cpp
│   ├── BookingService.cpp
│   ├── CardPayment.cpp
│   ├── CashPayment.cpp
│   ├── Cinema.cpp
│   ├── Customer.cpp
│   ├── Movie.cpp
│   ├── Payment.cpp
│   ├── PriceCalculator.cpp
│   ├── Screen.cpp
│   ├── Seat.cpp
│   ├── Show.cpp
│   ├── ShowSeat.cpp
│   ├── TicketPrinter.cpp
│   ├── Types.cpp
│   ├── UpiPayment.cpp
│   └── main.cpp
├── docs/
└── demo/
```

## Main Classes
| Class | Responsibility |
|---|---|
| Movie | Movie information |
| Seat | Physical seat, type and price |
| Screen | Owns seats |
| Cinema | Owns screens |
| Show | Movie on a screen at a time; owns show seats |
| ShowSeat | Seat status for a show |
| Customer | Customer details |
| Booking | Booking state and selected seats |
| Payment | Abstract payment contract |
| UpiPayment / CardPayment / CashPayment | Concrete payment implementations |
| PriceCalculator | Total price calculation |
| TicketPrinter | Ticket output |
| BookingService | Booking/cancellation orchestration |

## OOP Concepts
- **Encapsulation:** private state with controlled methods
- **Abstraction:** abstract `Payment` with `virtual bool pay(double amount) = 0`
- **Inheritance:** UPI, Card and Cash inherit `Payment`
- **Runtime polymorphism:** `Payment*` with `payment->pay(total)`
- **Compile-time polymorphism:** overloaded constructors/methods where applicable
- **Static member:** `Booking::nextBookingId`
- **Composition:** Cinema→Screen, Screen→Seat, Show→ShowSeat
- **Aggregation:** Show→Movie, Booking→ShowSeat
- **Association:** Booking→Customer/Show/Payment

## SOLID Mapping
- **SRP:** price calculation, ticket printing, payment and booking state are separated
- **OCP:** new payment types can be added as new `Payment` implementations
- **LSP:** concrete payment classes work through `Payment*`
- **ISP:** no unnecessary refund operation is forced on every payment class
- **DIP:** `BookingService` receives a `Payment*` instead of creating a concrete payment internally

## Compile and Run
```powershell
cd src
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o movie_booking.exe
.\movie_booking.exe
```

The project uses one class per `.cpp` file and no separate header files, following the assignment constraints.

## Important Booking Rules
1. One or more seats may be selected.
2. Invalid, duplicate or already-booked seats reject the complete booking.
3. Seats become BOOKED only after successful payment.
4. Failed payment does not confirm the booking.
5. Cancellation makes the booking CANCELLED and releases its seats.
6. Tickets are printed only after successful payment.

## Deliberate Non-Feature
Refund processing is not implemented because it is outside the assignment scope and would unnecessarily enlarge the common `Payment` abstraction.
