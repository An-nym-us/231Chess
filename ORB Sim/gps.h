//#pragma once
//#include <iostream>
//
//#include "object.h"
//#include "point.h"
//
//using namespace std;
//class GPS : public Object
//{
//public:
//   GPS() {
//
//   }
//   GPS(const Point startingPostion)
//   {
//      location = startingPostion;
//   }
//   GPS(double x, double y)
//   {
//      location.setMetersX(x);
//      location.setMetersY(y);
//   }
//
//   void updateTransformRelitiveToEarth()
//   {
//      updateGravity();
//      updateAcceleration();
//      updateVelocity();
//      updatelocation();
//    
//   }
//
//   
//   Point getPostion() { return location; }
//private:
//   
//   Object* object = new Object();
//
//   
//
//   void updateGravity();
//   void updateVelocity();
//   void updateAcceleration();
//   void updatelocation();
//   const double T = 144.0;
//
//   Point location;
//   const double DistanceFromCenterOfEarth = 42164000.0;
//   const double GeoTargetVelocity = 3000.0;
//   const double GRAVITY = -9.8067; // m/s^2 at sea level
//   double angleRelToEarth; // in degrees
//   Point velocityRelEarth = Point(0.0, 0.0);
//   Point accelerationRelEarth = Point(0.0, 0.0);
//   
//
//   double GravityHight = 0;;
//   double angleInRadians = 0;
//};