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
    int length;
    length = 0;

    int releaseYear = 1900;

    int rating = 3, stars = 5;

    std::cout << length;
}

