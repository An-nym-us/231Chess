#pragma once

#include "Point.h"
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

   };


   void updateVelocity();
   void updateAcceleration();
   void updatelocation();
   void updateGravity();

   



private:
   double rotation;
   double GravityHight;
   double angleInRadians = 0;
   double distance;
   double dx;
   double dy;
   double ddx;
   double ddy;
   double T;
   Point location = Point(0.0, 0.0);;


   const double DistanceFromCenterOfEarth = 42164000.0;
   const double GeoTargetVelocity = 3000.0;
   const double GRAVITY = -9.8067; // m/s^2 at sea level
   double angleRelToEarth; // in degrees//   double GravityHight = 0;;

   Point velocityRelEarth = Point(0.0, 0.0);
   Point accelerationRelEarth = Point(0.0, 0.0);

protected:




};

