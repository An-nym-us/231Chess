///***********************************************************************
// * Header File:
// *    Test Point2D : Test the Point2D class
// * Author:
// *    Br. Helfrich
// * Summary:
// *    All the unit tests for Point2D
// ************************************************************************/
//
//
//#pragma once
//
//#include <iostream>
//#include "point.h"
//#include <cassert>
//
//using namespace std;
//
///*******************************
// * TEST Point2D
// * A friend class for Point2D which contains the Point2D unit tests
// ********************************/
//class TestPosition
//{
//public:
//   void run()
//   {
//      Point2D().setZoom(1000.0 /* 1km equals 1 pixel */);
//      defaultConstructor();
//      nonDefaultConstructor();
//      copyConstructor();
//      assignment();
// 
//      setPixels();
//      setMeters();
//      
//      addPixels();
//      addMeters();
//   }
//   
//private:
//   // utility funciton because floating point numbers are approximations
//   bool closeEnough(double value, double test, double tolerence) const
//   {
//      double difference = value - test;
//      return (difference >= -tolerence) && (difference <= tolerence);
//   }
//
//   void defaultConstructor() const
//   {  // setup
//      // exercise
//      Point2D pos;
//      // verify
//      assert(pos.x == 0.0);
//      assert(pos.y == 0.0);
//   }  // teardown
//
//   void nonDefaultConstructor() const
//   {  // setup
//      // exercise
//      Point2D pos(3000.0, 9000.0);
//      // verify
//      assert(pos.x == 3000.0);
//      assert(pos.y == 9000.0);
//   }  // teardown
//
//   void copyConstructor() const
//   {  // setup
//      Point2D pos1;
//      pos1.x = 4000.0;
//      pos1.y = 2000.0;
//      // exercise
//      Point2D pos2(pos1);
//      // verify
//      assert(pos1.x == 4000.0);
//      assert(pos1.y == 2000.0);
//      assert(pos2.x == 4000.0);
//      assert(pos2.y == 2000.0);
//   }  // teardown
//
//   void assignment() const
//   {  // setup
//      Point2D pos1;
//      pos1.x = 4000.0;
//      pos1.y = 2000.0;
//      // exercise
//      Point2D pos2 = pos1;
//      // verify
//      assert(pos1.x == 4000.0);
//      assert(pos1.y == 2000.0);
//      assert(pos2.x == 4000.0);
//      assert(pos2.y == 2000.0);
//   }  // teardown
//   
//   void setMeters() const
//   {  // setup
//      Point2D pos;
//      pos.x = 0.0;
//      pos.y = 0.0;
//      // exercise
//      pos.setMetersX(5000.0);
//      pos.setMetersY(3000.0);
//      // verify
//      assert(pos.x == 5000.0);
//      assert(pos.y == 3000.0);
//   }  // teardown
// 
//   void setPixels() const
//   {  // setup
//      Point2D pos;
//      pos.x = 0.0;
//      pos.y = 0.0;
//      // exercise
//      pos.setPixelsX(6.0);
//      pos.setPixelsY(12.0);
//      // verify
//      assert(pos.x == 6000.0);
//      assert(pos.y == 12000.0);
//   }  // teardown
//   
//   void addMeters() const
//   {  // setup
//      Point2D pos;
//      pos.x = 800.0;
//      pos.y = 1600.0;
//      // exercise
//      pos.addMetersX(-400.0);
//      pos.addMetersY(800.0);
//      // verify
//      assert(pos.x == 400.0);
//      assert(pos.y == 2400.0);
//   }  // teardown
//   
//   void addPixels() const
//   {  // setup
//      Point2D pos;
//      pos.x = 2000.0;
//      pos.y = 4000.0;
//      // exercise
//      pos.addPixelsX(2);
//      pos.addPixelsY(3);
//      // verify
//      assert(pos.x == 4000.0);
//      assert(pos.y == 7000.0);
//   }  // teardown
//
//};
