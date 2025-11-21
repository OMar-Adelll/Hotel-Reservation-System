#ifndef CUSTOMER_FILE
#define CUSTOMER_FILE

#include <bits/stdc++.h>
#include "Person.h"
#include "Room.h"
#include "Utils.h"
#include "Rooms_category.h"

using namespace std;


class Customer : public Person
{
    private :

        Rooms_category completeRooms , canceledRooms , bookedRooms ;

    public :

        Customer ( int SSN , Date age , Name name , Object type ) 
            : Person( SSN , age , name , Object::Customer )
            , completeRooms ( this ) 
            , canceledRooms ( this ) 
            , bookedRooms ( this ) {} ;

        friend ostream& operator<<(ostream& out, const Customer& obj) 
        {
            out << static_cast<const Person&>(obj);  

            out << "Complete Rooms" << "\n" << obj.completeRooms << "\n" ;
            out << "Canceled Rooms" << "\n" << obj.canceledRooms << "\n" ;
            out << "Booked Rooms" << "\n" << obj.bookedRooms << "\n" ;

            return out;
        }

};


#endif