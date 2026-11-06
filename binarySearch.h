#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include <iostream>
#include <cstring>

template <typename T>
class DoubleList;


template<typename T>
DoubleList<T>* binarySearch(DoubleList<T>* head, const char* date, const char* time) {
    if (head == nullptr) {
        return nullptr;
    }

    DoubleList<T>* start = head;
    DoubleList<T>* end = nullptr;

    while(start != end) {

        DoubleList<T>* slow = start;
        DoubleList<T>* fast = start->next;

        while(fast != end) {
            fast = fast->next;
            if(fast != end) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        DoubleList<T>* mid = slow;

        // Compare Dates
        int compareDate = std::strcmp(date, mid->data.date);

        if(compareDate == 0) {
            // If dates are equal, compare time
            int compareTime = std::strcmp(time, mid->data.time);

            if(compareTime == 0) {
                // Appointment found
                return mid;
            }

            // Search the right half
            else if (compareTime > 0) {
                start = mid->next;
            }

            // Search the left half
            else {end = mid;}
        }

        // Search the right half
        else if (compareDate > 0) {
            start = mid->next;
        }
        
        // Search the left half
        else {end = mid;}

    } 
    return nullptr;
}

// Searches for the appointment then display it
template<typename T>
void dllSearch(DoubleList<T>* head, const char* date, const char* time) {
    if(head == nullptr){
        std::cout << "No scheduled appointment(s).\n";
        return;
    }

    selectionSort(head);

    DoubleList<T>* result = binarySearch(head, date, time);

    if(result == nullptr) {
        std::cout << "No scheduled appointment(s).\n";
        return;
    }

    std::cout << "Appointment found!\n" << "Appontment #" << result->data.number << std::endl;

    std::cout << "Name: " << result->data.name << std::endl << "\n";
    std::cout << "Date: " << result->data.date << std::endl << "\n";
    std::cout << "Time: " << result->data.time << std::endl << "\n";
}

#endif
