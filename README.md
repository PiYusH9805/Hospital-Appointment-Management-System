# 🏥 Hospital Appointment Management System

**C++ · Object-Oriented Programming · STL Vectors · Console Application**

A menu-driven C++ learning project that manages patient records, doctor records and appointment dates. It demonstrates how classes, constructors and standard-library containers can model a simple appointment workflow.

## Features

- **Patient management:** Add a patient's name, age and gender with an automatically assigned patient ID.
- **Doctor management:** Add doctor details with a separate automatically assigned doctor ID.
- **Appointment scheduling:** Link a registered patient to a registered doctor and store an appointment date.
- **ID validation:** Reject appointment requests when either ID is missing from the records.
- **Record viewing:** List patient names, doctor names and scheduled appointments.
- **In-memory storage:** Store records in `std::vector` containers for the current session.

## How it works

```text
Register patient -> Patient ID
Register doctor  -> Doctor ID
                         |
          Enter both IDs and appointment date
                         |
                Check that both IDs exist
                   /                \
                Valid              Invalid
                  |                   |
          Store appointment      Show error
                  |
          View appointments
```

Patient IDs and doctor IDs each start at **1** and increase independently. IDs restart when the application restarts.

## Technologies and concepts

| Technology / concept | Use |
| --- | --- |
| C++ | Application logic and console input/output |
| Classes and objects | Model patients, doctors and appointments |
| Constructors | Initialize record fields and assign IDs |
| `std::vector` | Store records dynamically in memory |
| `std::string` | Store names, gender and appointment dates |
| Loops and functions | Search records and process menu actions |
| `switch` statement | Dispatch menu choices |

## Project structure

```text
Hospital-Appointment-Management-System/
├── project2.cpp    # Original application source
└── README.md      # Features, setup and usage
```

### Data model

| Class | Stored fields |
| --- | --- |
| `Patient` | Name, gender, age, patient ID |
| `Doctor` | Name, gender, age, doctor ID |
| `Appointment` | Patient ID, doctor ID, date |

The application keeps three collections: `allPatients`, `allDoctors` and `allAppointments`. Patient and doctor lookup use linear searches.

## Build and run

Use **GCC / g++ with C++11 support or newer**. The source uses GCC's `<bits/stdc++.h>` header, so it will not compile unchanged with every C++ compiler.

```bash
git clone https://github.com/PiYusH9805/Hospital-Appointment-Management-System.git
cd Hospital-Appointment-Management-System
g++ -std=c++11 -Wall -Wextra project2.cpp -o hospital
./hospital
```

On Windows with a working MinGW installation:

```powershell
g++ -std=c++11 -Wall -Wextra project2.cpp -o hospital.exe
.\hospital.exe
```

## Menu

```text
1. Add Patient
2. Add Doctor
3. Schedule Appointment
4. View Patient
5. View Doctor
6. View Appointment
0. Exit
```

## Example walkthrough

Use fictional details for practice:

1. Choose **1** and enter patient `Aarav`, age `25`, gender `Male`. The first patient receives ID `1`.
2. Choose **2** and enter doctor `Meera`, age `40`, gender `Female`. The first doctor receives ID `1`.
3. Choose **3**, enter patient ID `1`, doctor ID `1`, and date `15-11-2026`.
4. Choose **6** to view the stored appointment.

Expected appointment line:

```text
Patient ID : 1 has Appointment with Doctor ID 1 on Date 15-11-2026
```

Entering an unknown patient or doctor ID instead shows `Invalid Patient or Doctor ID` and does not add an appointment.

## Current scope and known limitations

This repository preserves the original learning-project source.

- Records are lost on exit; there is no file or database persistence.
- Names and gender are read with `cin >>`, so inputs should be single words.
- The date prompt requests `DD-MM-YYYY`, but format and calendar validity are not checked.
- Appointment time slots, overlapping appointments and duplicate bookings are not validated.
- There is no edit, cancellation, authentication or medical-record functionality.
- Patient/doctor list views currently show names only; assigned IDs are not printed after registration.
- Age and non-numeric input validation are not implemented.
- Choosing **0** exits but also prints `Invalid choice` because there is no dedicated exit case.
- The code has been source-reviewed; a local build attempt was blocked by a Windows MinGW DLL startup error. Successful compilation and runtime behavior have not yet been verified in that environment.

## Suggested next improvements

- Add a dedicated exit case and robust numeric-input handling.
- Display assigned IDs and support full names with spaces.
- Validate real calendar dates and add appointment time slots.
- Add record persistence and appointment cancellation.
- Replace `<bits/stdc++.h>` with standard headers for portability.
- Add unit tests for ID validation and scheduling rules.

## Project origin

Extracted from [Project/project2.cpp](https://github.com/PiYusH9805/cpp-basic-to-advanced/blob/main/Project/project2.cpp) in my C++ practice repository.

**Author:** [Piyush Sharma](https://github.com/PiYusH9805)
