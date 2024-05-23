# Bus Transportation Project

## Project Overview

This Bus Transportation project is a C++ application designed to manage bus reservations efficiently. The application offers functionalities such as reservation, ticket viewing, cancellation, and displaying the history of transactions for the current day. The system stores data for up to 10 days, after which the user can back up the data and clear the storage file to maintain optimal performance.

## Features

- **Reservation**: Allows users to book seats on a bus, storing their information securely.
- **View Ticket**: Enables users to retrieve and review their ticket details.
- **Cancel Reservation**: Provides a way for users to cancel their bookings.
- **Show Today's History**: Displays all transactions and reservations made on the current day.
- **Data Management**: Stores data for up to 10 days and includes functionality for restoring and clearing the data file.

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/bus-transportation.git
   ```

2. **Navigate to the project directory:**
   ```bash
   cd bus-transportation
   ```

3. **Compile the project:**
   ```bash
   g++ main.cpp -o bus_transportation
   ```

4. **Run the executable:**
   ```bash
   ./bus_transportation
   ```

## Usage

Upon running the application, you will be presented with a menu that includes the following options:

1. **Make a Reservation**: Follow the prompts to enter passenger details and reserve a seat.
2. **View Ticket**: Enter the ticket number to view the details of an existing reservation.
3. **Cancel Reservation**: Enter the ticket number to cancel a reservation.
4. **Show Today's History**: Display all reservations and transactions made on the current day.
5. **Restore Data and Clean Data File**: Use this option after 10 days to back up the existing data and clear the `data.txt` file.

## File Structure

- **main.cpp**: The main source file containing the core logic of the application.
- **data.txt**: The file where reservation data is stored.
- **README.md**: This README file.

## Data Management

The application stores reservation data in `data.txt` for up to 10 days. After this period, users should use the provided option to restore the data and clear the file to ensure the system continues to operate efficiently.

## Contributing

If you would like to contribute to this project, please fork the repository and submit a pull request. For major changes, please open an issue first to discuss what you would like to change.


---

This project aims to provide a simple yet effective bus transportation management system using C++. For any questions or support, please contact [your email].
