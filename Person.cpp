// بسم الله الرحمن الرحيم
//  وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ

#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    /*--Identity information--*/
    int National_ID; // The ID number printed on a person's national identification card
    string Name;
    string Gender;
    int Age;
    string Nationality;

    /*--contact information--*/
    string Address;
    string Email;
    string Phone;

    /*--system information--*/
    string System_ID; // Unique identifier assigned by the hotel system for internal tracking
    string Password;
};