# Requirement Analysis

## Functional Requirements

### FR1 — Movie Listing
Display all currently playing movies with title, language and duration. If none exist, show an appropriate message.

### FR2 — Show Listing
For a selected movie, display available shows with screen number and start time.

### FR3 — Seat Availability
For a selected show, display seat number, seat type and AVAILABLE/BOOKED status.

### FR4 — Seat Selection and Booking
Allow one or more seats. If any seat is invalid, duplicated or already booked, reject the booking without changing any seat. Confirm only after successful payment.

### FR5 — Pricing
Calculate total using Silver ₹150, Gold ₹250 and Platinum ₹400.

### FR6 — Payment
Support UPI, Card and Cash. If payment fails, do not confirm the booking and keep seats available.

### FR7 — Ticket Printing
After successful payment print booking ID, customer, movie, screen, time, seats, amount and status.

### FR8 — Cancellation
Allow a confirmed booking to be cancelled. Set status to CANCELLED and release its seats.

## Non-Functional Requirements

- **NFR1 Modularity:** separate responsibilities into classes/files.
- **NFR2 Extensibility:** a new payment type such as NetBanking should be addable without modifying existing payment classes or BookingService.
- **NFR3 Input Validation:** invalid menu, movie/show, seat and payment input must be handled clearly without crashing.
- **NFR4 Maintainability:** meaningful names, constants, single-purpose functions and minimal repetition.
