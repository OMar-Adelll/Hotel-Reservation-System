#include <bits/stdc++.h>
using namespace std ;
enum Object { Room, Hotel, Admin, Customer } ;
class ID
{
      protected:

            static int inline count = 1000 ;
            static map< int, ID* > Table[ 4 ] ;
            int Id ;
            Object Type ;

      public:

            static ID* ValidID( int Id, Object Type )
            {
                  map<int, ID* >::iterator it = Table[Type].find( Id ) ;
                  if ( it != Table[Type].end() )
                        return it -> second ;
                  else
                        return nullptr ;
            }
            Object GetType()
            {
                  return Type ;
            }
            int MyID()
            {
                  return Id ;
            }
            static int NextId()
            {
                  int id = count++ ;
                  return id ;
            }
            
            // Two ways to read the id; feel comfortable using either one.
            static int ReadId()
            {
                  while ( true )
                  {
                        cout << "Enter the ID: " ;
                        int i ;
                        cin >> i ;
                        if ( cin.fail() )
                        {
                              cin.clear() ;
                              cin.ignore(INT_MAX, '\n');
                              cout << "Please Enter a valid integer!" << endl ;
                              continue ;
                        }
                        return i ;
                  }
            }
            static int ReadId2()
            {
                  cout << "Enter the ID: " ;
                  while ( true )
                  {
                        string s ;
                        cin >> s ;
                        bool NotValid = 0 ;
                        for ( auto &digit : s )
                        {
                              if ( !isdigit( digit ) )
                              {
                                    NotValid = 1 ;
                                    break ;
                              }
                        }
                        if ( NotValid )
                        {
                              cout << "Please Enter a valid integer!" << endl ;
                              continue ;
                        }
                        return stoi( s ) ;
                  }
            }
} ;

map< int, ID* > ID::Table[4] ;
