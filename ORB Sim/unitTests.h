#pragma once

#include <cassert>
#include "point2D.h"
#include "object.h"

class unitTests
{
public:
   void runner();

private:

   void resetTests();

   Velocity* vel = nullptr;
   Position* pos = nullptr;
   Acceleration* acc = nullptr;
   Object* obj = nullptr;

};

void unitTests::runner()
{
   resetTests();
}


void unitTests::resetTests()
{
   if (vel)
   {
      delete vel;
      vel = nullptr;
   }
   if (pos)
   {
      delete pos;
      pos = nullptr;
   }
   if (acc)
   {
      delete acc;
      acc = nullptr;
   }
   if (obj)
   {
      delete obj;
      obj = nullptr;
   }

   assert(vel == nullptr);
   assert(pos == nullptr);
   assert(acc == nullptr);
   assert(pos == nullptr);
};