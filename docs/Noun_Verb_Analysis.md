# Noun–Verb Analysis

## Nouns → Classes

| Noun | Decision |
|---|---|
| Customer | Class |
| Movie | Class |
| Show | Class |
| Seat | Class |
| Screen | Class |
| Cinema | Class |
| Booking | Class |
| ShowSeat | Class |
| Payment | Abstract class |
| UPI/Card/Cash Payment | Payment implementations |
| Price Calculator | Class |
| Ticket Printer | Class |
| Booking Service | Class |

### Rejected as Separate Classes
- **Seat Layout:** representation of ShowSeat objects
- **Price:** value calculated from seat type
- **Booking ID:** Booking attribute
- **Status:** enum/value, not an independent entity
- **Ticket:** output handled by TicketPrinter

## Verbs → Operations

| Verb | Operation |
|---|---|
| List movies | `listMovies()` |
| List shows | `displayShows()` |
| Display seats | `displaySeats()` |
| Check availability | `isAvailable()` |
| Book seat | `bookSeat()` |
| Release seat | `releaseSeat()` |
| Calculate total | `calculateTotal()` |
| Pay | `pay()` |
| Confirm | `confirm()` |
| Fail | `fail()` |
| Cancel | `cancel()` |
| Print ticket | `printTicket()` |
| Find booking | `findBooking()` |
| Book ticket | `bookTicket()` |
| Cancel booking | `cancelBooking()` |
| Read input | `readInteger()` |
