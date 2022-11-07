#pragma once

#include "testPointStuff.h"
#include <iostream>


class Velocity : private Point
{
public:
   Velocity(double dx, double dy) { this->dx = dx; this->dy = dy; }

   Velocity& operator +=(const Velocity& rhs)
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
   }




   Velocity returnVelocity() { return (*this); }
private:
   double dx;
   double dy;
};

class Position : private Point
{
public:



private:
   double dx;
   double dy;
};

class Acceleration : private Point
{
public:



private:


};


class Object  
{

public:

   Object();
   ~Object()
   {
      delete velocity;
      velocity = nullptr;
   };

   //void test()
   //{
   //   Velocity testing(7, 5);
   //   Velocity test2(3, 4);

   //   test2 += testing;

   //   std::cout << test2.returnVelocityX();
   //}

   

   

   Velocity* returnVelocity() { return velocity; }

private:



   Velocity* velocity = new Velocity(0,0);



protected:




};

