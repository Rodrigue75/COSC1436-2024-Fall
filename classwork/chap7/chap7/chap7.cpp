#include <iostream>
#include <string>
#include <iomanip>

struct point
{
    int x;
    int y;
};

struct Rectangle
{
    point topLeft;
    point bottomRight;
};

void Display(point point)
{
    std::cout << "(" << point.x << "," << point.y << ")";
}

void Display(Rectangle rect)
{
    //std::cout << "(" rect.topLeft.X << "," << rect.topLeft.Y << ")";
    std::cout << "(" << rect.topLeft.x << "," << rect.topLeft.y << ")";
    std::cout << "(";
    Display(rect.topLeft);
    std::cout << " ";
    Display(rect.bottomRight);
    std::cout << ")" << std::endl;
};
void Translate(Rectangle rect, int offsetX, int offsetY)
{
    rect.topLeft.x += offsetX;
    rect.bottomRight.x += offsetX;

    rect.topLeft.x += offsetY;
    rect.bottomRight.x += offsetY;
}
void TestPassByReference()
{
    Rectangle rc;
    rc.topLeft.x = 10;
    rc.topLeft.y = 20;

    rc.bottomRight.x = 100;
    rc.bottomRight.y = 75;
    Display(rc);

    Translate(rc, 5, 10);
    Display(rc);
}

int main() {
    const int MaxGrades = 20;
    double dummyValue2 = -1;
    int grades[MaxGrades];
    double dummyValue = 0;

    int estimatedMaxArraySize = //Size of array / Size of element
        sizeof(grades) / sizeof(int);
    
    int count = 0;
    for (int index = 0; index < MaxGrades; ++index)//, ++count)
    {
        std::cout << "Enter a grade: ";
        std::cin >> grades[index];
        //grades[index] = 100;

        if (grades[index] <= 0)
            break;

        ++count;
    };

    //for (int index = 0; index < MaxGrades; ++index) for entire array
        for (int index = 0; index < count; ++index)
    {
        std::cout << grades[index] << std::endl;
    }
    int indexToChange;

    do {
        std::cout << "Enter the index of the grade to change: ";
        std::cin >> indexToChange;
    } while (indexToChange < 0 || indexToChange >= MaxGrades);

    int newGrade;
    std::cout << "Enter the new garde: ";
    std::cin >> newGrade;

    grades[indexToChange] = newGrade;
}

void InitArrayDemo()
{
    const int MaxRates = 100;
    double payRates[MaxRates] = {0}; //Zero initialize

    ////Zero init
    //for (int index = 0; index < MaxRates; ++index)
    //    payRates[index] = 0;

 // Init days of month
    std::string monthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    monthNames[0] = "Jan";
    monthNames[1] = "Feb";
    monthNames[2] = "Mar";
    monthNames[3] = "Apr";
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    daysInMonth[0] = daysInMonth[2] = daysInMonth[4] = daysInMonth[6] =
      daysInMonth[7] = daysInMonth[9] = daysInMonth[11] = 31;
    daysInMonth[1] = 28;
    daysInMonth[3] = daysInMonth[5] = daysInMonth[8] = daysInMonth[10] = 30;

    for (int index = 0; index < 12; ++index)
        std::cout << monthNames[index] << " has " << daysInMonth[index] << " days " << std::endl;
}

// Functions parameters 'T id[]'
//  Always open array, no size
bool AreArraysEqual(int left[], int leftsize,int right[], int rightsize )
{
    if (leftsize != rightsize)
        return false;


    for (int index = 0; index < leftsize; ++index)
        if (left[index] != right[index])
            return false;

    return true;
};

int CopyArray(int left[], int leftSize, int right[], int rightSize)
{
    int size = (leftSize < rightSize) ? leftSize : rightSize;
    for (int index = 0; index < size; ++index)
        left[index] = right[index];

    return size;

};

void InitializeArray (int values[], int size, int initialValue)
{
    for (int index = 0; index < size; ++index)
        values[index] = initialValue;
}

void UseArrayDemo()
{
    int array1[20] = {0};

   /* for (int index = 0; index < 20; ++index)
        array1[index] = index + 1;*/


    InitializeArray(array1, 20, 2);
    /*int index2 = 0;
    while (index2 < 20)
        array1[index2++] = index2 + 1;*/

    // For loop for iterating arrays
    //for (int index = 0; index < 20; ++index)
    //  std::cout << arrayindex1[index] << std::endl;
    for (int value : array1)
        std::cout << value << std::endl;

    int array2[20] = {0};
    int array3[20] = {0};
    // array3[19] = 10;
    // Compare arrays
    std::cout << (array2 == array3)
        << " " << AreArraysEqual(array2, 20, array3, 20)
        << std::endl;

    // Assignment
    // array3 = array2;
    CopyArray(array3, 20, array2, 20);

    void DisplayArray(int values[], int size, int valueWidth, int maxCellsPerRow)
    {

        std::cout << std::left;

        for (int index = 0; index < size; ++index)
            std::cout << std::setw(valueWidth) << values[index] << " ";
        //If we have printed out maxCellsPerRow values, then newline
        if (index > 0 && index % maxCellsPerRow == 0)
            std::cout << std::endl;
    };

    std::cout << std::right << std::endl;

}

//Multi-D table passed like single-D tables
//
void DisplayTable(int values[][10], int size)
{
    for (int row = 0; row < size; ++row);

        /*for (int col = 0; col < 10; ++col)
            ;*/
}
 void TableDemo()
 {
     //[rows][cols] - compile size for all dimensions
     int multiplication[5][10] = {
                                 {1, 2, 3, 4, 5}
                                 ,{ 2, 4, 6, 8, 10 }
     };

     //Init values
     //Row major ordering - rows are enumerated, then columns
     for (int row = 0; row < 5; ++row)
         for (int col = 0; col < 10; ++col)
             multiplyTable[row][col] = (row + 1) * (col + 1);

     //// Column major ordering - columns are enumerated, then rows
     //for (int row = 0; row < 5; ++row)
     //    for (int col = 0; col < 10; ++col)
     //        multiplyTable[row][col] = (row + 1) * (col + 1);


 //    //Display table
 //    DisplayTable(multiplyTable, 5);
 //    for (int row = 0; row < 5; ++row)
 //    {
 //        for (int col = 0; col < 10; ++col)
 //            std::cout << std::setw(5) << multiplyTable[row][col];

 //        std::cout << std::endl;
 //    };
 //}



int main()
{
    TableDemo();
}

void NameArrayDemo()
{
    //Array is a set of related data
   /* std::string student1;
    std::string student2;
    std::string student3;
    std::string student4;
    std::string student5;*/
    const int MaxStudents = 100;  // solve maintenance issue of array size
    std::string students[MaxStudents];

    //Store roster of students
    // When using for loop use = 0 to < N
    for  (int index = 0; index < MaxStudents; ++index)
    {
        std::string student;
        std::cout << "Enter student name: ";
        getline(std::cin, student);
        if (student == "")
            break;
        // student at index 0, first element
        // students sub 0
        // array access operator
        students[index] = student;

    };
    // print roster
    for (int index = 0; index < MaxStudents; ++index)
    {
        if (students[index] != "")
        std::cout << students[index] << std::endl;
    };
}


