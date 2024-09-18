 /*
Lab 1: Grade Calculator
Author: Rodrigue Edmond Tonda
Course: COSC 1436 Fall 2024
*/

#include <iostream>
#include <iomanip>  // for setprecision
#include <string>   // for string

int main() {
    // Declare variables for storing user information and grades
    std::string studentName;
    int lab1, lab2, lab3, lab4;
    int exam1, exam2, exam3;
    int participation, finalExam;

    // Display program information
    std::cout << "Lab 1: Grade Calculator" << std::endl;
    std::cout << "Author: Rodrigue Edmond Tonda" << std::endl;
    std::cout << "Course: COSC 1436 Fall 2024" << std::endl;
    std::cout << "---------------------------------" << std::endl;

    // Collect user's name
    std::cout << "Please enter your name: ";
    std::getline(std::cin, studentName);  // Use getline to accept full names

    // Collect lab grades
    std::cout << "Please enter lab 1 grade: ";
    std::cin >> lab1;
    std::cout << "Please enter lab 2 grade: ";
    std::cin >> lab2;
    std::cout << "Please enter lab 3 grade: ";
    std::cin >> lab3;
    std::cout << "Please enter lab 4 grade: ";
    std::cin >> lab4;

    // Collect exam grades
    std::cout << "Please enter exam 1 grade: ";
    std::cin >> exam1;
    std::cout << "Please enter exam 2 grade: ";
    std::cin >> exam2;
    std::cout << "Please enter exam 3 grade: ";
    std::cin >> exam3;

    // Collect participation and final exam grades
    std::cout << "Please enter participation grade: ";
    std::cin >> participation;
    std::cout << "Please enter final exam grade: ";
    std::cin >> finalExam;

    // Calculate averages
    double labAverage = (lab1 + lab2 + lab3 + lab4) / 4.0;
    double examAverage = (exam1 + exam2 + exam3) / 3.0;
    double classAverage = (labAverage * 0.65) + (examAverage * 0.20) +
        (participation * 0.05) + (finalExam * 0.10);

// Display lab grades and average
    std::cout << "---------------------------------" << std::endl;
    std::cout << studentName << ", your lab grades are: " << std::endl;
    std::cout << "Lab 1 = " << lab1 << std::endl;
    std::cout << "Lab 2 = " << lab2 << std::endl;
    std::cout << "Lab 3 = " << lab3 << std::endl;
    std::cout << "Lab 4 = " << lab4 << std::endl;
    std::cout << std::fixed << std::setprecision(2); // Format to 2 decimal places
    std::cout << "Lab Average (65%) = " << labAverage << "%" << std::endl;

    // Display exam grades and average
    std::cout << "---------------------------------" << std::endl;
    std::cout << studentName << ", your exam grades are: " << std::endl;
    std::cout << "Exam 1 = " << exam1 << std::endl;
    std::cout << "Exam 2 = " << exam2 << std::endl;
    std::cout << "Exam 3 = " << exam3 << std::endl;
    std::cout << "Exam Average (20%) = " << examAverage << "%" << std::endl;

    // Display participation and final exam grades
    std::cout << "---------------------------------" << std::endl;
    std::cout << studentName << ", your other grades are: " << std::endl;
    std::cout << "Participation (5%) = " << participation << "%" << std::endl;
    std::cout << "Final Exam (10%) = " << finalExam << "%" << std::endl;

    // Display class average
    std::cout << "---------------------------------" << std::endl;
    std::cout << studentName << ", your class grade is: " << std::endl;
    std::cout << "Class Average = " << classAverage << "%" << std::endl;

}