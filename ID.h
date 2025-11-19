#ifndef ID_FILE
#define ID_FILE


#include <bits/stdc++.h>
using namespace std;
enum Object
{
      Room,
      Hotel,
      Admin,
      Customer
};
class ID
{
private:

      static int count;
      static map<int, ID *> Table[4];

protected:

      const int Id;
      const Object Type;

public:

      ID ( Object type ) : Id ( count ++ ) , Type ( type )
      {
            Table[this->Type][ Id ] = this ;
      }

      static ID *ValidID( int id , Object Type)
      {
            map<int, ID *>::iterator it = Table[Type].find(id);
            if (it != Table[Type].end())
                  return it->second;
            else
                  return nullptr;
      }

      Object getType()
      {
            return Type;
      }

      int getID()
      {
            return Id;
      }

};

int ID::count = 1000;
map<int, ID *> ID::Table[4];




#endif