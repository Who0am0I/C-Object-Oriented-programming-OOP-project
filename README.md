# Clinic Appointment Booking System

This is a simple command-line based clinic appointment booking system implemented in C++. It allows doctors to manage their schedules and patients to book appointments.

## Features

- **Doctor Management:**
  - Register new doctors with their specialty, consultation fee, and available slots.
  - View a doctor's schedule of booked appointments.

- **Patient Management:**
  - Book appointments with available doctors.
  - Provide basic medical information by answering specialty-specific questions.
  - View and cancel booked appointments.

- **Appointment System:**
  - Pre-populated with default doctors and sample appointments for demonstration.
  - Manages the booking, scheduling, and cancellation of appointments.

## How to Compile and Run

This project can be compiled with a standard C++ compiler like g++.

### Prerequisites

- A C++ compiler (like g++)
- Make (optional, but recommended for easier compilation)

### Compilation

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/your-username/your-repository-name.git
    cd your-repository-name
    ```

2.  **Compile the source code:**
    You can compile the `main.cpp` file using g++:
    ```bash
    g++ -o clinic_booking main.cpp src/*.cpp -Iinclude
    ```
    This command compiles all `.cpp` files in the `src` directory along with `main.cpp`, and includes the header files from the `include` directory.

3.  **Run the executable:**
    ```bash
    ./clinic_booking
    ```

## Project Structure

-   `main.cpp`: The main entry point of the application, containing the user interface and logic.
-   `include/`: Contains the header files for the classes (`Person.h`, `Doctor.h`, `Patient.h`, `Appointment.h`).
-   `src/`: Contains the implementation files for the classes (`Person.cpp`, `Doctor.cpp`, `Patient.cpp`, `Appointment.cpp`).
-   `finalProject2.cbp`: Code::Blocks project file.
-   `finalProject2.layout`: Code::Blocks layout file. 