# OOP and SOLID Mapping

## OOP

| Concept | Demonstration |
|---|---|
| Encapsulation | Private state and controlled methods |
| Abstraction | Abstract `Payment` and pure virtual `pay()` |
| Inheritance | UPI, Card and Cash derive from Payment |
| Runtime Polymorphism | `Payment*` calls `pay(total)` |
| Compile-time Polymorphism | Overloaded constructors/methods where applicable |
| Static Member | `Booking::nextBookingId` |
| `this` keyword | Explicit member assignment in state-changing methods |
| Composition | Cinema→Screen, Screen→Seat, Show→ShowSeat |
| Aggregation | Show→Movie, Booking→ShowSeat |
| Association | Booking with Customer/Show/Payment |

## SOLID

### SRP
Price calculation, ticket printing, payment and booking state are separated.

### OCP
A `NetBankingPayment : Payment` can be added as a new implementation without changing existing payment implementations or BookingService.

### LSP
UPI, Card and Cash payment objects can be used through `Payment*`.

### ISP
The common payment abstraction does not force unrelated operations such as refund handling.

### DIP
BookingService receives a `Payment*` instead of constructing a specific payment class internally.

## Deliberately Not Done
Refund processing is outside the assignment requirements, so no refund operation is added to the common Payment abstraction.
