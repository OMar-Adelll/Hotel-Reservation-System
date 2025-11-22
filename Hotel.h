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
    map<RoomType, vector<Room1 *>> roomsByType;

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

    void build_Room(int roomNumber, RoomType t)
    {
        Room1 *r = new Room1(roomNumber, t);
        roomsByType[t].push_back(r);
        roomsCount++;
    }

    void addRoom(const Room1 &other)
    {
        Room1 *r = new Room1(other.getRoomNumber(), other.getRoomType());
        roomsByType[other.getRoomType()].push_back(r);
        roomsCount++;
    }

    bool foundRoom()
    {
        // TODO
    }

    void deleteRoom()
    {
        // TODO
    }

    void displayRoomsList()
    {
        // TODO
    }

    ~Hotel()
    {
        for (auto &free : roomsByType)
            for (auto &room : free.second)
                delete room;
    }
};

#endif