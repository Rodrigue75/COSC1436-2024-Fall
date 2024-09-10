#include <iostream>
#include <string>
int main()
{
    //Getting input
    std::string name;
    std::cout << "Enter your name: ";

    // std::cin >> V
    //Inserts value up to first whitespace into variable 
    //Doesn't work with spaced strings
   // std::cin >> name;
    std::getline(std::cin, name);

    //std::cout << "Hello " << name << std::endl;

    int hours;
    std::cout << "How many hours did you work this week? ";
    std::cin >> hours;

    double payRate;
    std::cout << "How much do you earn an hour? ";
    std::cin >> payRate;

    std::cout << "You earned $" << (hours * payRate) << "this week" << std::endl;

     //Multi-values input, values are whitespace separated
    int x, y;
    std::cout << "Enter the X,Y values of a point: ";
    std::cin >> x >> y;


     //Type coercion - Compiler changes type of expression
    //no impact on runtime code generation
    //it's always safe we don't loose any data
    // only impacts current expression
    // Type hierarchy: large of two operand types
    // double
    // float
    // usigned long
    // long
    // unsigned int
    // int
    // char/short/unsigned short (automatic to int)
    // double = int * double
    // double = double * double (type coercion)
    // double = double
    double result = hours * payRate;
    // Precedence rules don't apply, just find the largest type 
    //  Exple:double + float * int => double

    //Assignment doesn't matter types determined on each side of operator
    // double = int * float

    // Overflow and underflow
    short smallValue = 32767 + 1; // Overflow
    std::cout << smallValue << std::endl;

    short largeValue = -32768 - 1; // Underflow
    std::cout << largeValue << std::endl;

    float floatValue = 1e38 + 1e2;
    std::cout << floatValue << std::endl;

}