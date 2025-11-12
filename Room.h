#include <bits/stdc++.h>
#include "Date.cpp"
using namespace std;

#define nl '\n'

enum class RoomStatus
{
    Available,
    Booked,
    UnderMaintenance
};

enum class RoomType
{
    Single,
    Double,
    Twin,
    Deluxe,
    Suite,
    Family
};

class Room
{
private:
    int roomNumber;
    double roomPrice;
    int roomFloor;
    int roomBeds;
    int hotelID;
    RoomType roomType;
    RoomStatus roomStatus;
    date checkIn;
    date checkOut;

public:
    Room()
    {
        this->roomNumber = 0;
        this->roomPrice = 0.0;
        this->roomFloor = 0;
        this->roomBeds = 1;
        this->hotelID = 0;
        this->roomType = RoomType::Single;
        this->roomStatus = RoomStatus::Available;
        this->checkIn = date();
        this->checkOut = date();
    }

    Room(int number, double price, int floor, int beds, int hotelId,
         RoomType type, RoomStatus status = RoomStatus::Available)
    {
        this->roomNumber = number;
        this->roomPrice = price;
        this->roomFloor = floor;
        this->roomBeds = beds;
        this->hotelID = hotelId;
        this->roomType = type;
        this->roomStatus = status;
        this->checkIn = date();
        this->checkOut = date();
    }

    // ------------------- Setters & Getters ------------------- //

    // 1. room number
    void set_roomNumber(int roomNumber)
    {
        this->roomNumber = roomNumber;
    }
    int get_roomNumber()
    {
        return this->roomNumber;
    }

    // 2. room price
    void set_roomPrice(double roomPrice)
    {
        this->roomPrice = roomPrice;
    }
    double get_roomPrice()
    {
        return this->roomPrice;
    }

    // 3. room floor
    void set_roomFloor(int roomFloor)
    {
        this->roomFloor = roomFloor;
    }
    int get_roomFloor()
    {
        return this->roomFloor;
    }

    // 4. room beds
    void set_roomBeds(int roomBeds)
    {
        this->roomBeds = roomBeds;
    }
    int get_roomBeds()
    {
        return this->roomBeds;
    }

    // 5. hotel ID
    void set_hotelID(int hotelID)
    {
        this->hotelID = hotelID;
    }
    int get_hotelID()
    {
        return this->hotelID;
    }

    // 6. room type
    void set_roomType(RoomType roomType)
    {
        this->roomType = roomType;
    }
    RoomType get_roomType()
    {
        return this->roomType;
    }

    // 7. room status
    void set_roomStatus(RoomStatus roomStatus)
    {
        this->roomStatus = roomStatus;
    }
    RoomStatus get_roomStatus()
    {
        return this->roomStatus;
    }

    // 8. check-in date
    void set_checkIn(const date &checkIn)
    {
        this->checkIn = checkIn;
    }
    date get_checkIn()
    {
        return this->checkIn;
    }

    // 9. check-out date
    void set_checkOut(const date &checkOut)
    {
        this->checkOut = checkOut;
    }
    date get_checkOut()
    {
        return this->checkOut;
    }

    // ------------------- Display ------------------- //
    void displayInfo() const
    {
        cout << "Room #" << roomNumber << nl;
        cout << "Hotel ID: " << hotelID << nl;
        cout << "Floor: " << roomFloor << nl;
        cout << "Beds: " << roomBeds << nl;
        cout << "Price per night: $" << fixed << setprecision(2) << roomPrice << nl;
        cout << "Type: " << getRoomTypeString() << nl;
        cout << "Status: " << getRoomStatusString() << nl;
        cout << "Check-in: ";
        checkIn.display();
        cout << "Check-out: ";
        checkOut.display();
        cout << string(40, '-') << nl;
    }

    
    string getRoomTypeString() const // to see type as a string
    {
        switch (roomType)
        {
        case RoomType::Single:
            return "Single";
        case RoomType::Double:
            return "Double";
        case RoomType::Twin:
            return "Twin";
        case RoomType::Deluxe:
            return "Deluxe";
        case RoomType::Suite:
            return "Suite";
        case RoomType::Family:
            return "Family";
        default:
            return "Unknown";
        }
    }

    string getRoomStatusString() const // to see status as a string
    {
        switch (roomStatus)
        {
        case RoomStatus::Available:
            return "Available";
        case RoomStatus::Booked:
            return "Booked";
        case RoomStatus::UnderMaintenance:
            return "Under Maintenance";
        default:
            return "Unknown";
        }
    }
};
vector<Room> all_rooms; // Global vector to store all rooms
