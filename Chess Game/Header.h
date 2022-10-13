#pragma once
#include <cassert>

#include "uiDraw.h"
#include "uiInteract.h"


class unitTests
{
public:
   void RunTests();




private:
   void test_setHoverPosition_1();
   void test_setHoverPosition_2();

   void test_positionFromXY_1();
   void test_positionFromXY_2();
   void test_positionFromXY_3();
   void test_positionFromXY_4();

   void test_clearSelectPosition();

   void test_clearPreviousPosition();

   void test_setSelectPosition_1();
   void test_setSelectPosition_2();
   void test_setSelectPosition_3();


   void test_drawPiece();

   Interface* p;
   ogstream* og;
};

void unitTests::RunTests()
{
   test_setHoverPosition_1();
   test_setHoverPosition_2();

   test_positionFromXY_1();
   test_positionFromXY_2();
   test_positionFromXY_3();
   test_positionFromXY_4();

   test_clearSelectPosition();

   test_clearPreviousPosition();

   test_setSelectPosition_1();
   test_setSelectPosition_2();
   test_setSelectPosition_3();


   ///
   test_drawPiece();
}



void unitTests::test_setHoverPosition_1()
{
  // Setup
   p = new Interface();
   assert(p);
   p->posHover = 10;
   

   // Exercise
   p->setHoverPosition(7);

   // verify
   assert(p->posHover == 7);



   //Teardown
   p = nullptr;
   assert(!p);
}

void unitTests::test_setHoverPosition_2()
{
   // Setup
   p = new Interface();
   assert(p);
   p->posHover = -10;


   // Exercise
   p->setHoverPosition(7);

   // verify
   assert(p->posHover == 7);



   //Teardown
   p = nullptr;
   assert(!p);
}

void unitTests::test_positionFromXY_1()
{
  // Setup
   p = new Interface();
   assert(p);
   p->widthScreen = 80;
   p->heightScreen = 80;


   assert(p->getSquareWidth() == 10);
   assert(p->getSquareHeight() == 10);

   // Exercise
   int t = p->positionFromXY(5, 5);

   

   // verify
   assert(t == 56);

   //Teardown
   p = nullptr;
   assert(!p);
}

void unitTests::test_positionFromXY_2()
{
   // Setup
   p = new Interface();
   assert(p);
   p->widthScreen = 80;
   p->heightScreen = 80;


   assert(p->getSquareWidth() == 10);
   assert(p->getSquareHeight() == 10);

   // Exercise
   int t = p->positionFromXY(-5, -5);



   // verify
   assert(t == 56);

   //Teardown
   p = nullptr;
   assert(!p);
}

void unitTests::test_positionFromXY_3()
{
   // Setup
   p = new Interface();
   assert(p);
   p->widthScreen = 80;
   p->heightScreen = 80;


   assert(p->getSquareWidth() == 10);
   assert(p->getSquareHeight() == 10);

   // Exercise
   int t = p->positionFromXY(-5, 5);



   // verify
   assert(t == 56);

   //Teardown
   p = nullptr;
   assert(!p);
}

void unitTests::test_positionFromXY_4()
{
   // Setup
   p = new Interface();
   assert(p);
   p->widthScreen = 80;
   p->heightScreen = 80;


   assert(p->getSquareWidth() == 10);
   assert(p->getSquareHeight() == 10);

   // Exercise
   int t = p->positionFromXY(5, -5);



   // verify
   assert(t == 56);

   //Teardown
   p = nullptr;
   assert(!p);
}

void unitTests::test_clearSelectPosition()
{
   // Setup
   p = new Interface();
   assert(p);
   p->posSelectPrevious = 5;
   p->posSelect = 5;


   assert(p->posSelectPrevious == 5);
   assert(p->posSelect == 5);


   // Exercise
   p->clearSelectPosition();


   // verify
   assert(p->posSelectPrevious == -1);
   assert(p->posSelect == -1);

   //Teardown
   p = nullptr;
   assert(!p);
}

void unitTests::test_clearPreviousPosition()
{
   // Setup
   p = new Interface();
   assert(p);
   p->posSelectPrevious = 5;
   assert(p->posSelectPrevious == 5);


   // Exercise
   p->clearPreviousPosition();


   // verify
   assert(p->posSelectPrevious == -1);


   //Teardown
   p = nullptr;
   assert(!p);
}

void unitTests::test_setSelectPosition_1()
{
   // Setup
   p = new Interface();
   assert(p);  
   p->posSelect = 5;
   p->posSelectPrevious = 5;

   assert(p->posSelect == 5);
   assert(p->posSelectPrevious == 5);


   // Exercise
   p->setSelectPosition(5);


   // verify
   assert(p->posSelect == 5);
   assert(p->posSelectPrevious == 5);
   //Teardown
   p = nullptr;
   assert(!p);
}

void unitTests::test_setSelectPosition_2()
{
   // Setup
   p = new Interface();
   assert(p);
   p->posSelect = 5;
   p->posSelectPrevious = 10;

   assert(p->posSelect == 5);
   assert(p->posSelectPrevious == 10);


   // Exercise
   p->setSelectPosition(5);


   // verify
   assert(p->posSelect == 5);
   assert(p->posSelectPrevious == 10);
   //Teardown
   p = nullptr;
   assert(!p);
}

void unitTests::test_setSelectPosition_3()
{
   // Setup
   p = new Interface();
   assert(p);
   p->posSelect = 5;
   p->posSelectPrevious = 10;

   assert(p->posSelect == 5);
   assert(p->posSelectPrevious == 10);


   // Exercise
   p->setSelectPosition(10);


   // verify
   assert(p->posSelect == 10);
   assert(p->posSelectPrevious == 5);

   //Teardown
   p = nullptr;
   assert(!p);
}

// OG TESTS
void unitTests::test_drawPiece()
{
   assert(og == nullptr);
   og = new ogstream();
   assert(og);


   //og.xgl
}