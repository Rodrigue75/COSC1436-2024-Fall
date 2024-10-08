#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Movie: Title, Actors, Run length, Description, Genres, Director(s), Release Year, MPAA Rating
struct Movie
{
    //Required
    string Title;

    // At least 0, minutes
    int RunLength;

    //Optional
    string Description;

    // >= 1900
    int ReleaseYear;

    bool IsClassic;

    string Genre;
};

//Integral data type with named values
enum MenuCommand
{
    //MC_Begin,
    AddMovie = 1,    //const int MenuCommand::MC_AddMovie = 0;
    EditMovie,
    DeleteMovie,
    ViewMovie,
    //MC_End
};

//enum class TestEnum
//{
//    AddMovie
//};
//TestEnum testValue = TestEnum::MC_AddMovie;//MC_AddMovie;//TestEnum::MC_AddMovie;

/// Displays main menu
void DisplayMenu()
{
    cout << "Movie Library" << endl;
    cout << "---------------" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;
}

/// Handles the menu selection
void HandleMenu()
{
    //HACK: Fix this
    MenuCommand menuCommand = (MenuCommand)0;
    switch (menuCommand)
    {
        case MenuCommand::AddMovie:
        case MenuCommand::EditMovie:
        case MenuCommand::DeleteMovie:
        case MenuCommand::ViewMovie: cout << "Not implemented" << endl; break;
    };
}

int main()
{
   

     //Function call ::= id ();    
    DisplayMenu();

    //While-stmt ::= while (Eb) S;
    //  Pretest, S executes zero or more times

    //// Get input
    MenuCommand menuCommand = (MenuCommand)0;
    //bool done = false;
    //while (!done)
    //while (menuCommand == 0); infinite loop, don't do it
    do
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
    } while (menuCommand == 0);
    cin.ignore();

    //int shouldntWork = MenuCommand::MC_AddMovie;
    //menuCommand = (MenuCommand)100;

    //// Handle menu command
    HandleMenu();
   /* switch (menuCommand)
    {
        case MenuCommand::AddMovie:
        case MenuCommand::EditMovie:
        case MenuCommand::DeleteMovie:
        case MenuCommand::ViewMovie: cout << "Not implemented" << endl; break;
    };*/

    ////// Add a new movie
    //Create a new movie
    Movie movie;// = {0};

    //Get required title
    //while (movie.Title == "")
    do
    {
        cout << "Enter a title: ";
        //cin >> movie.Title;
        getline(cin, movie.Title);

        //Decision making - IF statement
        // if-stmt ::= if (Eb) S ;
        if (movie.Title == "")
            cout << "ERROR: Title is required" << endl;
    } while (movie.Title == "");

    //Get run length, at least 0, minutes
    movie.RunLength = -1;
    do // while (movie.RunLength < 0 || movie.RunLength > 1440)
    {
        cout << "Enter run length (in minutes): ";
        cin >> movie.RunLength;

        //Nested if
        //if (movie.RunLength <= 0)
        //{
        //    //Look at additional stuff...
        //    
        //    if (movie.RunLength < 0)
        //    {
        //        cout << "ERROR: Run length must be at least 0" << endl;

        //        cout << "Enter run length (in minutes): ";
        //        cin >> movie.RunLength;
        //    };
        //} else if (movie.RunLength > 1440)
        //{
        //    cout << "ERROR: Run length cannot be greater than a day" << endl;

        //    cout << "Enter run length (in minutes): ";
        //    cin >> movie.RunLength;
        //};
        if (movie.RunLength < 0 || movie.RunLength > 1440)
            cout << "ERROR: Run length must be between 0 and 1440" << endl;
    } while (movie.RunLength < 0 || movie.RunLength > 1440);

     //Get release year, at least 1900
    while (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
    {
        cout << "Enter release year (1900+): ";
        cin >> movie.ReleaseYear;

        if (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
            cout << "ERROR: Release year must be between 1900 and 2100" << endl;
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
        /*if (isClassic == 'Y' || isClassic == 'y')
            movie.IsClassic = true;
        else if (isClassic == 'N' || isClassic == 'n')
            movie.IsClassic = false;
        else
        {
            cout << "ERROR: You must enter Y or N";

            cout << "Is this a classic (Y/N)? ";
            cin >> isClassic;
        };*/

        //Switch (select) statement - replacement for if-elseif where same expression compared to multiple values
        // 1. Must compare a single expression to one or more constant values with equality
        // 2. Switch expression must be an integral type
        // 3. Each case label must be a compile-time constant expression
        // 4. Each case label must be unique
        switch (isClassic)
        {
            case 'Y':
            case 'y': movie.IsClassic = true; done = true; break;

            case 'N':
            case 'n': movie.IsClassic = false; done = true; break;

            default:
            {
                cout << "ERROR: You must enter Y or N";
            };
        };
    };
    cin.ignore();

    // Get genre(s)
    //int genreCount = 0;
    //while (genreCount < 5)   // = 0, < N (rarely) = 1, <= N
    //{
    //    cout << "Enter optional genre: " << (genreCount +1) << ": ";

    //    string genre;
    //    getline(cin, genre);
    //    if (genre != "")
    //    {
    //        movie.Genre += genre + ", ";
    //    };
    //    
    //    genreCount++; //Prefix/postfix

    //};

    // for loop - designed to iterate a fixed number of times with a well known start and end
     // int genreIndex = 0;
    for (int index = 0; index < 5; ++index) // = 0, < N (RARELY) =1, <= 1

    {
        cout << "Enter optional genre: " << (index + 1) << ": ";

        string genre;
        getline(cin, genre);
        if (genre == "")
        //    break; //Exits the loop
      //  continue; //Loops only -stops the current iteration and loops again
            movie.Genre += genre + ", ";

    };
       // cout << genreIndex;
        //More complex loops
      //  for (int index = 0, int y = 1; index < 5, index < y; ++index, y+=2) // = 0, < N (RARELY) =1, <= N {};
       // int someIndex = 0;
        //for (;;) {}; //Infinite loop



    ///// Display movie details
    cout << "---------------" << endl;
    cout << movie.Title << " (" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;

    // Long form - 1
    //if (movie.IsClassic)
    //    cout << "Is Classic? Yes" << endl;
    //else
    //    cout << "Is Classic? No" << endl;
    // Better but longer form - 2
    /*string classicIndicator;
    if (movie.IsClassic)
        classicIndicator = "Yes";
    else
        classicIndicator = "No";
    cout << "Is Classic? " << classicIndicator << endl;*/

    //Shorter form using conditional operator => Eb ? Et : Ef    
    //string classicIndicator = movie.IsClassic ? "Yes" : "No";
    //cout << "Is Classic? " << classicIndicator << endl;

    //Shortest form using conditional operator => Eb ? Et : Ef  
    // Et & Ef = must be the exact same type, type coercion is not allowed  
    cout << "Is Classic? " << (movie.IsClassic ? "Yes" : "No") << endl;
    if (movie.Genre != "")
        cout << "Genre(s) " << movie.Genre << endl;
    if (movie.Description != "")
        cout << movie.Description << endl;
    cout << "---------------" << endl;
}