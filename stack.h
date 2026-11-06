#include <iostream>
#include <string>

// Maximum capacity for the array-based stack
const int MAX_CAPACITY = 100;

class BookingUndoStack {
private:
    std::string arr[MAX_CAPACITY];
    int topIndex;

public:
    // Constructor initializes an empty stack
    BookingUndoStack() {
        topIndex = -1;
    }

    // Check if the stack is empty
    bool IsEmpty() const {
        return (topIndex == -1);
    }

    // Check if the stack has reached maximum capacity
    bool IsFull() const {
        return (topIndex == MAX_CAPACITY - 1);
    }

    // Push: Add a new booking change to the history stack
    void Push(const std::string& changeDescription) {
        if (IsFull()) {
            std::cout << "Error: Booking history stack overflow!\n";
            return;
        }
        arr[++topIndex] = changeDescription;
        std::cout << "[Action Recorded]: " << changeDescription << "\n";
    }

    // Pop: Remove the most recent booking change to undo it
    void Pop() {
        if (IsEmpty()) {
            std::cout << "Error: No booking changes to undo (Stack Underflow)!\n";
            return;
        }
        std::cout << "[Undoing Change]: " << arr[topIndex] << "\n";
        topIndex--;
    }

    // Top: View the most recent booking change without removing it
    std::string Top() const {
        if (IsEmpty()) {
            return "No recent changes found.";
        }
        return arr[topIndex];
    }
};