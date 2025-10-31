#include <bits/stdc++.h>
#include "Person.cpp"
#include <Customer.cpp>
#include "Room.cpp"
#define sp " "
#define nl '\n'
using namespace std;

class Hotel
{
private:
    string hotelName;
    int hotelId;
    int stars;
    int roomsCount;
    int customersCount;
    string email;
    string phone;
    string address;
    string description;
    map<int, Room> rooms;

public:
    Hotel()
    {
        this->hotelName = "NULL";
        this->hotelId = 0;
        this->stars = 1;
        this->roomsCount = 0;
        this->customersCount = 0;
        this->email = "..@gmail.com";
        this->phone = "+44-7xxx-xxx-xxx";
        this->address = "Null";
        this->description = "Null";
    }

    //--- Setters ---//
    void set_hotelName(string hotelName) { this->hotelName = hotelName; }
    void set_hotelId(int hotelId) { this->hotelId = hotelId; }
    void set_stars(int stars) { this->stars = stars; }
    void set_roomsCount(int roomsCount) { this->roomsCount = roomsCount; }
    void set_customersCount(int customersCount) { this->customersCount = customersCount; }
    void set_email(string email) { this->email = email; }
    void set_phone(string phone) { this->phone = phone; }
    void set_address(string address) { this->address = address; }
    void set_description(string description) { this->description = description; }

    //--- Getters ---//
    string get_hotelName() { return this->hotelName; }
    int get_hotelId() { return this->hotelId; }
    int get_stars() { return this->stars; }
    int get_roomsCount() { return this->roomsCount; }
    int get_customersCount() { return this->customersCount; }
    string get_email() { return this->email; }
    string get_phone() { return this->phone; }
    string get_address() { return this->address; }
    string get_description() { return this->description; }

    //--- rooms ---//
    void addRoom(Room r)
    {
        int RoomNumber = r.get_hotelID();
        if (rooms.find(RoomNumber) != rooms.end())
        {
            cout << "This room already exists in the hotel!" << nl;
            return;
        }
        rooms[RoomNumber] = r;
        r.set_hotelID(this->hotelId);
        this->roomsCount++;

        cout << "Room #" << RoomNumber << " added successfully." << nl;
    }

    void display()
    {
        cout << "Hotel Name: " << hotelName << nl;
        cout << "Hotel ID: " << hotelId << nl;
        cout << "Stars: " << stars << nl;
        cout << "Rooms Count: " << roomsCount << nl;
        cout << "Customers Count: " << customersCount << nl;
        cout << "Email: " << email << nl;
        cout << "Phone: " << phone << nl;
        cout << "Address: " << address << nl;
        cout << "Description: " << description << nl;
    }
};