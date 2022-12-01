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
   //friend class unitTests;
public:

   Object();
   ~Object()
   {

   };


   void setGeoTargetVelocity(double GeoTargetVelocity) { this->GeoTargetVelocity = GeoTargetVelocity; }
   void setStartingVelocity2D(double dx, double dy) 
   { 
      this->velocityRelEarth.setMeters(dx, dy); 
   }
   Point getPostion() { return location; }
private:




protected:
   const double T = 30.0;

   // Point location;
   const double DistanceFromCenterOfEarth = 42164000.0;
   double GeoTargetVelocity = 3000.0;
   const double GRAVITY = -9.8067; // m/s^2 at sea level
   double angleRelToEarth; // in degrees
   Point velocityRelEarth = Point(0.0, 0.0);
   Point accelerationRelEarth = Point(0.0, 0.0);


   double GravityHight = 0;;
   double angleInRadians = 0;
   Point location = Point(0.0, 0.0);;
   void updateVelocity();
   void updateAcceleration();
   void updatelocation();
   void updateGravity();

   
};

