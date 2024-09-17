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

int main()
{
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

    //// Display movie details 
    cout << "----------------" << endl;
    cout << movie.Title << endl;
}
