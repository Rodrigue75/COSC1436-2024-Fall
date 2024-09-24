//int left, right
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//  Movie: Title, Actors, Run lengtgh, Description, Genres, Director(s), Release Year, MPAA Rating
struct Movie
{
    //Required
    string Title;
    // At least 0, minutes
    int Runlenght;

    //Optional
    string Description;

    // >= 1900
    int ReleaseYear;

    bool IsClassic;

};
enum MenuCommand
{
    MC_AddMovie,
    MC_EditMovie,
    MC_DeleteMovie,
    MC_ViewMovie,

int main()
{

    // Show menu
    cout << "Movie Library" << endl;
    cout << "------------" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;

    /// Get input
    char input;
    cin >> input;

    int menuCommand
    switch (input)
    {
        case 'A':
        case 'a': menuComand = 1; break;

        case 'E':
        case 'e': menuCommand = 2; break;

        case 'D':
        case 'd':menuCommand = 3; break;

        case 'V':
        case 'v': menuCommand = 4; break;

        default: cout << "Bad input" << endl; break;

    
    // Relational demo
    // rel_op ::= < <= > == !=
    //rel_exp ::= E rel_op E (boolean)


   //int left, right;
  //  std::cout << "Enter a left and right value: ";
   // std::cin >> left >> right;

     //Mangle the values
    // do not use == equality floating point values to avoid rounding errors
    // Except when comparing floating point value to an integral (e.g f == 45)
   /*left = (left * 21) / 21;
        right = (right * 15) / 15;*/

        //bool areEqual = left = right == 20;
        //bool areEqual = left = right = 20;

    //String comparaison for case insensitive
    // strcmpi (string, string) => int
    // when using C++ strings specify values as 'expr' .c_str()
    //returns < 0 if left < right
    //          = 0 if left == right
    //        > 0 if left > right
   // cout << left << "ciequal " << right << " = " << _strcmpi(left.c_str(),  right.c_str()) << endl;
   //cout << left << " == " << right << " = " << (left == right) << endl;
   //cout << left << " < " << right << " = " << (left < right) << endl;
   // cout << left << " <= " << right << " = " << (left <= right) << endl;
   // cout << left << " > " << right << " = " << (left > right) << endl;
   // cout << left << " >= " << right << " = " << (left >= right) << endl;
    //cout << left << " != " << right << " = " << (left != right) << endl;
   // cout << endl;


    // Decision making - IF statement 
    // if-stmt ::= if (Eb) S ;

    //Create a new movie
    Movie movie;// = {0};

    //Get required title
    cout << "Enter a title ";
   // cin >> movie.Title;
    getline(cin, movie.Title);

    if (movie.Title == "")
    {
        cout << "ERROR Title is required" << endl;

        cout << "Enter a title ";
        getline(cin, movie.Title);
    };

    //Get run lenght, at least 0, minutes
    cout << "Enter run lenght (in minutes): ";
    cin >> movie.Runlenght;


    if (movie.Runlenght <= 0)
    {
        //Look at aditional stuff...

        if (movie.Runlenght < 0)
        {
            cout << "ERROR: Run lenght must be at least 0" << endl;

            cout << "Enter Run lenght (in minutes): ";
            cin >> movie.Runlenght;
        };

    } else if (movie.Runlenght > 1440)
    {
        cout << "ERROR: Run lenght cannot be greather than a day" << endl;

        cout << "Enter Run lenght (in minutes): ";
        cin >> movie.Runlenght;
    };

        //Get release year, at least 1900
    cout << "Enter release year (1900+): ";
    cin >> movie.ReleaseYear;

    if (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
        cout << "ERROR: Release year must be between 1900 and 2100" << endl;

    cout << "Enter release year (1900+): ";
    cin >> movie.ReleaseYear;

    //Get the optional description
    cout << "Enter optional description: ";
    cin.ignore();
    getline(cin, movie.Description);

    //Get Is classic
    char isClassic;
    cout << "Is this a classic (Y/N)? ";
    cin >> isClassic;

    /*if (isClassic == 'Y')
        movie.IsClassic = true;
    else if (isClassic == 'y')
        movie.IsClassic = true;
    else if (isClassic == 'N')
        movie.IsClassic = false;
    else if (isClassic == 'n')
        movie.IsClassic = false;*/
   /* if (isClassic == 'Y' || isClassic == 'y')
        movie.IsClassic = true;
    else if (isClassic == 'N' || isClassic == 'n')
        movie.IsClassic = false;

    else
    {

        cout << "ERROR: you must enter Y or N";

        cout << "is this a classic (Y/N)?";
        cin >> isClassic;
    };*/

    //switch (select) statement - replacement for if-elseif where same expression compared to multiple values
    // 1. Must compare a single expression to one or more constant values with equality
    //2. switch expression must be an integral type
    //3. Each case label must be a compile-time constant expression 
    //4. Each case label must be unique
    switch (isClassic)
    {

        case 'Y': movie.IsClassic = true; break;
        case'y': movie.IsClassic = true; break;

        case 'N':  movie.IsClassic = false; break;
        case'n':  movie.IsClassic = false; break;

        default:
        {

            cout << "ERROR: you must enter Y or N";

            cout << "is this a classic (Y/N)?";
            cin >> isClassic;
        };
    };

        //// Display movie details 
    cout << "----------------" << endl;
    cout << movie.Title << endl;
    cout << movie.Title << " (" << movie.ReleaseYear << ")" << endl;
    cout << "Run Lenght (mins) " << movie.Runlenght << endl;

    // Long form - 1
    //if (movie.IsClassic)
    // cout << "Is Classic? Yes << endl;
    // else
    // cout << "Is Classic? No << endl;
    //Better but longer form - 2
    /*string classicIndicator;
    * if (movie.IsClassic)
    * classicIndicator = "Yes"
    else
        classicIndicator = "No"
        cout << "Is Classic? " << classicIndicator << endl;*/

    //Shorterst form using conditional operator => Eb ? Et :Ef
    // Et & Ef = must be the exact same type, type coersion is not allowed
    cout << " Is Classic? " << (movie.IsClassic ? "Yes" : "No") << endl;
    

    if (movie.Description != "")
        cout << movie.Description << endl;
    cout << "-------------------" << endl;

}
