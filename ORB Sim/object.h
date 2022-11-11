#pragma once

#include "testPointStuff.h"
#include <iostream>
class unitTests;

//class Velocity : private Point
//{
//   friend class unitTests;
//public:
//   Velocity() {};
//   Velocity(double dx, double dy) { this->dx = dx; this->dy = dy; }
//
//
//
//
//
//
//   Velocity returnVelocity() { return (*this); }
//private:
//   double dx;
//   double dy;
//};
//class Position : private Point
//{
//   friend class unitTests;
//public:
//
//
//
//private:
//   double dx;
//   double dy;
//
//};
//class Acceleration : private Point
//{
//   friend class unitTests;
//public:
//
//
//
//private:
//
//
//};


class Object  
{
   friend class unitTests;
public:

   Object();
   ~Object()
   {
      //delete velocity;
      //velocity = nullptr;
   };

   //void test()
   //{
   //   Velocity testing(7, 5);
   //   Velocity test2(3, 4);

   //   test2 += testing;

   //   std::cout << test2.returnVelocityX();
   //}
  /* Velocity& operator +=(const Velocity& rhs)
   {
      dx += rhs.dx;
      dy += rhs.dy;
      return *this;
   }
   Velocity& operator -=(const Velocity& rhs)
   {
      dx -= rhs.dx;
      dy -= rhs.dy;
      return *this;
   }
   Velocity operator + (const Velocity& rhs)
   {
      Velocity temp(*this);
      temp += rhs;
      return temp;
   }
   Velocity operator - (const Velocity& rhs)
   {
      Velocity temp(*this);
      temp -= rhs;
      return temp;
   }*/
   void updateVelocity();
   void updateAcceleration();
   void updateLocation();
   void updateGravity();

   



private:
   double rotation;
   double GravityHight;
   double distance;
   double dx;
   double dy;
   double ddx;
   double ddy;
   double T;
   Point* Location;



protected:




};

