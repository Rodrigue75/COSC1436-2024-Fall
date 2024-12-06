#include <iostream>
#include <cctype>
using namespace std;


// Node Structure for Linked list
struct Node {
    int Value = 0;
    Node* Next = nullptr;

};

// Linked list structure
struct LinkedList {
    Node* Head = nullptr;

};

// Function Prototypes
void displayProgramInfo();
void displayMenu();
char getUserChoice();
void addValue(LinkedList& List);
void listValues(const LinkedList& list);
void deleteValue(LinkedList& list);
void clearList(LinkedList& list);
bool confirmAction(const string& message);

// Main function
int main() {
    displayProgramInfo();

    LinkedList list;
    char choice;

    do {
        displayMenu();
        choice = getUserChoice();

        switch (choice) {
            case 'A': addValue(list); break;
            case 'L': listValues(list); break;
            case 'D': deleteValue(list); break;
            case 'C': clearList(list); break;
            case 'Q': cout << "Exiting program. Goodbye!" << endl; break;
            default: cout << "Invalid option. Try again" << endl;


        }
    } while (choice != 'Q');


    // Clean before exiting
    clearList(list);
    return 0;

}

// Function to display program infos
void displayProgramInfo() {
    cout << "Lab 5: Linked list Implementation" << endl;
    cout << "Author: Rodrigue Edmond" << endl;
    cout << "Course: COSC 1436" << endl;
    cout << "Semester: Fall 2024" << endl << endl;

}

// Function to display the main menu
void displayMenu() {
    cout << "\nMain Menu" << endl;
    cout << "-------------------" << endl;
    cout << "L) ist" << endl;
    cout << "A) dd" << endl;
    cout << "D) elete" << endl;
    cout << "C) lear" << endl;
    cout << "Q) uit" << endl;
    cout << "? ";

}

// Function to add a value to the linked list
void addValue(LinkedList& list) {
    int value;
    cout << "Enter the integer value to add: ";
    cin >> value;

    Node* newNode = new Node();
    newNode->Value = value;

    if (list.Head == nullptr) {
        list.Head = newNode;
    } else {
        Node* current = list.Head;
        while (current->Next != nullptr) {
            current = current->Next;

        }
    }

    cout << "Value" << value << " added to the list. " << endl;

}

// Function to list all values in the linked list
void listValues(const LinkedList& list) {
    if (list.Head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    cout << "Values in the list:" << endl;
    Node* current = list.Head;
    while (current != nullptr) {
        cout << current->Value << endl;
        current = current->Next;
    }

}

// Function to delete a value from the linked list
void deleteValue(LinkedList& list) {
    if (list.Head == nullptr) {
        cout << "The list is empty. Nothing to delete. " << endl;
        return;

    }

    int value;
    cout << "Enter the integer value to remove: ";
    cin >> value;

    Node* current = list.Head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->Value == value) {
            if (previous == nullptr) {
                list.Head = current->Next;
            } else {
                previous->Next = current->Next;

            }
            delete current;
            cout << "Value" << value << " removed from the list. " << endl;
            return;

        }
        previous = current;
        current = current->Next;
    }

    cout << "Value " << value << "not found in the list. " << endl;

}

// Function to clear the entire linked list
void clearlist(LinkedList& list) {
    if (!confirmAction("Are you sure you want to clear the list? (y/n): ")) {
        return;

    }

    Node* current = list.Head;
    while (current != nullptr) {
        Node* next = current->Next;
        delete current;
        current = next;
    }
    list.Head = nullptr;

    cout << "The list has been cleared." << endl;

}

// Function to confirm an action 
bool confirmAction(const string& message) {
    char response;
    cout << message;
    cin >> response;
    return tolower(response) == 'y';

}