#ifndef PERSON_FILE
#define PERSON_FILE


#include <bits/stdc++.h>
#include "ID.h"
#include "Date.h"
#include "Name.h"
#include "Utils.h"

using namespace std;


class Person : public ID
{
    private :
        
        const int SSN;
        const Date age;
        const Name name;
        string Password;

    public :

        Person ( int SSN , Date age , Name name , Object type ) 
            : SSN ( SSN ) 
            , age ( age ) 
            , name ( name ) 
            , ID ( type )
        {}

        
    int getSSN() const { return SSN;}
    Date getAge() const { return age;}
    Name getName() const { return name;}
    string getPassword() const { return Password; }

    void changePassword(string value) { Password = Utils::hashString( value ) ; }

    friend ostream& operator<< ( ostream& out , Person obj )
    {
        out << obj.name << "\n" ;
        out << static_cast<const ID&>(obj) << "\n" ;
        out << "National ID : " << obj.SSN << "\n" ;
        out << "Password : " << obj.Password << "\n" ;
        out << obj.age << "\n" ;

        return out ;
    }
};


#endif