/*
* Main.cpp
*
* Date: November 10, 2021
* Author: Tim Brady
*
*/


///////////////////////////////////////////////////
//FIX ME: Increment ceilings
///////////////////////////////////////////////////

#include "clock.h"
#include <Windows.h>

void display(Clock clock);
int menu();

int main()
{
    // declare time variables and prompt the user to enter their current time
    int mhour = 0;
    int mminute = 0;
    int msecond = 0;

    // hours
    cout << "Please enter the current hour: " << endl;
    cin >> mhour;
    while (mhour > 23 || mhour < 0) {
        cout << "Please enter a valid hour: " << endl;
        cin >> mhour;
    }

    // minutes
    cout << "Please enter the current minutes: " << endl;
    cin >> mminute;
    while (mminute > 59 || mminute < 0) {
        cout << "Please enter a valid minute: " << endl;
        cin >> mminute;
    }
  
    // seconds
    cout << "Please enter the current seconds: " << endl;
    cin >> msecond;
    while (msecond > 59 || msecond < 0) {
        cout << "Please enter a valid second: " << endl;
        cin >> msecond;
    }

    // create clock object and display
    Clock clock(mhour, mminute, msecond);
    system("cls"); // clear the screen of the prompts for input
        display(clock);
        // display menu
        int opt = menu();
        // display menu until user exits
        while (opt != 4) {
            // menu options
            if (opt == 1) {
                clock.incrementHour();
            }
            else if (opt == 2) {
                clock.incrementMinute();
            }
            else if (opt == 3) {
                clock.incrementSecond();
            }

            // clear screen and display new on input
            system("cls");
            display(clock);
            opt = menu();
        }
    return 0;
}
    
