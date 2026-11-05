#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H
#include <iostream>

//Doublelist Node
template <typename T> 
class DoubleList{
  public:
  T data;
  DoubleList<T>* next;
  DoubleList<T>* prev;
};

//creating a node function
template <typename T>
DoubleList<T> *createNode(T newData){
    
    //dynamic memory allocation for a new node
    DoubleList<T>* newNode = new DoubleList<T>;
    
    newNode->data = newData;
    //point it to the next node
    newNode->prev = nullptr;
    newNode->next = nullptr;

    return newNode;
}

template<typename T>
void dllTraversal(DoubleList<T>* currentNode){
  // check if the list is empty
  if(currentNode == nullptr){
    std::cout << "The list is empty";
    return;
  }
 
  
  DoubleList<T>* tail;
  std::cout << "FORWARD\n";
   //forward traverse
  while(currentNode != nullptr){
    std::cout << currentNode->data << " ";
    tail = currentNode;
    currentNode = currentNode -> next;
  }
  //reverse traversal
  std::cout << "\nREVERSE\n";
  while(tail != nullptr){
    std::cout << tail->data << " ";
    tail = tail->prev;
  }
}

//Inserting a node to the head
template<typename T>
void dllInsertHead(T newData, DoubleList<T>** currentNode){
  //Allocate a new node
  DoubleList<T> *newNode = createNode(newData);

  //point the new node to the currentNode (head)
  newNode -> next = *currentNode;

  //point the currentNode to the newNode
  if(*currentNode != nullptr){
    (*currentNode)->prev = newNode;
  }
  *currentNode = newNode;
}

//Inserting at the End
template <typename T>
void dllInsertEnd(T newData, DoubleList<T>** currentNode){
  //create a new node
  DoubleList<T>* newNode = createNode(newData);

  //traverse until we reach the last node
  if(*currentNode == nullptr){
    *currentNode = newNode;
    return;
  }
  DoubleList<T>* current = *currentNode;
  while(current->next != nullptr){
    current = current->next;
  }
  //connect the new node back to the last node
  newNode->prev = current;
  //connect the current node to the new node
  current->next = newNode;

}

// Delete the first node. 
template <typename T> 
void dllDeleteHead(DoubleList<T>** head) { 
  if (*head == nullptr) { 
    std::cout << "The list is empty. Nothing to delete.\\n"; 
    return; 
    } 

    DoubleList<T>* temp = *head; 
    *head = (*head)->next; 

  if (*head != nullptr) { 
    (*head)->prev = nullptr; 
  } 

  delete temp; 
} 

// Delete the last node. 
template <typename T> 
void dllDeleteEnd(DoubleList<T>** head) { 
    if (*head == nullptr) { 
      std::cout << "The list is empty. Nothing to delete.\\n"; 
      return; 
    } 

    DoubleList<T>* current = *head; 

    if(current->next == nullptr) { 
      delete current; 
      *head = nullptr; 
      return; 
    } 

    // Traverse to the last node. 
  while (current->next != nullptr) { 
    current = current->next; 
    } 

  current->prev->next = nullptr; 
  delete current; 
} 

#endif