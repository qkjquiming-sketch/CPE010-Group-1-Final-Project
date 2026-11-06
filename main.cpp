#include <iostream>
#include "doubly_ll.h"

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

   DoubleList<Appointment>* head = nullptr;
   do {
    std::cout<< "\n======== Dental Patient Appointment Scheduling and Customer Service Management System ========\n";
    std::cout<< "[1] Add Appointment\n";
    std::cout<< "[2] View Appointments\n";
    std::cout<< "[3] Customer Information\n";
    std::cout<< "[4] Delete Appointment\n";
    std::cout<< "[5] Exit\n";

    std::cout<< "\nEnter your choice(1-5): "; std::cin>> choice;
    
    switch (choice){
    case 1:
        std::cout << "\nAdding Appointment\n";
        std::cout<< "Enter appointment number: ";
        std::cin>> appointment.number;
        std::cin.ignore();
        std::cout<<"Enter Name: "; std::cin.getline(appointment.name, 50);
        std::cout<<"Enter date(MM/DD/YYYY): "; std::cin.getline(appointment.date, 20);
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
        std::cout << "\nDisplaying Customer Information...\n";
        break;
    case 4:
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
    
    case 5:
        std::cout << "\nExiting the Program...\n";
        break;
    
    default:
        std::cout << "\nInvalid Choice! Please try again.\n";
    }

   } while(choice != 5);
   return 0;
}