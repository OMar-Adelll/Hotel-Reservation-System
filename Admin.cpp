#include <bits/stdc++.h>
#include "Person.h"
#include "Customer.h"
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

        cout << "Enter Password: ";
        string password;
        getline(cin, password);

        cout << "Enter Gender: ";
        string gender;
        getline(cin, gender);

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
        set_System_ID(); // System_ID can be set internally or generated
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

    bool remove_customer(const string &ID_to_remove)
    {
        ifstream fin("Customers_data.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading!" << endl;
            return false;
        }

        vector<string> lines;
        string line;

        bool found = false;
        while (getline(fin, line))
        {
            string current_title = line.substr(0, line.find(','));

            if (current_title != ID_to_remove)
            {
                lines.push_back(line);
            }
            else
            {
                found = true;
            }
        }
        fin.close();

        if (!found)
        {
            cout << "Customer with ID \"" << ID_to_remove << "\" not found.\n\n";
            return false;
        }

        ofstream fout("Customers_data.csv");
        if (!fout)
        {
            cerr << "Error opening file for writing!\n\n";
            return false;
        }

        for (const string &remaining_line : lines)
        {
            fout << remaining_line << endl;
        }
        fout.close();
        for (auto it = all_customers.begin(); it != all_customers.end(); it++)
        {
            if (it->get_System_ID() == stoi(ID_to_remove))
            {
                all_customers.erase(it);
                break;
            }
        }
        cout << "Customer with ID \"" << ID_to_remove << "\" successfully removed.\n\n";
        return true;
    }

    // void search_customer(){}

    // void show_all_customers(){}

    // void all_available_rooms(){}

    // void all_reserved_rooms(){}

    // void show_hotel_data(){}
};
vector<admin> all_admins;

void admins_in_the_system()
{
    string line;
    ifstream fin("admins_in_the_system.csv");
    bool header = true;
    while (getline(fin, line))
    {
        if (header)
        {
            header = false;
            continue;
        }
        admin ad;
        stringstream ss(line);

        string id, name, password, gender, age, national_id, email, phone, address;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, password, ',');
        getline(ss, gender, ',');
        getline(ss, age, ',');
        getline(ss, national_id, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');
        getline(ss, address, ',');
        ad.set_System_ID();
        ad.set_Name(name);
        ad.set_Password(password);
        ad.set_Gender(gender);
        ad.set_Age(stoi(age));
        ad.set_National_ID(national_id);
        ad.set_Email(email);
        ad.set_Phone(phone);
        ad.set_Address(address);
        ad.set_Name(name);

        all_admins.push_back(ad);
    }
    fin.close();
}
