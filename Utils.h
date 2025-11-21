#ifndef UTILS_FILE
#define UTILS_FILE


#include <bits/stdc++.h>
#include "picosha2.h"
using namespace std;


class Utils
{
private :

      static const regex passwordTemplate ;
      
public :

      static int Readint ( const string & promote , int min_ = INT_MIN , int max_ = INT_MAX )
      {                  
            int i;
            
            while (true)
            {
                  cout << promote << " : " ;
                  cin >> i;
                  if (cin.fail())
                  {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Please Enter a valid integer!" << endl;
                        continue;
                  }
                  if ( !( min_ <= i && i <= max_ ) ) break;
                 cout << "Please Enter a integer! at vaild range ( " << min_ << " , " << max_ << ")" << endl;
            }
            return i;
      }

      static string ReadString ( const string & promote )
      {
            string s;

            while (true)
            {
                  cout << promote << " : " ;
                  cin >> s;

                  if (cin.fail())
                  {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Please Enter a valid string!" << endl;
                        continue;
                  }

                  break;
            }

            return s;
      }

      static bool vaildPassword ( const string & passowrd )
      {
            return regex_match(  passowrd , passwordTemplate ) ;
      }

      static string hashString ( const string & password ) 
      {
            return picosha2::hash256_hex_string( password ) ; 
      }

      static string ReadPasswrod ()
      {
            string password ;
            while (true)
            {
                  password = ReadString( "Enter password" ) ;

                  if (!vaildPassword(password))
                  {
                        cout << "Password does not match the required template!" << endl;
                        continue;
                  }

                  break;
            }  

            return hashString( password ) ;
      }

};

const regex Utils::passwordTemplate ( "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*\\W).{8,}$" ) ;


// ------------------------------------- RoomStatus -------------------------------------

enum RoomStatus
{
      Available,
      Booked,
      UnderMaintenance
};

ostream& operator<<(ostream& out, RoomStatus status)
{
    switch (status)
    {
    case RoomStatus::Available:
        out << setw(15) << "Available";
        break;
    case RoomStatus::Booked:
        out << setw(15) << "Booked";
        break;
    case RoomStatus::UnderMaintenance:
        out << setw(15) << "Maintenance";
        break;
    }
    return out;
}

// ------------------------------------- RoomType -------------------------------------

enum RoomType
{
      Single = 1,
      Double,
      Twin,
      Deluxe,
      Suite,
      Family
};

ostream& operator<<(ostream& out, RoomType type)
{
    switch (type)
    {
    case RoomType::Single:
        out << setw(12) << "Single";
        break;
    case RoomType::Double:
        out << setw(12) << "Double";
        break;
    case RoomType::Twin:
        out << setw(12) << "Twin";
        break;
    case RoomType::Deluxe:
        out << setw(12) << "Deluxe";
        break;
    case RoomType::Suite:
        out << setw(12) << "Suite";
        break;
    case RoomType::Family:
        out << setw(12) << "Family";
        break;
    }
    return out;
}

// ------------------------------------- Object -------------------------------------

enum Object
{
    Room,
    Hotel,
    Admin,
    Customer
};

ostream &operator<<(ostream &out, Object obj)
{
    switch (obj)
    {
    case Room:
        out << "Room";
        break;
    case Hotel:
        out << "Hotel";
        break;
    case Admin:
        out << "Admin";
        break;
    case Customer:
        out << "Customer";
        break;
    default:
        out << "Unknown";
        break;
    }
    return out;
}

// ------------------------------------- PowerLevel -------------------------------------

enum class PowerLevel
{
    Low,
    Medium,
    High,
    Super
};

ostream &operator<<(ostream &out, PowerLevel level)
{
    switch (level)
    {
    case PowerLevel::Low:
        out << "Low";
        break;
    case PowerLevel::Medium:
        out << "Medium";
        break;
    case PowerLevel::High:
        out << "High";
        break;
    case PowerLevel::Super:
        out << "Super";
        break;
    default:
        out << "Unknown";
        break;
    }
    return out;
}

#endif