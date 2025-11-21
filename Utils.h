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


enum RoomStatus
{
      Available,
      Booked,
      UnderMaintenance
};

void print_roomStatus ( RoomStatus roomStatus )
{
      switch (roomStatus)
      {
      case RoomStatus::Available:
            cout << setw(15) << "Available";
            break;
      case RoomStatus::Booked:
            cout << setw(15) << "Booked";
            break;
      case RoomStatus::UnderMaintenance:
            cout << setw(15) << "Maintenance";
            break;
      }
}


enum RoomType
{
      Single = 1,
      Double,
      Twin,
      Deluxe,
      Suite,
      Family
};

void print_roomType ( RoomType roomType )
{
      switch (roomType)
      {
      case RoomType::Single:
            cout << setw(12) << "Single";
            break;
      case RoomType::Double:
            cout << setw(12) << "Double";
            break;
      case RoomType::Twin:
            cout << setw(12) << "Twin";
            break;
      case RoomType::Deluxe:
            cout << setw(12) << "Deluxe";
            break;
      case RoomType::Suite:
            cout << setw(12) << "Suite";
            break;
      case RoomType::Family:
            cout << setw(12) << "Family";
            break;
      }
}

#endif