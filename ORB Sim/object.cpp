#include "object.h"

Object::Object()
{
}

void Object::updateGravity()
{

   GravityHight = (-1)* GRAVITY * pow((6378000 / (DistanceFromCenterOfEarth)), 2);
   angleInRadians = atan2(location.getMetersY(), location.getMetersX());
}


void Object::updateVelocity()
{
   //calculate Velocity.
   velocityRelEarth.setMetersX(GeoTargetVelocity * sin(angleInRadians));
   velocityRelEarth.setMetersY(GeoTargetVelocity * -1 * cos(angleInRadians));
   double dx = velocityRelEarth.getMetersX() + accelerationRelEarth.getMetersX() * T;
   double dy = velocityRelEarth.getMetersY() + accelerationRelEarth.getMetersY() * T;


}

void Object::updateAcceleration()
{
   // calculate Acceleration
   accelerationRelEarth.setMetersX(GravityHight * sin(angleInRadians));
   accelerationRelEarth.setMetersY(GravityHight * cos(angleInRadians));


}

void  Object::updatelocation()
{
   double x = location.getMetersX() + velocityRelEarth.getMetersX() * T + .5 * accelerationRelEarth.getMetersX() * (T * T);
   double y = location.getMetersY() + velocityRelEarth.getMetersY() * T + .5 * accelerationRelEarth.getMetersY() * (T * T);
   location.setMetersX(x);
   location.setMetersY(y);
}
