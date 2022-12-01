#pragma once
#include <iostream>

#include "object.h"
#include "point.h"

using namespace std;
class GPS : public Object
{
public:
   GPS() {

   }

   GPS(double x, double y, double dx, double dy, double GeoTargetVelocity)
   {
      location.setMetersX(x);
      location.setMetersY(y);
      setStartingVelocity2D(dx, dy);
      setGeoTargetVelocity(GeoTargetVelocity);
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
      updatelocation();
   }

   


private:
   

};

class DragonCrew : public Object
{
public:
   DragonCrew() {

   }
   DragonCrew(double x, double y)
   {
      location.setMetersX(x);
      location.setMetersY(y);
   }

   void updateTransformRelitiveToEarth()
   {
      updateGravity();
      updateAcceleration();
      updateVelocity();
      updatelocation();
   }


private:


};

class Hubble : public Object
{
public:
   Hubble() {

   }

   Hubble(double x, double y)
   {
      location.setMetersX(x);
      location.setMetersY(y);
   }

   void updateTransformRelitiveToEarth()
   {
      updateGravity();
      updateAcceleration();
      updateVelocity();
      updatelocation();
   }

private:
};

class Sputnik : public Object
{
public:
   Sputnik() {

   }

   Sputnik(double x, double y)
   {
      location.setMetersX(x);
      location.setMetersY(y);
   }

   void updateTransformRelitiveToEarth()
   {
      updateGravity();
      updateAcceleration();
      updateVelocity();
      updatelocation();
   }

private:
};

class Starlink : public Object
{
public:
   Starlink() {

   }
   Starlink(double x, double y, double dx, double dy, double GeoTargetVelocity)
   {
      location.setMetersX(x);
      location.setMetersY(y);
      setStartingVelocity2D(dx, dy);
      setGeoTargetVelocity(GeoTargetVelocity);
   }
   Starlink(double x, double y)
   {
      location.setMetersX(x);
      location.setMetersY(y);
   }

   void updateTransformRelitiveToEarth()
   {
      updateGravity();
      updateAcceleration();
      updateVelocity();
      updatelocation();
   }

private:
};


class Star : public Object
{
public:
   Star() {

   }

   Star(double x, double y, unsigned char starPhase)
   {
      location.setMetersX(x);
      location.setMetersY(y);
      this->starPhase = starPhase;
   }

   void UpdatePhase() { starPhase++; }
   unsigned char getPhase() { return starPhase; }
private:
   unsigned char starPhase;

};

class Fragments : public Object
{
public:
   Fragments() {

   }

   Fragments(double x, double y)
   {
      location.setMetersX(x);
      location.setMetersY(y);
   }

   void updateTransformRelitiveToEarth()
   {
      updateGravity();
      updateAcceleration();
      updateVelocity();
      updatelocation();
   }

private:
};