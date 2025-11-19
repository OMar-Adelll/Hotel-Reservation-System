#ifndef UTILS_FILE
#define UTILS_FILE


#include <bits/stdc++.h>
using namespace std;


class Utils
{
private :
      
public :

      static int Readint ( const string & promote , int min_ , int max_ )
      {                  
            cout << promote << "\n" ;
            int i;
            
            while (true)
            {

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


};



#endif