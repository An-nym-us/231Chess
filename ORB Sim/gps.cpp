#include "gps.h"

void GPS::updateGravity()
{
   GravityHight = GRAVITY * pow((6378000 / (DistanceFromCenterOfEarth)), 2);
   angleInRadians = atan2(location.getMetersY(), location.getMetersX());


}

void GPS::updateVelocity()
{
   //calculate Velocity.
   velocityRelEarth.setMetersX(GeoTargetVelocity * sin(angleInRadians));
   velocityRelEarth.setMetersY(GeoTargetVelocity * -1 * cos(angleInRadians));
   double dx = velocityRelEarth.getMetersX() + accelerationRelEarth.getMetersX() * T;
   double dy = velocityRelEarth.getMetersY() + accelerationRelEarth.getMetersY() * T;

   cout << "velocity" << endl;
   cout << "X Vel: " << velocityRelEarth.getMetersX() << endl;
   cout << "Y Vel: " << velocityRelEarth.getMetersY() << endl;
}

void GPS::updateAcceleration()
{
   // calculate Acceleration
   accelerationRelEarth.setMetersX(GravityHight * sin(angleInRadians));
   accelerationRelEarth.setMetersY(GravityHight * cos(angleInRadians));

   cout << "Aceleration " << endl;
   cout << "X acc: " << accelerationRelEarth.getMetersX() << endl;
   cout << "Y acc: " << accelerationRelEarth.getMetersY() << endl;
}

void GPS::updateLocation()
{
   double x = location.getMetersX() + velocityRelEarth.getMetersX() * T + .5 * accelerationRelEarth.getMetersX() * (T * T);
   double y = location.getMetersY() + velocityRelEarth.getMetersY() * T + .5 * accelerationRelEarth.getMetersY() * (T * T);
   location.setMetersX(x);
   location.setMetersY(y);
}
