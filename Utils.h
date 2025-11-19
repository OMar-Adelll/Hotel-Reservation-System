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


#endif