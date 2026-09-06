# Class Details

| Class | Main Attributes | Main Methods | Responsibility |
|---|---|---|---|
| Movie | title, language, duration | getters | Stores movie information |
| Seat | seatNumber, seatType, price | getters, price calculation | Physical seat |
| Screen | screenNumber, seats | addSeat, getters | Owns seats |
| Cinema | name, screens | addScreen, listMovies, getters | Owns screens |
| Show | movie, screen, startTime, showSeats | displaySeats, getters | Screening and show-specific seats |
| ShowSeat | seat, status | isAvailable, bookSeat, releaseSeat | Per-show seat state |
| Customer | name, phone | getters | Customer data |
| Booking | bookingId, customer, show, seats, amount, status | confirm, fail, cancel, getters | Booking state |
| Payment | amount | pure virtual pay | Payment abstraction |
| UpiPayment | upiId | pay | UPI payment |
| CardPayment | cardNumber | pay | Card payment |
| CashPayment | — | pay | Cash payment |
| PriceCalculator | — | calculateTotal | Calculates total |
| TicketPrinter | — | printTicket | Prints ticket |
| BookingService | calculator, printer, bookings | bookTicket, findBooking, cancelBooking | Coordinates workflow |

## Must-Not-Do Responsibilities

- `Booking` must not print its own ticket or implement payment.
- `PriceCalculator` must not book seats.
- `TicketPrinter` must not change booking status.
- `Payment` implementations must not manage cinema seats.
- `ShowSeat` must not calculate the whole booking total.
