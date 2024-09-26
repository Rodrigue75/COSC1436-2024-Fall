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
    int Runlength;

    //Optional
    string Description;

    // >= 1900
    int ReleaseYear;

    bool IsClassic;

};

// Integral data type with name values
enum MenuCommand
{
   // MC_Begin,
    AddMovie = 1,    //const int MenuCommand::MC_AddMovie = 0;
    EditMovie,
    DeleteMovie,
    ViewMovie,
    //MC_End

};
//enum class TestEnum
//{
//    MC_AddMovie
//};
//TestEnum testValue = TestEnum::MC_AddMovie; //MC_AddMovie //TestEnum::MC_AddMovie;

int main()
{

    // Show menu
    cout << "Movie Library" << endl;
    cout << "------------" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;

    //While-stm ::=while (Eb) S;
    // Pretest, S executes zero or more times

    /// Get input
    MenuCommand  menuCommand = (MenuCommand)0;
   // bool done = false;
   // while (!done)
    // while (menuCommand == 0); infinite loop don't do it

        while (menuCommand == 0)
  {
      char input;
        cin >> input;

   
        switch (input)

        {
            case 'A':
            case 'a': menuCommand = MenuCommand::AddMovie; break;

            case 'E':
            case 'e': menuCommand = MenuCommand::EditMovie; break;

            case 'D':
            case 'd': menuCommand = MenuCommand::DeleteMovie; break;

            case 'V':
            case 'v': menuCommand = MenuCommand::ViewMovie; break;

            default: cout << "Bad input" << endl; break;

        };

};

        cin.ignore();

    //int shouldntwork = MenuCommand::MC_AddMovie;
    //menuCommand = (MenuCommand)100;

    // Handle menu command
        switch (menuCommand)
        {
            case MenuCommand::AddMovie:
            case MenuCommand::EditMovie:
            case MenuCommand::DeleteMovie:
            case MenuCommand::ViewMovie: cout << "Not implemented" << endl; break;
        };

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
    while (movie.Title == "")
    {
        cout << "Enter a title: ";
       // cin >> movie.Title;
        getline(cin, movie.Title);

        //Decision making - if statement
        // if stmt ::= if (Eb) s;
        
        if (movie.Title == "")
        
        {    cout << "ERROR Title is required" << endl;

            cout << "Enter a title: ";
            getline(cin, movie.Title);
        };

    };

    //Get run lenght, at least 0, minutes
    movie.Runlenght = -1
    while (movie.Runlength < 0 || movie.Runlenght > 1440)
    {
        cout << "Enter run lenght (in minutes): ";
        cin >> movie.Runlenght;


        if (movie.Runlenght <= 0)
        {
            //Look at aditional stuff...

            if (movie.Runlength < 0)
            {
                cout << "ERROR: Run lenght must be at least 0" << endl;

                cout << "Enter Run lenght (in minutes): ";
                cin >> movie.Runlenght;
            };

        } else if (movie.Runlenght > 1440)
        {
            cout << "ERROR: Run lenght cannot be greather than a day" << endl;

            cout << "Enter Run lenght (in minutes): ";
            cin >> movie.Runlength;
        };
    };
        //Get release year, at least 1900
    while (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
    {
        cout << "Enter release year (1900+): ";
        cin >> movie.ReleaseYear;

        if (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
            cout << "ERROR: Release year must be between 1900 and 2100" << endl;

        cout << "Enter release year (1900+): ";
        cin >> movie.ReleaseYear;
    };

    //Get the optional description
    cout << "Enter optional description: ";
    cin.ignore();
    getline(cin, movie.Description);

    //Get Is classic
    bool done = false;
    while (!done)
    {
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

        case 'Y': 
        case'y': movie.IsClassic = true; done = true; break;

        case 'N':  
        case'n':  movie.IsClassic = false; done = true;break;

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
    cout << "Run Length (mins) " << movie.Runlength << endl;

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

};
