#include <bits/stdc++.h>
#include "Person.h"
#include "Customer.h"
#include "Room.h"
#include "Date.cpp"
#include "Safe_Input.cpp"
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

    void search_customer()
    {
        cout << "Enter Customer System ID to search: ";
        string search_id;
        getline(cin, search_id);

        bool found = false;
        for (auto &customer : all_customers)
        {
            if (customer.get_System_ID() == stoi(search_id))
            {
                cout << "\nCustomer data:\n";
                cout << "Name: " << customer.get_Name() << endl;
                cout << "Password: " << customer.get_Password() << endl;
                cout << "National ID: " << customer.get_National_ID() << endl;
                cout << "Gender: " << customer.get_Gender() << endl;
                cout << "Age: " << customer.get_Age() << endl;
                cout << "Email: " << customer.get_Email() << endl;
                cout << "Phone: " << customer.get_Phone() << endl;
                cout << "Address: " << customer.get_Address() << endl;
                cout << "System ID: " << customer.get_System_ID() << "\n\n";
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Customer with System ID \"" << search_id << "\" not found.\n\n";
        }
    }

    void show_all_customers()
    {
        cout << "All Customers in the System:\n";
        cout << string(80, '-') << endl;
        cout << left << setw(15) << "Name"
             << setw(15) << "Password"
             << setw(15) << "National ID"
             << setw(10) << "Gender"
             << setw(5) << "Age"
             << setw(20) << "Email"
             << setw(15) << "Phone"
             << setw(25) << "Address"
             << setw(10) << "System ID" << endl;
        cout << string(80, '-') << endl;
        for (auto &customer : all_customers)
        {
            cout << left << setw(15) << customer.get_Name()
                 << setw(15) << customer.get_Password()
                 << setw(15) << customer.get_National_ID()
                 << setw(10) << customer.get_Gender()
                 << setw(5) << customer.get_Age()
                 << setw(20) << customer.get_Email()
                 << setw(15) << customer.get_Phone()
                 << setw(25) << customer.get_Address()
                 << setw(10) << customer.get_System_ID() << endl;
        }
        cout << string(80, '-') << "\n\n";
    }

    void all_available_rooms()
    {
        cout << "Available Rooms in the System:\n";
        cout << string(80, '-') << endl;
        cout << left << setw(10) << "Room No."
             << setw(10) << "Price"
             << setw(10) << "Floor"
             << setw(10) << "Beds"
             << setw(15) << "Hotel ID"
             << setw(15) << "Type"
             << setw(15) << "Status" << endl;
        cout << string(80, '-') << endl;
        for (auto &room : all_rooms)
        {
            if (room.get_roomStatus() == RoomStatus::Available)
            {
                cout << left << setw(10) << room.get_roomNumber()
                     << setw(10) << room.get_roomPrice()
                     << setw(10) << room.get_roomFloor()
                     << setw(10) << room.get_roomBeds()
                     << setw(15) << room.get_hotelID()
                     << setw(15) << room.getRoomTypeString()
                     << setw(15) << room.getRoomStatusString() << endl;
            }
        }
        cout << string(80, '-') << "\n\n";
    }

    void all_reserved_rooms()
    {
        cout << "Reserved Rooms in the System:\n";
        cout << string(80, '-') << endl;
        cout << left << setw(10) << "Room No."
             << setw(10) << "Price"
             << setw(10) << "Floor"
             << setw(10) << "Beds"
             << setw(15) << "Hotel ID"
             << setw(15) << "Type"
             << setw(15) << "Status"
             << setw(15) << "Check-in"
             << setw(15) << "Check-out" << endl;
        cout << string(80, '-') << endl;
        for (auto &room : all_rooms)
        {
            if (room.get_roomStatus() == RoomStatus::Booked)
            {
                cout << left << setw(10) << room.get_roomNumber()
                     << setw(10) << room.get_roomPrice()
                     << setw(10) << room.get_roomFloor()
                     << setw(10) << room.get_roomBeds()
                     << setw(15) << room.get_hotelID()
                     << setw(15) << room.getRoomTypeString()
                     << setw(15) << room.getRoomStatusString();
                // Maybe the foramat of date should be changed to fit in the table
                room.get_checkIn().display();
                room.get_checkOut().display();
            }
        }
        cout << string(80, '-') << "\n\n";
    }

    // void show_hotel_data()
    // {
    //     cout << "Hotel Data:\n\n";
    //     cout << string(30, '-') << endl;
    //     cout << left << setw(20) << "Hotel Name"
    //          << setw(10) << "Hotel ID"
    //          << setw(10) << "Stars"
    //          << setw(15) << "Rooms Count"
    //          << setw(15) << "Customers Count"
    //          << setw(25) << "Email"
    //          << setw(15) << "Phone"
    //          << setw(30) << "Address"
    //          << setw(30) << "Description" << endl;
    //     cout << string(30, '-') << endl;
    // }
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

        all_admins.push_back(ad);
    }
    fin.close();
}

void admin_menu(admin &ad)
{
    cout << "\nHello " << ad.get_Name() << " | Admin view\n";
    while (true)
    {
        cout << "Menu:\n";
        cout << "1. View Profile\n";
        cout << "2. Show All Customers\n";
        cout << "3. Search Customer by System ID\n";
        cout << "4. Remove Customer by System ID\n";
        cout << "5. Update Room Data\n";
        cout << "6. Show All Available Rooms\n";
        cout << "7. Show All Reserved Rooms\n";
        cout << "8. Add Admin\n";
        cout << "9. Logout\n";
        cout << "Enter your choice: ";
        int choice = safe_int(1, 9);
        if (choice == 1)
        {
            ad.view_profile();
        }
        else if (choice == 2)
        {
            ad.show_all_customers();
        }
        else if (choice == 3)
        {
            ad.search_customer();
        }
        else if (choice == 4)
        {
            cout << "Enter Customer System ID to remove: ";
            string id_to_remove;
            getline(cin, id_to_remove);
            ad.remove_customer(id_to_remove);
        }
        else if (choice == 5)
        {
            // ad.update_room_data();
            cout << "Feature under development.\n\n";
        }
        else if (choice == 6)
        {
            ad.all_available_rooms();
        }
        else if (choice == 7)
        {
            ad.all_reserved_rooms();
        }
        else if (choice == 8)
        {
            admin new_admin;
            new_admin.read();
            all_admins.push_back(new_admin);
            ofstream fout("admins_in_the_system.csv", ios::app);
            fout << new_admin.get_System_ID() << ","
                 << new_admin.get_Name() << ","
                 << new_admin.get_Password() << ","
                 << new_admin.get_Gender() << ","
                 << new_admin.get_Age() << ","
                 << new_admin.get_National_ID() << ","
                 << new_admin.get_Email() << ","
                 << new_admin.get_Phone() << ","
                 << new_admin.get_Address() << "\n";

            cout << "New admin added successfully.\n\n";
        }
        else if (choice == 9)
        {
            cout << "Logging out...\n\n";
            break;
        }
    }
}