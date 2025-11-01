// بسم الله الرحمن الرحيم
//  وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ

#ifndef PERSON_H
#define PERSON_H

#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    /*--Identity information--*/
    string National_ID; // The ID number printed on a person's national identification card
    string Name;
    string Gender;
    int Age;
    string Nationality;

    /*--contact information--*/
    string Address;
    string Email;
    string Phone;

    /*--system information--*/

    int System_ID; // Unique identifier assigned by the hotel system for internal tracking
    string Password;

public:
    static int nextId;
    Person() // empty constructor
    {
        this->National_ID = "Null";
        this->Name = "Null";
        this->Gender = "Null";
        this->Age = 0;
        this->Nationality = "Null";

        this->Address = "Null";
        this->Email = "Null";
        this->Phone = "Null";

        set_System_ID();
        this->Password = "Null";
    }

    Person(string National_ID, string Name, string Gender, int Age, string Nationality,
           string Address, string Email, string Phone, int System_ID, string Password) // Parametrize constructor
    {
        this->National_ID = National_ID;
        this->Name = Name;
        this->Gender = Gender;
        this->Age = Age;
        this->Nationality = Nationality;

        this->Address = Address;
        this->Email = Email;
        this->Phone = Phone;

        this->System_ID = System_ID;
        this->Password = Password;
    }

    /*--Setters and Getters--*/

    // 1- National ID
    void set_National_ID(string Set_National_ID)
    {
        this->National_ID = Set_National_ID; // Corrected: Should use the parameter Set_National_ID
    }
    string get_National_ID()
    {
        return this->National_ID;
    }

    // 2- Name
    void set_Name(string Set_Name)
    {
        this->Name = Set_Name;
    }
    string get_Name()
    {
        return this->Name;
    }

    // 3- Gender
    void set_Gender(string Set_Gender)
    {
        this->Gender = Set_Gender;
    }
    string get_Gender()
    {
        return this->Gender;
    }

    // 4- Age
    void set_Age(int Set_Age)
    {
        this->Age = Set_Age;
    }
    int get_Age()
    {
        return this->Age;
    }

    // 5- Nationality
    void set_Nationality(string Set_Nationality)
    {
        this->Nationality = Set_Nationality;
    }
    string get_Nationality()
    {
        return this->Nationality;
    }

    // 6- Address
    void set_Address(string Set_Address)
    {
        this->Address = Set_Address;
    }
    string get_Address()
    {
        return this->Address;
    }

    // 7- Email
    void set_Email(string Set_Email)
    {
        this->Email = Set_Email;
    }
    string get_Email()
    {
        return this->Email;
    }

    // 8- Phone
    void set_Phone(string Set_Phone)
    {
        this->Phone = Set_Phone;
    }
    string get_Phone()
    {
        return this->Phone;
    }

    // 9- System ID
    void set_System_ID()
    {
        this->System_ID = ++nextId;
    }
    int get_System_ID()
    {
        return this->System_ID;
    }

    // 10- Password
    void set_Password(string Set_Password)
    {
        this->Password = Set_Password;
    }
    string get_Password()
    {
        return this->Password;
    }
};

int Person::nextId = 0;

#endif