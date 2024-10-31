#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// Constants
const double GRAVITY = 9.8;                                 //  Gravitational constant in meters per second squared
const double METERS_TO_FEET = 3.28084;                      // conversion from meters to feet


// Function prototypes
void displayProgramInfos();
int getFallingTime();
char getDistanceUnit();
double calculateFallingDistance(int seconds);
void displayFallingDistanceTable(int time, char unit);
double convertToFeet(double meters);

// Main Function

int main() {
    displayProgramInfos();

    int fallingTime = getFallingTime();
    char unit = getDistanceUnit();

    displayFallingDistanceTable(fallingTime, unit);

    return 0;

}

    // Function to display program information
void displayProgramInfos() {
    cout << "Program Title: Falling Distance Calculator\n";
    cout << "Name: Rodrigue Edmond\n" ;
    cout << "Course: COSC 1436 - Fall 2024\n";
    cout << "Lab3\n" << std::endl;
}


// Function to prompt and validate falling time input

int getFallingTime() {
    int time;
    cout << "please enter the number of seconds (1-60):";
    cin >> time;

    if (time >= 1 && time <= 60) {
        cout << "You enterd a valid number of time: " << time << endl;
    } else {
        cout << "Invalid input. Please enter a number between 1 and 60." << endl;
    }
    return time;
}

// Function to calculates the appropriate falling distance for a given time (second) 

double calculateFallingDistance(int seconds) {
    return 0.5 * GRAVITY * seconds * seconds;     // distance =  0.5 * g * t^2
}


// Function to get distance unit 

char getDistanceUnit() {
    char unit;
    do {
        cout << "Do you want the results in meters (m) or feet (f)?";
        cin >> unit;
        unit = tolower(unit);       // Makes input case insensitive
        if (unit != 'm' && unit != 'f') {
            cout << "Invalid input. please enter 'm' for meters or 'f' for feet." << endl;
     
        }
    } while (unit != 'm' && unit != 'f');
    return unit;
}

// Function to convert distance from meters to feet

double convertToFeet(double meters) {
    return meters * METERS_TO_FEET;
}
 
// Function to display the falling distance table

void displayFallingDistanceTable(int time, char unit) {
    cout << "\nSeconds              Distance\n";
    cout << "===============================\n";

    for (int second = 1; second <= time; ++second) {
        double distance = calculateFallingDistance(second);

        if (unit == 'f') {
            distance = convertToFeet(distance);
            cout << setw(2) << second << "    "
                << fixed << setprecision(2)
                << distance << " ft\n";
        } else {
            cout << setw(2) << second << "   "
                << fixed << setprecision(2)
                << distance << " m\n";
        }
    }
}
