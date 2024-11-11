#include <iostream>
#include<iomanip>
#include<string>

void StackDemo()
{
    double localDouble = 45.6;

    //Declare a pointer to a double
    // Pointer is always a memory address
    // Pointer is always either 4 or 8 bytes long
    // pointer value is always an integral value

    // Pointers always have 2 data points: value (memory address), value they reference (in memory)
    // address-of :: & variable 
    // Type of the expression is T* whare T is the type of the variable
    double* ptrDouble = &localDouble; //pointer to double

    //Assign new value to value at memory address
    *ptrDouble = 89.7;

    // Type coersion doesn't behave the same with poiunters
    int localInt = 56;
    localDouble = localInt;
   // ptrDouble = &localInt; not allowed

    // double* != double
    //  ptrDouble = 90.6;

    // Deference a pointer we use the deference operator :: *expr
    // The type of expression is T where E is T*    (T*= pointer of T)
    std::cout << *ptrDouble << " " << *ptrDouble << std::endl;
    std::cout << (*ptrDouble == localDouble) << std::endl;
};

void EmptyDemo() {

    float PayRate = 12.50;
    
    // Always init to 0 or valid memory
    //float* pPayRate = NULL;     // C, old school, not recommended
    float* pPayRate = nullptr;    // C++, recommended

    //Print value and deferenced value
    std::cout << pPayRate << " = ";

    //Always verify the poiunter before deferencing
    //   if (ptr != nullptr)
    //   if (ptr != NULL)  // not recommended
    //   if (ptr)
    // if (pPayrate != nullptr)
    if (pPayRate)
    std::cout << *pPayRate;
    std::cout << std::endl;
}

struct Employee {
    int Id;
    std::string Name;

    int DummyValues[1000];
};

void DynamicMemoryDemo()
{
    const int MaxEmployees = 100;
    Employee* employees[MaxEmployees] = {0};
    int id = 1000;

    //int numbeerOfEmployees = 0;
    for (int index = 0; index < 100; ++index)
    {
        std::string name;
        std::cout << "Enter name or empty to quit: ";
        std::getline(std::cin, name);

        if (name == "")
            break;

        //Add to array
        // new-op :: new T; returns T*
        Employee* employee = new Employee;
       // (*employee).Id = ++id;
        employee->Id = ++id;
        employee->Name = name;
        employees[index] = employee;
       // ++numberOfEmployees;
    };


    //Print employees
    for (int index = 0; index < MaxEmployees; ++index)
    {
        //if done then abort
        if (employees[index] == nullptr)
            break;
        std::cout << "[" << employees[index]->Id << "] " << employees[index]->Name << std::endl;
    };

    // Ensure that any memory allocated by new is cleaned up using delete
    // delete-op ::= delete E;

    for (int index = 0; index < MaxEmployees; ++index)
    {
        //if done then abort
        if (employees[index] == nullptr)
            break;
        
        //Delete the memory
        Employee* employee = employees[index];
        delete employee;
        employees[index] = nullptr; // Always reset to null to avoid issues
        delete employees[index];  //This work
        //employee->Id = 20; // going to fail

        //delete &index;  // bad things will happen
    };
}
int main()
{
   
   //StackDemo();
   //EmptyDemo();
   DynamicMemoryDemo();

}
