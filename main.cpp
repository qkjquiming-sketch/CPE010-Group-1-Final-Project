#include <iostream>
#include <cstring>
#include "doubly_ll.h"
#include "queue.h"
#include "selectionSort.h"
#include "binarySearch.h"

const int max_size = 100;

struct Appointment {
    int number;
    char name[50];
    char date[50];
    char time[50];
};

int main(){
    int choice;
    Appointment appointment;
    int where;

    queueArr<Appointment> queue(max_size);
    DoubleList<Appointment>* head = nullptr;
    
    do {
        std::cout << "\n======== Dental Patient Appointment Scheduling and Customer Service Management System ========\n";
        std::cout << "[1] Schedule an Appointment\n";
        std::cout << "[2] View Appointments\n";
        std::cout << "[3] Queue Walk-In Customers and Serve Section\n";
        std::cout << "[4] Customer Information\n";
        std::cout << "[5] Delete Appointment\n";
        std::cout << "[6] Exit\n";

        std::cout << "\nEnter your choice (1-6): "; 
        std::cin >> choice;
    
        switch (choice){
        case 1:
            std::cout << "\nSchedule an Appointment\n";
            std::cout << "Enter appointment number: ";
            std::cin >> appointment.number;
            std::cin.ignore();
            std::cout << "Enter Name: "; std::cin.getline(appointment.name, 50);
            std::cout << "Enter date (MM/DD/YYYY): "; std::cin.getline(appointment.date, 20);
            std::cout << "Enter time: "; std::cin.getline(appointment.time, 20);

            // Automatically inserts at the end
            dllInsertEnd(appointment, &head); 
            std::cout << "Appointment successfully added!\n"; 
            break;

        case 2: {
            std::cout << "\nViewing Appointments...\n";

            std::cout << "\nScheduled Appointments:\n";
            dllDisplay(head);
            
            std::cout << "\nWalk-In Appointments:\n";
            queue.Display(); 
            
            break;
        }
        case 3:
            int queuechoice;
            do {
                std::cout << "\nManage Walk-In Customers\n";
                std::cout << "[1] Queue Customer\n";
                std::cout << "[2] Serve Customer\n";
                std::cout << "[3] View Queue Size\n";
                std::cout << "[4] Go back\n";
                
                std::cout << "\nEnter your choice (1-4): "; 
                std::cin >> queuechoice;

                switch(queuechoice){
                    case 1: {
                        std::cout << "Enter appointment number: ";
                        std::cin >> appointment.number;
                        std::cin.ignore();
                        std::cout << "Enter Name: "; std::cin.getline(appointment.name, 50);
                        std::cout << "Enter time: "; std::cin.getline(appointment.time, 20);
                        
                        queue.Enqueue(appointment);
                        std::cout << "Walk-in customer queued successfully!\n";
                        break;
                    }
                    case 2: {
                        std::cout << "\nServing customer...\n\n";
                        bool servedFromDLL = false;
                        DoubleList<Appointment>* targetNode = nullptr;

                        //checks if there is walk in or scheduled appointment
                        if (head != nullptr && !queue.Empty()) {
                            Appointment walk_in_cus = queue.Front();
                            
                            DoubleList<Appointment>* currentNode = head;
                            while (currentNode != nullptr) {
                                //compare dates with the walk-in customer
                                int dateCompare = std::strcmp(currentNode->data.date, walk_in_cus.date);
                                //if same date
                                if (dateCompare == 0) {
                                    //if the scheduled time is earlier than the walk-in customer time
                                    if (std::strcmp(currentNode->data.time, walk_in_cus.time) < 0) {
                                        targetNode = currentNode;
                                        servedFromDLL = true;
                                        break;
                                    }
                                }
                                currentNode = currentNode->next;
                            }
                        }

                        //serves the scheduled appointment if has same date with walk in and has an earlier time
                        if (servedFromDLL && targetNode != nullptr) {
                            std::cout << "Serving scheduled appointment...\n";
                            std::cout << "Appointment #" << targetNode->data.number << "\n";
                            std::cout << "Name: " << targetNode->data.name << "\n";
                            std::cout << "Date: " << targetNode->data.date << "\n";
                            std::cout << "Time: " << targetNode->data.time << "\n\n";

                            if (targetNode == head) {
                                dllDeleteHead(&head);
                            } else {
                                targetNode->prev->next = targetNode->next;
                                if (targetNode->next != nullptr) {
                                    targetNode->next->prev = targetNode->prev;
                                }
                                delete targetNode;
                            }
                        } 
                        //else, serve the standard walk-in from the queue
                        else if (!queue.Empty()) {
                            std::cout << "Serving customer...\n";
                            Appointment appt = queue.Front();
                            std::cout << "Appointment #" << appt.number << "\n";
                            std::cout << "Name: " << appt.name << "\n";
                            std::cout << "Time: " << appt.time << "\n\n";
                            queue.Dequeue();
                        } 
                        else {
                            std::cout << "No customers to serve.\n\n";
                        }
                        break;
                    }
                    case 3:
                        std::cout << "\nCurrent Walk-In Queue Size: " << queue.Size() << "\n";
                        break;
                    case 4:
                        break; 
                }
            } while(queuechoice != 4);
            break;

        case 4:
            std::cout << "\nDisplaying Customer Information...\n";
            break;

        case 5:
            std::cout << "\nDeleting Appointments\n";
            std::cout << "[1] Delete the first appointment\n"; 
            std::cout << "[2] Delete the last appointment\n"; 
            std::cout << "Enter your choice: "; 
            std::cin >> where; 
        
            if(where == 1){ 
                dllDeleteHead(&head); 
            } 
            else if(where == 2){ 
                dllDeleteEnd(&head); 
            } 
            else{ 
                std::cout << "Invalid choice.\n"; 
            } 
            break;
        case 6: {
            char searchDate[50];
            char searchTime[50];

            std::cout << "\nSearch Appointment\n";
            std::cin.ignore();
            std::cout << "Enter date (MM/DD/YYYY): "; std::cin.getline(searchDate, 50);
            std::cout << "Enter time: "; std::cin.getline(searchTime, 50);

            dllSearch(head, searchDate, searchTime);
            break;
        }

        
        case 7:
            std::cout << "\nExiting the Program...\n";
            break;
        
        default:
            std::cout << "\nInvalid Choice! Please try again.\n";
        }

    } while(choice != 7);
    return 0;
}
