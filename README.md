# CPE010-Group-1-Final-Project

## Appointment and Customer Service System
Dental Patient Appointment Scheduling and Customer Service Management System
CPE 010 – Data Structures and Algorithms | CPE21S4 / Group 1

## Description
A console-based C++ program for a dental clinic receptionist: schedule, view (sorted by date/time), search, and delete appointments; queue and serve walk-ins; keep a log of recent booking changes.

Uses: doubly linked list, selection sort, binary search, array queue, array stack.

## Compile and Run
    g++ -std=c++17 -O2 main.cpp -o system
    ./system        (Windows: system.exe)

## Sample Input
    1 -> 101 -> Maria Santos -> 11/10/2026 -> 10:00   (schedule)
    1 -> 102 -> Juan Cruz -> 11/09/2026 -> 09:00      (schedule)
    2                                                 (view, sorted)
    6 -> 11/10/2026 -> 10:00                          (search)
    3 -> 1 -> 201 -> Pedro Reyes                      (queue walk-in)
    7                                                 (undo log)
    8                                                 (exit)

## Team Members
- Arensol, James Alfred Y.
- Garcia, Dennis James T.
- Larracas, Jerry Matthew L.
- Quiming, Kadaphy James A.
- Pellazar, Stephen Kurt R.
