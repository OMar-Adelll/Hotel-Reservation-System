#ifndef ROOMS_CATEGORY_H
#define ROOMS_CATEGORY_H

#include "Room.h"
#include <bits/stdc++.h>

using namespace std;
class Rooms_category
{
private:
    map<int, Room1 *> rooms;

public:

    bool hasRoom(int roomId ) const
    {
        return rooms.find( roomId ) != rooms.end();
    }

    void addRoom( int roomId )
    {
        rooms[ roomId ] = static_cast<Room1*>(ID::ValidID( roomId , Object::Room )) ;
    }

    void addRoom( Room1 *roomPtr )
    {
        rooms[ roomPtr->getID() ] = roomPtr ;
    }

    void deleteRoom( int roomId )
    {
        rooms.erase ( roomId ) ;
    }

    void deleteRoom( Room1 *roomPtr )
    {
        rooms.erase (  roomPtr->getID() ) ;
    }

    friend ostream &operator<<(ostream &out, const Rooms_category &obj)
    {
        if (obj.rooms.empty())
        {
            cout << "No rooms in this category." << endl;
            return;
        }

        cout << "Rooms in category:" << endl;
        for (const auto &room : obj.rooms)
            if ( room.second ) out << room.second ;
        
        return out;
    }

    int count() const
    {
        return rooms.size() ;
    }

};
#endif
