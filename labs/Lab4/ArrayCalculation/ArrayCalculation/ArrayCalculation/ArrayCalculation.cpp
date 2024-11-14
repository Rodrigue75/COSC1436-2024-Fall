#include <iostream>
#include <iomanip>

using namespace std;

// Function Declarations
void displayProgramInfo();
int getrUserNumbers(int array[], int maxSize);
void displayMenu();
int getLargestValue(const int array[], int size);
int getSmallestValue(const int array[]; int size);
int getSum(const int array[], int size);
double getMean(const int array[], int size);
void displayValues(const int array[], int size);
int addMoreValues(int arr[], int &size);

// Function to display program information

void displayProgramInfos() {
    cout << "Program Title: ArrayCalculation\n";
    cout << "Name: Rodrigue Tonda \n";
    cout << "Course:COSC 1436 - Fall 2024\n";
    cout << "Lab4\n" << std::endl;
}


// Function to get user numbers and store them in an array

int getUserNumbers(int array[], int max_size) {
    int index = 0; // position to store the next number
    int input;
   
    while (index < max_size) {
        cout << "Enter an integer ( 0 to stop): ";
        int input;
        cin >> input;

        if (input == 0) break; // stop if input is 0
        if (input < 0) {
            cout << "Error: Negative numbers are not allowed. \n";
        } else {
            array[index++] = input;

           index++
        }

     }

    return index;   // Return the number of values stored
}

// Function to display the main menu and get user choice
char displayMainmenu() {
    char choice
    cout << "\nMain Menu:\n";
    cout << "A - Display all values\n";
    cout << "B - Find largest value\n";
    cout << "C - Find smallest value\n";
    cout << "D - Calculate sum\n";
    cout << "E - Calculate mean\n";
    cout << "F - Add more values\n";
    cout << "Q - Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    return toupper(choice); // to make choice case-insensitive

}

// Function to find the largest value in the array
int findLargest(int array[], int index) {
   int largest = array[0];
    for (int i = 1; i < index; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
    }
    return largest;
}

// Function to find the smallest value in the array
int findSmallest(int array[], int index) {
    if (index == 0) return 0;

    int smallest = array[0];
    for (int i = 1; i < index; i++) {
        if (array[i] < smallest) {
            smallest = array[i];  // update smallest if a smallest value is found
        }
    }
    return smallest; 
}

// Function to calculate the sum of values in the array
int calculationSum(int array[], int index) {
    int sum = 0;
    for (int i = 0; i < index; i++) {
        sum += array[i];
    }
    return sum;
}

// Function to calculate the mean (average) of values in the array
double calculateMean(int array[], int index) {
    if (index == 0) return 0.0; // to avoid division by zero;
    int sum = calculateSum(array, index);
    return static_cast<double>(sum) / index;
}

// Function to display all values in the array
void displayArrayValues(int array[], int index) {
    for (int i = 0; i < index; i++) {
        cout << array[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl; //  to print 10 numbers per line
    }
    cout << endl;
}

// Function to add  new values to the array
int addNewValues(int array[], int index, int max_size) {
    int new_input;
    int added_count = 0;

    while (index + added_count < max_size) {
        cout << "Enter a new integer (0 to stop):  ";
        cin >> new_input;

        if (new_input == 0) {
            break;     // stop if input is 0
    
        } else if (new_input < 0) {
            cout << "Error: Negative numbers are not allowed.\n";

        } else {
            array[index + added_count] = new_input;
            added_count++; // Increment the number of new values added
        }
    }
    
    return added_count; // Return the number of new values added
}

int main() {
    const int MAX_SIZE = 100;
    int numbers[MAX_SIZE];

    displayProgramInfo();

    char choice;
    do {
        choice = displayMenu();

        switch (choice) {
            case 'A':  // Largest value
                cout << "Largest value: " << getLargest(numbers, index) << endl;
                break;
            case 'B': // Smallest value
                cout << "Smallest value: " << getSmallest(numbers, index) << endl;
                break;
            case'C': // Sum of values
                cout << "Sum of values: " << calculateSum(numbers, index) << endl;
                break;
            case'D':  // Mean(average) of values
                cout << "Average of values: " << calculateMean(numbers, index) << endl;
                break;
            case'E':  // display all values
                displayValues(numbers, index);
                break;
            case'Q': // Quit
                cout << "Exiting program.\n";
                break;
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 'Q');

    return 0;
}