#pragma once

#include <cassert>
#include "point2D.h"
#include "object.h"
#include <iostream>

class unitTests
{
public:
   void runner();

private:

   void resetTests();

   void updateGravity_1();

   void updateVelocity_1();
   void updateVelocity_2();
   void updateVelocity_3();
   void updateVelocity_4();

   void updateAcceleration_1();
   void updateAcceleration_2();
   void updateAcceleration_3();
   void updateAcceleration_4();

   void updateLocation_1();
   void updateLocation_2();
   void updateLocation_3();
   void updateLocation_4();

   /// <summary>
   /// //////////////////////
   /// </summary>

   void setMeters_1();
   void setMeters_2();
   void setMeters_3();
   void setMeters_4();

   void setMeters_x_1();
   void setMeters_y_1();

   void computeDistnace_1();
   void computeDistnace_2();

   void getMeters_x_1();
   void getMeters_x_2();

   void getMeters_y_1();
   void getMeters_y_2();

   void addMeters_x_1();
   void addMeters_x_2();
   void addMeters_x_3();

   void addMeters_y_1();
   void addMeters_y_2();
   void addMeters_y_3();

   Point* pt = nullptr;
   Object* obj = nullptr;

};

void unitTests::runner()
{

   updateGravity_1();

   updateVelocity_1();
   updateVelocity_2();
   updateVelocity_3();
   updateVelocity_4(); 

   updateAcceleration_1();
   updateAcceleration_2();
   updateAcceleration_3();
   updateAcceleration_4();

   updateLocation_1();
   updateLocation_2();
   updateLocation_3();
   updateLocation_4();

   setMeters_1();
   setMeters_2();
   setMeters_3();
   setMeters_4();

   setMeters_x_1();
   setMeters_y_1();

   computeDistnace_1();
   computeDistnace_2();

   getMeters_x_1();
   getMeters_x_2();

   getMeters_y_1();
   getMeters_y_2();

   addMeters_x_1();
   addMeters_x_2();
   addMeters_x_3();

   addMeters_y_1();
   addMeters_y_2();
   addMeters_y_3(); 
}



void unitTests::updateGravity_1()
{
   // Setup  
   resetTests();
   obj = new Object();
   assert(obj);;
   obj->rotation = 45;
   obj->distance = 6378000;
   obj->GravityHight = 0;

   // Exercise 
   obj->updateGravity();
   
   //Verify
   assert(rotation == 45);
   assert(GravityHight = 9.8);


   //Teardown
   resetTests();

}

void unitTests::updateVelocity_1()
{
   // Setup  
   resetTests();


   obj = new Object();
   assert(obj);
   obj->ddx = 0;
   obj->ddy = 0;
   obj->dx = 1;
   obj->dy = 1;
   obj->rotation = 0;
   obj->T = 1;

   // Exercise 
   obj->updateVelocity();
   //Verify
   assert(obj->dx == 1);
   assert(obj->dy == 1);


   //Teardown
   resetTests();
}

void unitTests::updateVelocity_2()
{
   // Setup  
   resetTests();


   obj = new Object();
   assert(obj);
   obj->ddx = 1;
   obj->ddy = 1;
   obj->dx = 1;
   obj->dy = 1;
   obj->rotation = 0;
   obj->T = 1;

   // Exercise 
   obj->updateVelocity();
   //Verify
   assert(obj->dx == .5);
   assert(obj->dy == .5);


   //Teardown
   resetTests();
}

void unitTests::updateVelocity_3()
{
   // Setup  
   resetTests();


   obj = new Object();
   assert(obj);
   obj->ddx = 1;
   obj->ddy = 0;
   obj->dx = 0;
   obj->dy = 0;
   obj->rotation = 45;
   obj->T = 1;

   // Exercise 
   obj->updateVelocity();
   //Verify
   assert(obj->dx == .5);
   assert(obj->dy == .5);


   //Teardown
   resetTests();
}

void unitTests::updateVelocity_4()
{
   // Setup  
   resetTests();


   obj = new Object();
   assert(obj);
   obj->ddx = 1;
   obj->ddy = 1;
   obj->dx = 1;
   obj->dy = -1;
   obj->rotation = 0;
   obj->T = 1;

   // Exercise 
   obj->updateVelocity();
   //Verify
   assert(obj->dx == 0);
   assert(obj->dy == 0);


   //Teardown
   resetTests();
}

void unitTests::updateAcceleration_1()
{
   // Setup  
   resetTests();


   obj = new Object();
   assert(obj);
   obj->GravityHight = -9.8;
   obj->ddx = 0;
   obj->ddy = 0;
   obj->dx = 0;
   obj->dy = 0;
   obj->rotation = 0;
   obj->T = 1;

   // Exercise 
   obj->updateAcceleration();
   //Verify
   assert(obj->ddx == 0);
   assert(obj->ddy == -9.8);


   //Teardown
   resetTests();
}

void unitTests::updateAcceleration_2()
{
   // Setup  
   resetTests();


   obj = new Object();
   assert(obj);
   obj->GravityHight = -9.8;
   obj->ddx = 0;
   obj->ddy = 0;
   obj->dx = 0;
   obj->dy = 0;
   obj->rotation = 45;
   obj->T = 1;

   // Exercise 
   obj->updateAcceleration();
   //Verify
   assert(obj->ddx <= -6.7);
   assert(obj->ddx >= -6.9);
   assert(obj->ddy <= -6.7);
   assert(obj->ddy >= -6.9);


   //Teardown
   resetTests();
}

void unitTests::updateAcceleration_3()
{
   // Setup  
   resetTests();


   obj = new Object();
   assert(obj);
   obj->GravityHight = -9.8;
   obj->ddx = 0;
   obj->ddy = 0;
   obj->dx = 0;
   obj->dy = 0;
   obj->rotation = 90;
   obj->T = 1;

   // Exercise 
   obj->updateAcceleration();
   //Verify
   assert(obj->ddx == -9.8);
   assert(obj->ddy == 0);


   //Teardown
   resetTests();
}

void unitTests::updateAcceleration_4()
{
   // Setup  
   resetTests();


   obj = new Object();
   assert(obj);
   obj->GravityHight = -9.8;
   obj->ddx = 1;
   obj->ddy = 1;
   obj->dx = 0;
   obj->dy = 0;
   obj->rotation = 0;
   obj->T = 1;

   // Exercise 
   obj->updateAcceleration();
   //Verify
   assert(obj->ddx == -9.8);
   assert(obj->ddy == 1);


   //Teardown
   resetTests();
}

void unitTests::updateLocation_1()
{
   // Setup  
   resetTests();


   obj = new Object();
   assert(obj);
   obj->Location = new Point();
   obj->Location->setMetersX(1);
   obj->Location->setMetersY(1);
   obj->ddx = 0;
   obj->ddy = 0;
   obj->dx = 0;
   obj->dy = 0;
   obj->T = 1;
   // Exercise 
   obj->updateLocation();
   //Verify
   
   assert(obj->Location->getMetersX() == 1);
   assert(obj->Location->getMetersY() == 1);


   //Teardown
   delete obj->Location;
   obj->Location = nullptr;
   resetTests();
}

void unitTests::updateLocation_2()
{
   // Setup  
   resetTests();


   obj = new Object();
   assert(obj);
   obj->Location = new Point();
   obj->Location->setMetersX(1);
   obj->Location->setMetersY(1);
   obj->ddx = 0;
   obj->ddy = 0;
   obj->dx = 1;
   obj->dy = 1;
   obj->T = 1;
   // Exercise 
   obj->updateLocation();
   //Verify
   assert(obj->Location->getMetersX() == 2);
   assert(obj->Location->getMetersY() == 2);


   //Teardown
   delete obj->Location;
   obj->Location = nullptr;
   resetTests();
}

void unitTests::updateLocation_3()
{
   // Setup  
   resetTests();


   obj = new Object();
   assert(obj);
   obj->Location = new Point();
   obj->Location->setMetersX(1);
   obj->Location->setMetersY(1);
   obj->ddx = 1;
   obj->ddy = 1;
   obj->dx = 1;
   obj->dy = 1;
   obj->T = 1;
   // Exercise 
   obj->updateLocation();
   //Verify
   assert(obj->Location->getMetersX() == 2.5);
   assert(obj->Location->getMetersY() == 2.5);


   //Teardown
   delete obj->Location;
   obj->Location = nullptr;
   resetTests();
}

void unitTests::updateLocation_4()
{
   // Setup  
   resetTests();


   obj = new Object();
   assert(obj);
   obj->Location = new Point();
   obj->Location->setMetersX(1);
   obj->Location->setMetersY(1);
   obj->ddx = 1;
   obj->ddy = 1;
   obj->dx = 0;
   obj->dy = 0;
   obj->T = 1;
   // Exercise 
   obj->updateLocation();
   //Verify
   assert(obj->Location->getMetersX() == 1.5);
   assert(obj->Location->getMetersY() == 1.5);


   //Teardown
   delete obj->Location;
   obj->Location = nullptr;
   resetTests();
}


///////////////////////////////////////////////////////////////////////


void unitTests::setMeters_1()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->x = -1;
   pt->y = -1;

   // Exercise 
   pt->setMeters(0, 0);

   //Verify
   assert(pt->x == 0);
   assert(pt->y == 0);

   //Teardown
   resetTests();

}

void unitTests::setMeters_2()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->x = 0;
   pt->y = 0;

   // Exercise 
   pt->setMeters(1,-10);

   //Verify
   assert(pt->x == 1);
   assert(pt->y == -1);

   //Teardown
   resetTests();

}

void unitTests::setMeters_3()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->x = 0;
   pt->y = 0;

   // Exercise 
   pt->setMeters(1, 1);

   //Verify
   assert(pt->x == 1);
   assert(pt->y == 1);

   //Teardown
   resetTests();

}

void unitTests::setMeters_4()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->x = 0;
   pt->y = 0;

   // Exercise 
   pt->setMeters(-1, -1);

   //Verify
   assert(pt->x == -1);
   assert(pt->y == -1);

   //Teardown
   resetTests();

}

void unitTests::setMeters_x_1()
{

   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->x = 0;


   // Exercise 
   pt->setMetersX(1);

   //Verify
   assert(pt->x == 1);


   //Teardown
   resetTests();
}

void unitTests::setMeters_y_1()
{

   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->y = 0;


   // Exercise 
   pt->setMetersY(1);

   //Verify
   assert(pt->y == 1);


   //Teardown
   resetTests();
}

void unitTests::computeDistnace_1()
{

   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);



   // Exercise 
   double output = pt->computeDistance(Point2D(0,0), Point2D(1,1));

   //Verify
   assert(output < 1.4);
   assert(output > 1.42);


   //Teardown
   resetTests();
}

void unitTests::computeDistnace_2()
{

   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);



   // Exercise 
   double output = pt->computeDistance(Point2D(0, 0), Point2D(-1, -1));

   //Verify
   assert(output < -1.4);
   assert(output > -1.42);


   //Teardown
   resetTests();
}


void unitTests::getMeters_x_1()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->x = 1;


   // Exercise 
   //Verify
   assert(pt->getMetersX() == 1);

   //Teardown
   resetTests();
}

void unitTests::getMeters_x_2()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->x = -1;


   // Exercise 
   //Verify
   assert(pt->getMetersX() == -1);

   //Teardown
   resetTests();
}

void unitTests::getMeters_y_1()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->y = 1;


   // Exercise 
   //Verify
   assert(pt->getMetersY() == 1);

   //Teardown
   resetTests();
}

void unitTests::getMeters_y_2()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->y = 1;


   // Exercise 
   //Verify
   assert(pt->getMetersY() == 1);

   //Teardown
   resetTests();
}


void unitTests::addMeters_x_1()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->x = 1;


   // Exercise 
   pt->addMetersX(1);
   
   //Verify
   assert(pt->getMetersX() == 1);

   //Teardown
   resetTests();
}

void unitTests::addMeters_x_2()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->x = 1;


   // Exercise 
   pt->addMetersX(-1);

   //Verify
   assert(pt->getMetersX() == 0);

   //Teardown
   resetTests();
}

void unitTests::addMeters_x_3()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->x = 0;


   // Exercise 
   pt->addMetersX(-1);

   //Verify
   assert(pt->getMetersX() == -1);

   //Teardown
   resetTests();
}

void unitTests::addMeters_y_1()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->y = 1;


   // Exercise 
   pt->addMetersY(1);

   //Verify
   assert(pt->getMetersY() == 2);

   //Teardown
   resetTests();
}

void unitTests::addMeters_y_2()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->y = 1;


   // Exercise 
   pt->addMetersY(-1);

   //Verify
   assert(pt->getMetersY() == 0);

   //Teardown
   resetTests();
}

void unitTests::addMeters_y_3()
{
   // Setup  
   resetTests();


   pt = new Point();
   assert(pt);
   pt->y = 0;


   // Exercise 
   pt->addMetersY(-1);

   //Verify
   assert(pt->getMetersY() == -1);

   //Teardown
   resetTests();
}

void unitTests::resetTests()
{

   if (obj)
   {
      delete obj;
      obj = nullptr;
   }
   if (pt)
   {
      delete pt;
      pt = nullptr;
   }

   assert(obj == nullptr);
   assert(pt == nullptr);
};