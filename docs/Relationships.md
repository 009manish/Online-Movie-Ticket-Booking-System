# Relationships and UML

| Relationship | Type | Multiplicity | Reason |
|---|---|---|---|
| Cinema → Screen | Composition | 1 → 1..* | Cinema owns its screens |
| Screen → Seat | Composition | 1 → 1..* | Screen owns its physical seats |
| Show → Movie | Aggregation | * → 1 | Show refers to an existing movie |
| Show → Screen | Association | * → 1 | Show is scheduled on one screen |
| Show → ShowSeat | Composition | 1 → 1..* | Show owns its show-specific seat states |
| Booking → Customer | Association | * → 1 | Booking belongs to a customer |
| Booking → ShowSeat | Aggregation | 1 → 1..* | Booking refers to selected show seats |
| Booking → Payment | Association | 1 → 1 | Booking uses a payment object |
| Payment → UpiPayment/CardPayment/CashPayment | Inheritance | — | Concrete payment implementations |
| BookingService → Booking | Association | 1 → * | Service manages bookings |

## Class Diagram

```mermaid
classDiagram
class Movie { -string title; -string language; -int duration }
class Seat { -string seatNumber; -SeatType seatType; -double price }
class Screen { -int screenNumber; -vector~Seat~ seats }
class Cinema { -string name; -vector~Screen~ screens }
class Show { -Movie* movie; -Screen* screen; -string startTime; -vector~ShowSeat~ showSeats }
class ShowSeat { -Seat* seat; -SeatStatus status }
class Customer { -string name; -string phone }
class Booking { -int bookingId; -Customer* customer; -Show* show; -vector~ShowSeat*~ seats; -double bookingAmount; -BookingStatus status }
class Payment { <<abstract>>; #double amount; +pay(double amount) bool }
class UpiPayment
class CardPayment
class CashPayment
class PriceCalculator
class TicketPrinter
class BookingService

Cinema "1" *-- "1..*" Screen
Screen "1" *-- "1..*" Seat
Show "*" o-- "1" Movie
Show "*" --> "1" Screen
Show "1" *-- "1..*" ShowSeat
Booking "*" --> "1" Customer
Booking "1" o-- "1..*" ShowSeat
Booking "1" --> "1" Payment
Payment <|-- UpiPayment
Payment <|-- CardPayment
Payment <|-- CashPayment
BookingService "1" --> "*" Booking
```

## Sequence Diagram

Use case: **customer books 1 seat and pays by UPI**.

```mermaid
sequenceDiagram
actor Customer
participant BookingService
participant Show
participant ShowSeat
participant PriceCalculator
participant Payment
participant Booking
participant TicketPrinter

Customer->>BookingService: bookTicket(customer, show, A1, UPI)
BookingService->>Show: getShowSeats()
Show-->>BookingService: ShowSeat list
BookingService->>ShowSeat: isAvailable()
ShowSeat-->>BookingService: true
BookingService->>PriceCalculator: calculateTotal(selectedSeats)
PriceCalculator-->>BookingService: total
BookingService->>Booking: create Booking(PENDING)
Booking-->>BookingService: booking
BookingService->>Payment: pay(total)
Payment-->>BookingService: success
BookingService->>ShowSeat: bookSeat()
ShowSeat-->>BookingService: true
BookingService->>Booking: confirm()
BookingService->>TicketPrinter: printTicket(booking)
TicketPrinter-->>BookingService: ticket printed
BookingService-->>Customer: confirmed booking
```
