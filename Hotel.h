#ifndef HOTEL_H
#define HOTEL_H

#include <bits/stdc++.h>
#include "ID.h"
#include "Rooms_category.h"
using namespace std;
class Hotel : public ID
{
    string hotelName;
    int stars;
    int roomsCount;
    int customersCount;
    string description;
    map<RoomType, map<int, Room1 *>> Rooms; // (roomtype , (Id , room1))
    map<int, Room1 *> RoomsByNumber;        // (roomNumber , room1)

public:
    Hotel() : ID(Object::Hotel)
    {
        hotelName = "";
        stars = 0;
        roomsCount = 0;
        customersCount = 0;
        this->description =
            "A hotel is an establishment that provides lodging, comfort, and services to travelers and guests. "
            "It usually offers furnished rooms, housekeeping, and additional amenities such as dining, reception, "
            "and recreation. Its main purpose is to ensure a safe, pleasant, and convenient stay for people away from home.";
    }

    Hotel(const string &name, int starRating = 0)
        : ID(Object::Hotel), hotelName(name), stars(starRating), roomsCount(0), customersCount(0),
          description("A hotel is an establishment that provides lodging, comfort, and services to travelers and guests. "
                      "It usually offers furnished rooms, housekeeping, and additional amenities such as dining, reception, "
                      "and recreation. Its main purpose is to ensure a safe, pleasant, and convenient stay for people away from home.")
    {
    }

    // -- functions -- //
    string getHotelName() const { return hotelName; }
    int getStars() const { return stars; }
    int getRoomsCount() const { return roomsCount; }
    int getCustomersCount() const { return customersCount; }
    string getDescription() const { return description; }

    void setHotelName(const string &name) { hotelName = name; }
    void setStars(int s) { stars = s; }
    void setCustomersCount(int count) { customersCount = count; }
    void setDescription(const string &desc) { description = desc; }

    void build_Room(int roomNumber, RoomType t) // roomNumber required because it's essential thing when you intialize new room it (room number, type)
    {
        Room1 *r = new Room1(roomNumber, t);
        const int id = r->getID();
        Rooms[t][id] = r;
        RoomsByNumber[roomNumber] = r;
        roomsCount++;
    }

    void addRoom(const Room1 &other)
    {
        Room1 *r = new Room1(other.getRoomNumber(), other.getRoomType());
        const int id = r->getID();
        Rooms[other.getRoomType()][id] = r;
        RoomsByNumber[other.getRoomNumber()] = r;
        roomsCount++;
    }

    bool foundRoom(Room1 other) // search with Room
    {
        RoomType type = other.getRoomType();
        const int id = other.getID();
        auto it = Rooms[type].find(id);
        if (it != Rooms[type].end())
            return true;
        return false;
    }

    bool foundRoom(int roomNumber) // search with Room number
    {
        auto it = RoomsByNumber.find(roomNumber);
        if (it != RoomsByNumber.end())
            return true;
        return false;
    }

    void deleteRoom(Room1 other)
    {
        if (!foundRoom(other))
            return void(cout << "This Room is Not Found !" << nl);
        RoomType type = other.getRoomType();
        const int id = other.getID();
        int roomNumber = other.getRoomNumber();
        Rooms[type].erase(id);
        RoomsByNumber.erase(roomNumber);
        roomsCount--;
    }

    void deleteRoom(int roomNumber) // delete with room number
    {
        if (!foundRoom(roomNumber))
            return void(cout << "This Room isn't Found !" << nl);
        Room1 *r = RoomsByNumber[roomNumber];
        RoomType type = r->getRoomType();
        const int id = r->getID();
        Rooms[type].erase(id);
        RoomsByNumber.erase(roomNumber);
        roomsCount--;
    }

    void displayRoomsList()
    {
        if (roomsCount == 0)
        {
            cout << "No rooms available in this hotel.\n";
            return;
        }

        cout << left << setw(10) << "ID"
             << setw(12) << "Number"
             << setw(12) << "Type"
             << setw(12) << "Status" << "\n";

        cout << string(46, '-') << "\n";

        for (auto &typeGroup : Rooms)
        {
            for (auto &roomPair : typeGroup.second)
            {
                Room1 *room = roomPair.second;

                cout << left
                     << setw(10) << room->getID()
                     << setw(12) << room->getRoomNumber()
                     << setw(12) << room->getRoomType()
                     << setw(12) << room->getRoomStatus()
                     << "\n";
            }
        }
    }
    Room1 *findRoomByNumber(int roomNumber)
    {
        auto it = RoomsByNumber.find(roomNumber);
        if (it != RoomsByNumber.end())
            return it->second;
        return nullptr;
    }

    ~Hotel()
    {
        for (auto &typeGroup : Rooms)
        {
            for (auto &roomPair : typeGroup.second)
                delete roomPair.second;
            typeGroup.second.clear();
        }
        Rooms.clear();
    }
};

#endif