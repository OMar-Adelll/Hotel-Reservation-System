#ifndef HOTEL_H
#define HOTEL_H

#include <bits/stdc++.h>
#include "ID.h"
#include "Rooms_category.h"
using namespace std;
class Hotel : public ID
{
    string hotelName;
    int roomsCount;
    int customersCount;
    string description;
    Rooms_category reservedRooms;
    Rooms_category nonReservedRooms;

public:
    Hotel() : ID(Object::Hotel)
    {
        this->hotelName = "";
        this->customersCount = 0;
        this->description =
            "A hotel is an establishment that provides lodging, comfort, and services to travelers and guests. "
            "It usually offers furnished rooms, housekeeping, and additional amenities such as dining, reception, "
            "and recreation. Its main purpose is to ensure a safe, pleasant, and convenient stay for people away from home.";
    }

    Hotel(string name, int totalRooms) : ID(Object::Hotel)
    {
        this->hotelName = name;
        this->customersCount = totalRooms;
    }

    Hotel(string name) : ID(Object::Hotel)
    {
        this->hotelName = name;
    }

    // -- functions -- //
    void reNameHotel(string name)
    {
        this->hotelName = name;
    }

    string getHotelName()
    {
        return this->hotelName;
    }

    string display_desctiption()
    {
        return this->description;
    }
};

#endif