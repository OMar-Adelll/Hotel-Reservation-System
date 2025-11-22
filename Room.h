#ifndef ROOM_FILE
#define ROOM_FILE

#include <bits/stdc++.h>
#include "ID.h"
#include "Date.h"
#include "Utils.h"



class Room1 : public ID
{
private:
      int roomNumber;
      int roomFloor;
      double roomPrice;
      RoomStatus roomStatus;
      RoomType roomType;
      Date checkIn;
      Date checkOut;

public:
      Room1() : ID(Object::Room)
      {
            roomNumber = 0;
            roomFloor = 0;
            roomPrice = 0.0;
            roomStatus = RoomStatus::UnderMaintenance;
            roomType = RoomType::Single;

            checkIn = Date();
            checkOut = Date();
      };

      Room1(int roomNumber, int roomFloor, double roomPrice, RoomType roomType,
           RoomStatus roomStatus = RoomStatus::Available) : ID(Object::Room)
      {
            this->roomNumber = roomNumber;
            this->roomFloor = roomFloor;
            this->roomPrice = roomPrice;
            this->roomType = roomType;
            this->roomStatus = roomStatus;

            checkIn = Date();
            checkOut = Date();
      };

      Room1(int roomNumber , RoomType t) :ID(Object::Room)
      {
            this->roomNumber = roomNumber;
            this->roomType = t;
            this->roomFloor = 0;
            this->roomPrice = 0.0;
            RoomStatus::UnderMaintenance;
            checkIn = Date();
            checkOut = Date();
      }


      // -- Main functions -- //

      void setRoomNumber(int n) { roomNumber = n; }
      void setRoomFloor(int f) { roomFloor = f; }
      void setRoomPrice(double p) { roomPrice = p; }
      void setRoomStatus(RoomStatus s) { roomStatus = s; }
      void setRoomType(RoomType t) { roomType = t; }
      void setCheckIn(int d, int m, int y) { checkIn.setDate(d, m, y); }
      void setCheckOut(int d, int m, int y) { checkOut.setDate(d, m, y); }
      void setCheckIn(const Date &t) { checkIn = t; }
      void setCheckOut(const Date &t) { checkOut = t; }

      int getRoomNumber() const { return roomNumber; }
      int getRoomFloor() const { return roomFloor; }
      double getRoomPrice() const { return roomPrice; }
      RoomStatus getRoomStatus() const { return roomStatus; }
      RoomType getRoomType() const { return roomType; }
      Date getCheckIn() const { return checkIn; }
      Date getCheckOut() const { return checkOut; }

      // -- Additional functions -- //

      bool isAvailable() const
      {
            return roomStatus == RoomStatus::Available;
      }

      void bookRoom(const Date &in, const Date &out)
      {
            checkIn = in;
            checkOut = out;
            roomStatus = RoomStatus::Booked;
      }

      void freeRoom()
      {
            checkIn = Date();
            checkOut = Date();
            roomStatus = RoomStatus::Available;
      }

      friend ostream& operator<< ( ostream& out , Room1 obj )
      {
            out << left
                 << setw(10) << "RoomNo : " << obj.roomNumber
                 << setw(8) << "Floor : " << obj.roomFloor
                 << setw(10) << "Price : " << obj.roomPrice
                 << setw(12) << "Type : " << obj.roomType
                 << setw(15) << "Status : " << obj.roomStatus
                 << setw(12) << "CheckIn : " << obj.checkIn
                 << setw(12) << "CheckOut : " << obj.checkOut << '\n';

            out << string(79, '-') << '\n';

            out << left
                 << setw(10) << obj.roomNumber
                 << setw(8) << obj.roomFloor
                 << setw(10) << obj.roomPrice;


            out << setw(12) << obj.checkIn.toString() << setw(12) << obj.checkOut.toString() << '\n';
      }
};

#endif