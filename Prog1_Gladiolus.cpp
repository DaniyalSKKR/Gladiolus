/* ---------------------------------------------
    Program 1: Gladiolus
        Prompt for the number of sections and display
        an ASCII gladiolus flower, with the sections centered
        above each other.

    Course: CS 141, Fall 2021. Tues 5pm lab
    System: Mac using Xcode
    Author: Dale Reed
    
    Original ASCII graphics gives:
       ------------------------------------------
           ______     _____
          /          /     \      /   /    /    /
         /          |            /   /    /    /
        |            ---        /    -----    /
        |               \      /        /    /
         \_____   \_____/     /        /    /

        ------------------------------------------
        
    Sample program run:
        Program 1: Gladiolus
        Choose from among the following options:
           1. Display original graphic
           2. Display Gladiolus
           3. Exit the program
        Your choice -> 2
        Number of sections -> 3
           ---
          ( @ )
           ---
          (   )
         (  @  )
          (   )
           ---
          (   )
         (     )
        (   @   )
         (     )
          (   )
           ---
            |/
            |
           \|
            |
            |/
            |
        Exiting
   ---------------------------------------------
*/

#include <iostream>   // for cin and cout
#include <iomanip>    // for setw. The number in setw(...) is the total of blank spaces including the printed item.
using namespace std;  // so that we don't need to preface every cin and cout with std::


// --------------------------------------------------------------------------------------------------
// Entire program is given inside of main(), which is acceptable since this is the first program.
int main() {

    // Display the menu and get the user choice
    int menuOption = 0;
    cout << "Program 1: Gladiolus            \n"
         << "Choose from among the following options:  \n"
         << "   1. Display original graphic  \n"
         << "   2. Display Gladiolus         \n"
         << "   3. Exit the program          \n"
         << "Your choice -> ";
    cin >> menuOption;
    
    // Handle menu option of 3 to exit
    if( menuOption == 3) {
        exit( 0);
    }
    // Handle menu option of 1 to display custom ASCII graphics
    else if( menuOption == 1) {
        // My own graphic.  You must create your own.
        cout << setw( 8) << " ";
        // Display a line across the top
        for( int i=0; i<42; i++) {
           cout << "-";
        }
        cout << endl;
        // Display ASCII graphics for "CS 141".  Yours must be different!
        cout << setw( 8) << " " << "   ______     _____                       \n"
             << setw( 8) << " " << "  /          /     \\      /   /    /    /  \n"
             << setw( 8) << " " << " /          |            /   /    /    /   \n"
             << setw( 8) << " " << "|            ---        /    -----    /    \n"
             << setw( 8) << " " << "|               \\      /        /    /     \n"
             << setw( 8) << " " << " \\_____   \\_____/     /        /    /      \n"
             << endl;
        cout << setw( 8) << " ";
        // Display a line across the bottom
        for( int i=0; i<42; i++) {
            cout << "-";
        }
        cout << endl;
    } //end if( menuOption == 1)  // menu option to display custom graphic

    else if( menuOption == 2) {
        // Prompt for and get the number of flower sections.
        int numberOfSections = 0;
        cout << "Number of sections -> ";
        cin >> numberOfSections;
        
        // Loop to display each flower section.
        for( int section = 1; section <= numberOfSections; section++) {
            
            // Display the top row for this section
            cout << setw(numberOfSections + 3) << "---" << endl;
            
            // Display the petal rows for a single flower section.
            // The relationship between section number and total number of rows is:
            //    Section   # Rows
            //       1        1
            //       2        3
            //       3        5
            //       4        7
            // The rows are handled in 3 pieces:
            //    1. The top half
            //    2. The middle row
            //    3. The bottom half (w/numbering starting from 1 again)
            // Each of these is handled in turn below.  For instance consider
            // a 4-section Gladiolus.  The 4th section (the largest one) would look
            // like the following.  In this program we use a loop counter
            // to count up from 0 in the top half, we handle the middle
            // row separately, and count down starting from (section - 1)
            // in the bottom half.  This could be done differently just as well.
            //            Row
            //   (   )     0     <--|
            //  (     )    1     <--|---- Top Half
            // (       )   2     <--|
            //(    @    )     <-- Middle Row
            // (       )   3     <--|
            //  (     )    2     <--|---- Bottom Half
            //   (   )     1     <--|

            // 1. Display the top half of this flower section, getting wider as rows progress
            for( int row=0; row<(section-1); row++) {
                cout << setw( numberOfSections - row) << "("; // Left section up to '('
                cout << setw( (row * 2) + 4) << ")";          // Right section up to ')'
                cout << endl;
            }
            
            // 2. Display the single middle row for this flower section, containing "@"
            cout << setw( numberOfSections - section + 1) << "("; // Left section up to '('
            cout << setw( section + 1) << "@";                    // Middle section with '@'
            cout << setw( section + 1) << ")" << endl;            // Right section up to ')'
            
            // 3. Display the bottom half of this flower section, getting narrower as rows progress
            for( int row=section-1; row>0; row--) {
                cout << setw( numberOfSections - row + 1) << "("; // Left section up to '('
                cout << setw( (row * 2) + 2) << ")";              // Right section up to ')'
                cout << endl;
            } //end for( int row...
            
        } //end for( int section = 1 ...
        
        // Display the bottom row
        cout << setw(numberOfSections + 3) << "---" << endl;
        
        // Display the stem, which has alternating leaves equal to the number of flowers.
        for( int section = 1; section <= numberOfSections; section++) {
            // Display stem to the right for odd numbered sections, to the left for even stem sections
            if( (section % 2) == 1) {
                cout << setw(numberOfSections + 3) << "|/" << endl; // Odd numbered section
            }
            else {
                cout << setw(numberOfSections + 2) << "\\|" << endl; // Even numbered section. To print '\' use "\\"
            }
            cout << setw(numberOfSections + 2) << "|" << endl;
        }// end for( int section = 1 ...
        
    } //end if( menuOption == 2) // menu option to display building
            
    cout << "Exiting" << endl;
    return 0;
}// end main()
