#include <iostream>
#include "doubly_ll.h"
#include "queue.h"

const int max_size = 100;

struct  Appointment{
    int number;
    char name[50];
    char date[50];
    char time[50];
};

int main(){
   int choice;
   Appointment appointment;
   int choice2;
   int where;

   queueArr<Appointment> queue(max_size);

   DoubleList<Appointment>* head = nullptr;
   do {
    std::cout<< "\n======== Dental Patient Appointment Scheduling and Customer Service Management System ========\n";
    std::cout<< "[1] Add Appointment\n";
    std::cout<< "[2] View Appointments\n";
    std::cout<< "[3] Queue Walk-In Customers\n";
    std::cout<< "[4] Customer Information\n";
    std::cout<< "[5] Delete Appointment\n";
    std::cout<< "[6] Exit\n";

    std::cout<< "\nEnter your choice(1-6): "; 
    std::cin>> choice;
    
    switch (choice){
    case 1:
        std::cout << "\nAdding Appointment\n";
        std::cout<< "Enter appointment number: ";
        std::cin>> appointment.number;
        std::cin.ignore();
        std::cout<<"Enter Name: "; std::cin.getline(appointment.name, 50);
        std::cout<<"Enter date (MM/DD/YYYY): "; std::cin.getline(appointment.date, 20);
        std::cout<<"Enter time: "; std::cin.getline(appointment.time, 20);

        std::cout << "[1] Add at the start\n"; 
        std::cout << "[2] Add at the end\n"; 
        std::cout << "Enter your choice: "; 
        std::cin >> where;         
        
    if(where == 1){
        dllInsertHead(appointment, &head); 
        std::cout << "Appointment added at the start.\n"; 
    } 
    else if(where == 2){ 
        dllInsertEnd(appointment, &head); 
        std::cout << "Appointment added at the end.\n"; 
    } 
    else{ 
        std::cout << "Invalid choice.\n"; 
    } 
    break;

    case 2:
        std::cout << "\nViewing Appointments...\n";
        break;
    case 3:
        int queuechoice;
        do{
        std::cout << "\nManage Walk-In Customers\n";
        std::cout << "[1] Queue Customer\n";
        std::cout << "[2] Serve Customer\n";
        std::cout << "[3] View Queue Size\n";
        std::cout << "[4] Go back\n";
        
        std::cout<< "\nEnter your choice(1-6): "; 
        std::cin >> queuechoice;


        switch(queuechoice){
            case 1: {
                std::cout<< "Enter appointment number: ";
                std::cin>> appointment.number;
                std::cin.ignore();
                std::cout<<"Enter Name: "; std::cin.getline(appointment.name, 50);
                std::cout<<"Enter time: "; std::cin.getline(appointment.time, 20);
                
                queue.Enqueue(appointment);
                break;
            }
            case 2:
                std::cout << "\nServing customer front in queue\n\n";
                if (!queue.Empty()) {
                    Appointment appointment = queue.Front();

                    std::cout << "Appointment #" << appointment.number << "\n";
                    std::cout << "Name: " << appointment.name << "\n";
                    std::cout << "Time: " << appointment.time<< "\n";

                    queue.Dequeue();

                } else {
                    std::cout << "No walk-in customers in queue\n\n";
                }
                break;
            case 3:
                std::cout << "\nCurrent Walk-In Queue Size: " << queue.Size() << "\n";
                break;
            case 4:
            break; 

      }

    }while(queuechoice != 4);

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
    
    case 6:
        std::cout << "\nExiting the Program...\n";
        break;
    
    default:
        std::cout << "\nInvalid Choice! Please try again.\n";
    }

   } while(choice != 6);
   return 0;
}
