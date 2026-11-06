#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include <iostream>
#include <cstring>

template <typename T> 
class DoubleList;

template<typename T>
void selectionSort(DoubleList<T>* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    //traverse outer loop
    for (DoubleList<T>* i = head; i != nullptr; i = i->next) {
        DoubleList<T>* minNode = i;
        //inner loop will check every node to find smallest value
        for (DoubleList<T>* j = i->next; j != nullptr; j = j->next) {
            
            //will compare dates
            int dateCompare = std::strcmp(j->data.date, minNode->data.date);
            
            if (dateCompare < 0) {
                minNode = j;
            } 
            else if (dateCompare == 0) {
                //if dates are equal, times will be compared
                if (std::strcmp(j->data.time, minNode->data.time) < 0) {
                    minNode = j;
                }
            }
        }

        if (minNode != i) {
            T temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
        }
    }
}

#endif