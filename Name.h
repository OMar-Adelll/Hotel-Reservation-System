#ifndef NAME_FILE
#define NAME_FILE
#include <bits/stdc++.h>
using namespace std;

class Name
{
private:
    string firstName;
    string lastName;

public:
    Name(): firstName(""), lastName(""){}

    Name(const string &first, const string &last): firstName(first), lastName(last){}

    void setFirstName(const string &first)
    {
        firstName = first;
    }

    void setLastName(const string &last)
    {
        lastName = last;
    }

    string getFullName() const
    {
        return firstName + " " + lastName;
    }

    friend ostream &operator << (ostream &out, const Name &name)
    {
        out << name.firstName << " " << name.lastName;
        return out;
    }
};
#endif
