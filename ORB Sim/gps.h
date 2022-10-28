#pragma once
#include <iostream>
#include "position.h"

using namespace std;
class GPS : private Position
{
public:
   GPS() {

   }
   GPS(Position startingPostion)
   {
      location = startingPostion;
   }
   GPS(double x, double y)
   {
      location.setMetersX(x);
      location.setMetersY(y);
   }

   void updateTransformRelitiveToEarth() 
   { 
      updateGravity();
      updateAcceleration();
      updateVelocity();
      updateLocation();
   }

   
   Position getPostion() { return location; }
private:
   
   void updateGravity();
   void updateVelocity();
   void updateAcceleration();
   void updateLocation();
   const double T = 144.0;

   Position location;
   const double DistanceFromCenterOfEarth = 42164000.0;
   const double GeoTargetVelocity = 3100.0;
   const double GRAVITY = -9.8067; // m/s^2 at sea level
   double angleRelToEarth; // in degrees
   Position velocityRelEarth = Position(0.0, 0.0);
   Position accelerationRelEarth = Position(0.0, 0.0);
   

   double GravityHight = 0;;
   double angleInRadians = 0;
};