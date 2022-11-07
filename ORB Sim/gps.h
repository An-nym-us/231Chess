#pragma once
#include <iostream>

#include "object.h"
#include "point2D.h"

using namespace std;
class GPS : public Object
{
public:
   GPS() {

   }
   GPS(Point2D startingPostion)
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

      object->returnVelocity();

      
   }

   
   Point2D getPostion() { return location; }
private:
   
   Object* object = new Object();

   

   void updateGravity();
   void updateVelocity();
   void updateAcceleration();
   void updateLocation();
   const double T = 144.0;

   Point2D location;
   const double DistanceFromCenterOfEarth = 42164000.0;
   const double GeoTargetVelocity = 3000.0;
   const double GRAVITY = -9.8067; // m/s^2 at sea level
   double angleRelToEarth; // in degrees
   Point2D velocityRelEarth = Point2D(0.0, 0.0);
   Point2D accelerationRelEarth = Point2D(0.0, 0.0);
   

   double GravityHight = 0;;
   double angleInRadians = 0;
};