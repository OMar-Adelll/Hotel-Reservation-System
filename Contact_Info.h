#ifndef CONTACT_INFO_H
#define CONTACT_INFO_H
#include <bits/stdc++.h>
using namespace std;

class Contact_Information
{
private:
    string address;
    string email;
    string phone;

public:
    Contact_Information(): address(""), email(""), phone(""){}

    Contact_Information(const string &addr, const string &em, const string &ph): address(addr), email(em), phone(ph){}

    string getAddress() const
    {
        return address;
    }

    void setAddress(const string &addr)
    {
        address = addr;
    }

    void setEmail(const string &em)
    {
        email = em;
    }

    string getEmail() const
    {
        return email;
    }

    void setPhone(const string &ph)
    {
        phone = ph;
    }

    string getPhone() const
    {
        return phone;
    }

    friend ostream &operator << (ostream &out, const Contact_Information &contact)
    {
        out << "Address: " << contact.address << ", Email: " << contact.email << ", Phone: " << contact.phone;
        return out;
    }
};
#endif
