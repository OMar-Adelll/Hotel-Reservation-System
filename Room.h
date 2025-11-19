#include<bits/stdc++.h>
#include "ID.h"
class Room : public ID
{
      public :
            Room()
            {
                  Type = Object::Room ;
                  Id = NextId() ;
                  Table[Type][Id] = this ;
            } ;
} ;