#include <iostream>

//entry point of our code
int main()
{
    //output a message - 1
    std::cout << "Hello World" << std::endl;

    //message - 2
    std::cout << "Hello" << " " << "World" << std::endl;

    //message - 3
    std::cout << "Hello";
    std::cout << " ";
    std::cout << "World";
    std::cout << std::endl;

    //message - 4
    std::cout << "Hello\tWorld\n";
    std::cout << "hello \"Bob\"";

    //File paths
    std::cout << "C:\\windows\\temp";
    //std::cout << R"C:\windows\temp";

    //Variables - named memory location to store data

    //Declaration of variables - tell compiler that a variable exists
    //Scope - is a lifetime of a variable/identifier:lifetime is a point of declaration to end of block
    //Expression - can be used anywhere an expression is allowed
    //Styling - Name:nouns, Casing: Camel
    //
    //Variable-decl ::= T id [ '=' E ] { ',' id [ '=' E ] }* ';'
    int length;
    length = 0;
    //int length = 0; //preferred
    int releaseYear = 1900;

    int rating = 3, stars = 5;

    std::cout << length;
    //Identifiers
    //int _hours, _1stGrade, 1stGrade, first-grade;
    int examGrade, hoursWrked;
    //int exam_grade,hours_worked; DONT DO THIS 
    //std::cout << e

    //Types
    //Defines what kind of data is stored,range and size
    //Primitives - understood by lang
    //|Type | Size | Range |
    //|- | - | - |
    //| short | 2 | +-32767 (integral) |
    //| int | 4 | +- 2 billion (default) |
    //| long | 4 | +- 2 billion |
    //| unsigned * | * | 0-
    //Floats
    //| float | 4 | E+- | precision: 5-7 |
    //| double | 8 | E+- | precision: 12-15 (default) |
    // Text
    //| char | 1 | -128 to 127 | character |
    //| std::string | * | text |
    //| bool | 1? | true or false |
    short s;
    int i = 0;
    long l = 5l
    unsigned int ui = 3U;
    float pi = 3.14159F;
    double largerNumber = 10E100;
    char c = 'A';
    std::string name = "Bob";
    bool isPassing = true;
    //int isOK = 1; //dont do it
    int intsize = sizeof(int);

    //Assignment
    //  asn_op ::= v = E
    //  Must be type compatible
    // Expression of type Vt
    // Associativity - Right
    int shapeLength = 10;
    int shapeWidth = 20;
    int shapeArea;

    shapeArea = shapeLength;
    shapeWidth = 10;
    //20 = shapewidth;

    shapeArea = shapeLength = shapeWidth = 20

   //Arithmetic operators
   // + - * / % (int modulus)
   // arith_op ::= Et op Et
    shapeArea = shapeLength * shapeWidth;
    int remainder = 10 * 3; // 1
    int result = 10 / 3; // 3
    double dresult = 10.0 / 3.0; // 3.333 ( to solve the issue of lost part)

    // unary_op ::= + Et | - Et
    int positiveValue = 10;
    int negativeValue = -positiveValue;

    //Scope
    // block-statement ::= { S* }
    {
        int newVariable = 10;
    }
    //std::cout << newVariable;



}

