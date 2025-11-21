#ifndef ROOMS_CATEGORY_H
#define ROOMS_CATEGORY_H
#include <bits/stdc++.h>
using namespace std;
class Rooms_category
{
private:
    map<int, string> rooms;

public:
    Rooms_category(){}

    bool hasRoom(int roomNumber) const
    {
        return rooms.find(roomNumber) != rooms.end();
    }

    void addRoom(int roomNumber, const string &type, bool status = true)
    {
        if (status)
        {
            rooms[roomNumber] = type;
        }
    }

    void deleteRoom(int roomNumber, bool status = true)
    {
        if (status)
        {
            rooms.erase(roomNumber);
        }
    }

    map<int, string> getRooms() const
    {
        return rooms;
    }

    void printAllRooms() const
    {
        if (rooms.empty())
        {
            cout << "No rooms in this category." << endl;
            return;
        }

        cout << "Rooms in category:" << endl;
        for (const auto &room : rooms)
        {
            cout << " Room Number: " << room.first << ", Type: " << room.second << endl;
        }
    }

    int count() const
    {
        return rooms.size();
    }

};
#endif
