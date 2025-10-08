#include <bits/stdc++.h>
#define sp " "
using namespace std;

int safe_input_int(int min, int max)
{
    int choice;
    while (true)
    {
        cin >> choice;
        if (cin.fail())
        {
            cout << "Invalid input! Expected an integer.\n";
            cout << "Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (choice < min || choice > max)
        {
            cout << "Out of range, please try again.\n";
            cout << "Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        return choice;
    }
}