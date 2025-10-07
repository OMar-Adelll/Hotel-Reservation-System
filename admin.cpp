#include <bits/stdc++.h>
#include "Person.cpp"
#define sp " "
using namespace std;

class admin : public Person
{
public:
    admin() : Person() {}
    void read()
    {
        cout << "Enter name: ";
        string name;
        getline(cin, name);

        cout << "Enter Passsword: ";
        string password;
        getline(cin, password);

        cout << "Enter Gender: ";
        string gender;
        getline(cin,gender);

        cout << "Enter Age: ";
        int age;
        cin >> age;
        cin.ignore(); // To ignore the newline character after reading age

        cout << "Enter National_ID: ";
        string national_id;
        getline(cin, national_id);

        cout << "Enter Email: ";
        string email;
        getline(cin, email);

        cout << "Enter Phone Number: ";
        string phone;
        getline(cin, phone);

        cout << "Enter Address: ";
        string address;
        getline(cin, address);

        set_Name(name);
        set_Password(password);
        set_Gender(gender);
        set_Age(age);
        set_National_ID(national_id);
        set_Email(email);
        set_Phone(phone);
        set_Address(address);
        // set_System_ID(); // System_ID can be set internally or generated
    }

    void view_profile()
    {
        cout << endl;
        cout << "Name: " << get_Name() << endl;
        cout << "Password: " << get_Password() << endl;
        cout << "Gender: " << get_Gender() << endl;
        cout << "Age: " << get_Age() << endl;
        cout << "National_ID: " << get_National_ID() << endl;
        cout << "Email: " << get_Email() << endl;
        cout << "Phone Number: " << get_Phone() << endl;
        cout << "Address: " << get_Address() << endl;
        cout << "System_ID: " << get_System_ID() << "\n\n";
    }

    // void update_room_data(){}

    //void delete_customer(){}

    // void search_customer(){}

    // void show_all_customers(){}

    // void all_available_rooms(){}

    // void all_reserved_rooms(){}

    // void show_hotel_data(){}

};
