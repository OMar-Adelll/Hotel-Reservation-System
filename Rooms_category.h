#ifndef ROOMS_CATEGORY_H
#define ROOMS_CATEGORY_H

#include "Room.h"
#include <bits/stdc++.h>



using namespace std;
class Rooms_category
{
private:
    map<int, Room1 *> rooms;
    ID * owner ;


public:
    Rooms_category( ID * owner  ) : owner ( owner ) {}

    bool hasRoom(int roomNumber) const
    {
        return rooms.find(roomNumber) != rooms.end();
    }

    void addRoom(int roomNumber, Room1 *roomPtr, bool status = true)
    {
        if (status)
        {
            auto it = rooms.find(roomNumber);
            if ( owner->getType() == Object::Hotel && it != rooms.end())
                delete it->second;

            rooms[roomNumber] = roomPtr;
        }
    }

    void deleteRoom(int roomNumber, bool status = true)
    {
        if (status)
        {
            auto it = rooms.find(roomNumber);
            if ( owner->getType() == Object::Hotel && it != rooms.end())
            {
                delete it->second;
                rooms.erase(it);
            }
        }
    }

    map<int, Room1 *> getRooms() const
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
            cout << " Room Number: " << room.first << ", Type: ";
            if (room.second)
            {
                room.second->displayRoomData() ;
            }

            cout << endl;
        }
    }

    int count() const
    {
        return rooms.size();
    }
    
    ~Rooms_category()
    {
        for (auto &p : rooms)
        {
            if ( owner->getType() == Object::Hotel )
                delete p.second;
        }
        rooms.clear();
    }
};
#endif
