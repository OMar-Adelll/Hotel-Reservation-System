#include <bits/stdc++.h>
#include "Admin.cpp"
#include "Safe_Input.cpp"
#include "Customer.h"
#include "Person.h"
using namespace std;
#define nl '\n'

void Welcome()
{
    cout << nl << "=======================================" << nl;
    cout << "Welcome to Hotel Reservation System" << nl;
    cout << "=======================================" << nl;
    cout << "1. Customer - Reserve Online" << nl;
    cout << "2. Admin - Manage / Reserve Offline" << nl;
    cout << "3. Exit" << nl;
    cout << "---------------------------------------" << nl;
    cout << "Enter your choice: ";
}
void exitMessage()
{
    cout << endl;
    cout << "==========================================" << endl;
    cout << "       Thank You for Using Our System     " << endl;
    cout << "==========================================" << endl;
    cout << "We appreciate your time and hope you had a" << endl;
    cout << "pleasant experience using our application." << endl;
    cout << "------------------------------------------" << endl;
    cout << "     Goodbye and have a wonderful day!     " << endl;
    cout << "==========================================" << endl;
    cout << endl;
}
int main()
{
    Welcome();

    int choice = safe_int(1, 3);
    switch (choice)
    {
    case 1:
        cout << "Customer menu will Open... " << nl;
        // customer menu
        break;
    case 2:
        cout << "Admin menu will Open... " << nl;
        // admin menu
        break;
    case 3:
        exitMessage();
    default:
        break;
    }

    return 0;
}