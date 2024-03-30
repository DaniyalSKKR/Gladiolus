#include <iostream>
#include <iomanip>
using namespace std;

// Essay
//Name: Daniyal Khokhar
//Professor: Ellen Kidane
/* The program solution in comparison to my code is essentially more concise, containing a cleaner style of organization
 * and providing clear details as to which segment of code translates to whatever function/procedure that will be
 * executed as a result. Starting with the original graphic, I implemented the simple printing of spaces and characters
 * followed by an "endl" to indicate when the next line of the graphic would begin. The spacing to make sure the entire
 * graphic was properly aligned was done through this simple method of adding spaces within quotations. The provided
 * program solution code differed in its characteristics of displaying the graphic, using the function "setw()" to
 * establish set lengths of spaces that the characters that would comprise the graphic of would consume those empty
 * spaces from the right-hand side. Furthermore, newlines were added to the end of each line of the grpahic design to
 * simplify the procedure. The horizontal lines above and below the graphic were printed using a loop from the solution
 * code, which I feel is effective for enormous amounts of repeating characters, but I felt simply printing them within
 * one line of quotations would do the job for this particular case. For the main code, my code consisted more of "for"
 * loops to indicate placement of specific characters and to establish set patterns through nested loop counters. I
 * think that the solution code's use of "setw()" to formulate the pattern of presenting the progressively increasing
 * size of the gladiolus is a much more effective, clean, and easier way to code the objective of this assignment. My
 * code will print spaces until the appropriate length at which a parentheses will be display after the for loop. The
 * solution code differs in setting the distance that the parentheses will be placed in accordance to how the "setw()"
 * function changes upon the increasing sizes of the sections. This process appears to be more effective considering it
 * takes less lines of code, avoids confusion of addition curly braces, and creates a straight-forward technique to
 * affirm certain points of the gladiolus will hold the "petals" in the correct locations. I was unable to understand
 * how to place the center of the flower on each section, unaware that the center could be a separate segment of code,
 * isolated from the upper portion of a flower section. This is a portion of code a implemented directly from the
 * solution. The code that correlates to displaying the bottom portion of the flower follows the same procedure as the
 * upper portion of the flower. A for loop is used to place spaces before the parentheses with the limit of the counter
 * relying upon the changes in the rows variable and over all size that the user inputs. Finally, the flower stem
 * possesses a similar for loop that will establish a set distance of spaces followed by the components of the flower
 * stalk. I felt that changing the second possible option for the flower stalk was redundant considering the solution
 * code's use of the "setw()" function was much more simple and condensed. The if statements that provide the 3 options
 * for the user remain exactly the same as I had originally incorporated. The developer of the solution found that the
 * if statements were also satisfactory in providing the options, rather than relying on switch cases.
 *
 */

int main() {
    cout << "Program 1: Gladiolus            " << endl;
    cout     << "Choose from among the following options:  " << endl;
    cout     << "   1. Display original graphic  " << endl;
    cout     << "   2. Display Gladiolus         " << endl;
    cout     << "   3. Exit the program          "<< endl;
    cout     << "Your choice -> ";
    int choice;
    cin >> choice;
    //Original Graphic
    if(choice == 1){
        cout << "_____________________________________" << endl;
        cout << " " << " ______       ___        __          " << endl;
        cout << " " << " |      \\      /  \\       | \\    | " << endl;
        cout << " " << " |       \\    /____\\      |  \\   |   " << endl;
        cout << " " << " |       //  //    \\      |   \\  |   " << endl;
        cout << " " << " |      //  //      \\     |    \\ |  " << endl;
        cout << " " << " |_____//  //        \\    |     \\|  " << endl;
        cout << "_____________________________________" << endl;
        cout << endl;
        cout << "Exiting" << endl;
    }

    else if(choice == 2) {
        cout << "Number of sections ->";
        int theSize;
        cin >> theSize;
// Code will add sections until the total input size is reached
        cout << setw(theSize + 4) << "---" << endl;
        for (int section = 1; section <= theSize; section++) {
            // Determines the number of rows that are printed per section
            //The number of sections (i) will increase until it reaches theSize
            //Then the rows will increase until it reaches the point where (i) stops
            for (int rows = 0; rows < (section - 1); rows++) {
                for (int i = 0; i < (theSize - rows - 1); i++) {
                    cout << " ";
                }
                cout << "(";
                for (int j = 0; j < ((rows * 2) + 3); j++) {
                    cout << " ";
                }
                cout << ")" << endl;
            }

            // 2. Display the single middle row for this flower section, containing "@"
            cout << setw(theSize - section + 1) << "("; // Left section up to '('
            cout << setw(section + 1) << "@";                    // Middle section with '@'
            cout << setw(section + 1) << ")" << endl;            // Right section up to ')'

            // Contains code that will print bottom section of flower
            for (int rows = section - 1; rows > 0; rows--) {
                for (int i = 0; i < (theSize - rows); i++) {
                    cout << " ";
                }
                cout << "(";
                for (int j = 0; j < ((rows * 2) + 1); j++) {
                    cout << " ";
                }
                cout << ")";
                cout << endl;
            }

            cout << setw(theSize + 3) << "---" << endl;
        }
        for (int section = 1; section <= theSize; section++) {
            // Display stem to the right for odd numbered sections, to the left for even stem sections
            if ((section % 2) == 1) {
                // The stem remains a consistent vertical line, therefore theSize will act as the termination point to the for loop
                for(int k = 0; k<=theSize; k++) {
                    cout << " ";
                }
                cout << "|/" << endl;

            } else {
                for(int z = 0; z<=theSize-1; z++) {
                    cout << " ";
                }
                cout << "\\|" << endl;
            }
            cout << setw(theSize + 2) << "|" << endl;
        }
        cout << "Exiting" << endl;
    }
    else if(choice == 3) {
        cout << "Exiting" << endl;
        return 0;
    }
}