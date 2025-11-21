#ifndef ADMIN_FILE
#define ADMIN_FILE

#include <bits/stdc++.h>
#include "Person.h"
#include "Room.h"
#include "Utils.h"
#include "Rooms_category.h"

using namespace std;


class Admin : public Person
{
    private :

        PowerLevel levelPower;
        int hotelWorkAt;

    public :

        Admin ( int SSN , Date age , Name name , Object type ) 
            : Person( SSN , age , name , Object::Admin ) {} ;

        PowerLevel getLevelPower() const { return levelPower; }
        int getHotelWorkAt() const { return hotelWorkAt; }

        void setLevelPower(PowerLevel p) { levelPower = p; }
        void setHotelWorkAt(int h) { hotelWorkAt = h; }

        friend ostream& operator<<(ostream& out, const Admin& obj) 
        {
            out << static_cast<const Person&>(obj);  


            return out;
        }

};


#endif