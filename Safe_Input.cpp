#include <bits/stdc++.h>
#define sp " "
using namespace std;

int safe_int(int min, int max)
{
    int choice;
    while (true)
    {
        cin >> choice;
        if (cin.fail())
        {
            cout << "Invalid input. Please enter a valid number.\n";
            cout << "Enter a number between " << min << " and " << max << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (choice < min || choice > max)
        {
            cout << "Choice out of range. Please select a number between \n"
                 << min << " and " << max << "." << endl;
            cout << "Try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return choice;
    }
}