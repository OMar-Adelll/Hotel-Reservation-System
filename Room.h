#ifndef ROOM_FILE
#define ROOM_FILE

#include <bits/stdc++.h>
#include "ID.h"
#include "Date.h"

enum class RoomStatus
{
      Available,
      Booked,
      UnderMaintenance
};

enum class RoomType
{
      Single = 1,
      Double,
      Twin,
      Deluxe,
      Suite,
      Family
};

class Room : public ID
{
private:
      int roomNumber;
      int roomFloor;
      double roomPrice;
      RoomStatus roomStatus;
      RoomType roomType;
      date checkIn;
      date checkOut;

public:
      Room() : ID ( Object::Room )
      {
            roomNumber = 0;
            roomFloor = 0;
            roomPrice = 0.0;
            roomStatus = RoomStatus::Available;
            roomType = RoomType::Single;

            checkIn = date();
            checkOut = date();
      };

      Room(int roomNumber, int roomFloor, double roomPrice, RoomType roomType,
           RoomStatus roomStatus = RoomStatus::Available)  : ID ( Object::Room )
      {
            this->roomNumber = roomNumber;
            this->roomFloor = roomFloor;
            this->roomPrice = roomPrice;
            this->roomType = roomType;
            this->roomStatus = roomStatus;

            checkIn = date();
            checkOut = date();
      }

      // -- Main functions -- //

      void setRoomNumber(int n) { roomNumber = n; }
      void setRoomFloor(int f) { roomFloor = f; }
      void setRoomPrice(double p) { roomPrice = p; }
      void setRoomStatus(RoomStatus s) { roomStatus = s; }
      void setRoomType(RoomType t) { roomType = t; }

      void setCheckIn(int d, int m, int y)
      {
            checkIn.set_date(d, m, y);
      }

      void setCheckOut(int d, int m, int y)
      {
            checkOut.set_date(d, m, y);
      }
      void setCheckIn(const date &t)
      {
            checkIn = t;
      }

      void setCheckOut(const date &t)
      {
            checkOut = t;
      }

      int getRoomNumber() const { return roomNumber; }
      int getRoomFloor() const { return roomFloor; }
      double getRoomPrice() const { return roomPrice; }
      RoomStatus getRoomStatus() const { return roomStatus; }
      RoomType getRoomType() const { return roomType; }
      date getCheckIn() const { return checkIn; }
      date getCheckOut() const { return checkOut; }

      // -- Additional functions -- //

      bool isAvailable() const
      {
            return roomStatus == RoomStatus::Available;
      }

      void bookRoom(const date &in, const date &out)
      {
            checkIn = in;
            checkOut = out;
            roomStatus = RoomStatus::Booked;
      }

      void freeRoom()
      {
            checkIn = date();
            checkOut = date();
            roomStatus = RoomStatus::Available;
      }

      void displayRoomData() const
      {
            cout << left
                 << setw(10) << "RoomNo"
                 << setw(8) << "Floor"
                 << setw(10) << "Price"
                 << setw(12) << "Type"
                 << setw(15) << "Status"
                 << setw(12) << "CheckIn"
                 << setw(12) << "CheckOut" << '\n';

            cout << string(79, '-') << '\n';

            cout << left
                 << setw(10) << roomNumber
                 << setw(8) << roomFloor
                 << setw(10) << roomPrice;

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

            cout << setw(12) << checkIn.toString() << setw(12) << checkOut.toString() << '\n';
      }
};


#endif