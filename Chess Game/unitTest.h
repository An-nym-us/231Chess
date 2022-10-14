#pragma once
/**********************************************************************
 * Unit Tests:
 * 
 * Authors:
 *  Jonathan Lee Gunderson
 *  Alex Michael Jacobs
 * 
 * Description::
 * Run unit test at runtime to validate and confirm critical 
 * functions within the code are working as intended
 * 
 **********************************************************************/
#include <cassert>
#include "chessCritical.h"
#include "uiInteract.h"


class UnitTest
{
public:
   void RunTests();
private:
    
   bool validateBoard(char board[64]);
   void resetBoard();



   // Unit tests //
   
   // Inerface
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


   // GameLogic
   void test_isNotWhite_1();
   void test_isNotWhite_2();

   void test_isWhite_1();
   void test_isWhite_2();

   void test_isNotBlack_1();
   void test_isNotBlack_2();

   void test_isBlack_1();
   void test_isBlack_2();

   void test_move_1();
   void test_move_2();


   // Varibles
   Interface* p;
   CriticalMethods* CCM;

   char board[64] = {
   'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
   'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
   'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
   };
};




bool UnitTest::validateBoard(char boardPassed[64])
{
   const char boardCheck[64] = 
   {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
   };


   for (int i = 0; i < 64; i++)
   {
      if (boardPassed[i] != boardCheck[i])
         return false;
   }

   return true; 
}

void UnitTest::resetBoard()
{
   const char boardReset[64] =
   {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
   };


   for (int i = 0; i < 64; i++)
   {
      board[i] = boardReset[i];
   }

}


/*
* Runner
*/
void UnitTest::RunTests()
{
   // Test Interface
   test_setHoverPosition_1();
   test_setHoverPosition_2();

   test_positionFromXY_1();
   test_positionFromXY_2();
   test_positionFromXY_3();
   test_positionFromXY_4();

   test_setSelectPosition_1();
   test_setSelectPosition_2();
   test_setSelectPosition_3();

   test_clearSelectPosition();

   test_clearPreviousPosition();



   // Test GameLogic
   test_isNotWhite_1();
   test_isNotWhite_2();

   test_isWhite_1();
   test_isWhite_2();

   test_isNotBlack_1();
   test_isNotBlack_2();

   test_isBlack_1();
   test_isBlack_2();

   test_move_1();
   test_move_2();
}


// Chess Interface Tests
void UnitTest::test_setHoverPosition_1()
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

void UnitTest::test_setHoverPosition_2()
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

void UnitTest::test_positionFromXY_1()
{
  // Setup
   p = new Interface();
   assert(p);
   p->widthScreen = 256;
   p->heightScreen = 256;


   assert(p->getSquareWidth() == 32);
   assert(p->getSquareHeight() == 32);

   // Exercise
   int t = p->positionFromXY(5, 5);

   

   // verify
   assert(t == 56);

   //Teardown
   p = nullptr;
   assert(!p);
}

void UnitTest::test_positionFromXY_2()
{
   // Setup
   p = new Interface();
   assert(p);
   p->widthScreen = 256;
   p->heightScreen = 256;


   assert(p->getSquareWidth() == 32);
   assert(p->getSquareHeight() == 32);

   // Exercise
   int t = p->positionFromXY(-5, -5);



   // verify
   assert(t == 56);

   //Teardown
   p = nullptr;
   assert(!p);
}

void UnitTest::test_positionFromXY_3()
{
   // Setup
   p = new Interface();
   assert(p);
   p->widthScreen = 256;
   p->heightScreen = 256;


   assert(p->getSquareWidth() == 32);
   assert(p->getSquareHeight() ==32);

   // Exercise
   int t = p->positionFromXY(-5, 5);



   // verify
   assert(t == 56);

   //Teardown
   p = nullptr;
   assert(!p);
}

void UnitTest::test_positionFromXY_4()
{
   // Setup
   p = new Interface();
   assert(p);
   p->widthScreen = 256;
   p->heightScreen = 256;


   assert(p->getSquareWidth() ==32);
   assert(p->getSquareHeight() == 32);

   // Exercise
   int t = p->positionFromXY(5, -5);



   // verify
   assert(t == 56);

   //Teardown
   p = nullptr;
   assert(!p);
}

void UnitTest::test_clearSelectPosition()
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

void UnitTest::test_clearPreviousPosition()
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

void UnitTest::test_setSelectPosition_1()
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

void UnitTest::test_setSelectPosition_2()
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

void UnitTest::test_setSelectPosition_3()
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



// Chess Methods TESTS
void UnitTest::test_isNotWhite_1()
{
   // Setup
   assert(CCM == nullptr);
   CCM = new CriticalMethods();
   assert(CCM);
   assert(validateBoard(board));


   // Exercise
   // verify
   assert( !CCM->isNotWhite(board, 1, 1) );



   //Teardown
   resetBoard();
   assert(validateBoard(board));
   CCM = nullptr;
   assert(!CCM);
}

void UnitTest::test_isNotWhite_2()
{
   // Setup
   assert(CCM == nullptr);
   CCM = new CriticalMethods();
   assert(CCM);
   assert(validateBoard(board));


   // Exercise
   // verify
   assert(CCM->isNotWhite(board, 7,7));



   //Teardown
   resetBoard();
   assert(validateBoard(board));
   CCM = nullptr;
   assert(!CCM);
}

void UnitTest::test_isWhite_1()
{
   // Setup
   assert(CCM == nullptr);
   CCM = new CriticalMethods();
   assert(CCM);
   assert(validateBoard(board));


   // Exercise
   // verify
   assert(CCM->isWhite(board, 1, 1));



   //Teardown
   resetBoard();
   assert(validateBoard(board));
   CCM = nullptr;
   assert(!CCM);
}

void UnitTest::test_isWhite_2()
{
   // Setup
   assert(CCM == nullptr);
   CCM = new CriticalMethods();
   assert(CCM);
   assert(validateBoard(board));


   // Exercise
   // verify
   assert(!CCM->isWhite(board, 7, 7));



   //Teardown
   resetBoard();
   assert(validateBoard(board));
   CCM = nullptr;
   assert(!CCM);
}

void UnitTest::test_isNotBlack_1()
{
   // Setup
   assert(CCM == nullptr);
   CCM = new CriticalMethods();
   assert(CCM);
   assert(validateBoard(board));


   // Exercise
   // verify
   assert(CCM->isNotBlack(board, 1, 1));



   //Teardown
   resetBoard();
   assert(validateBoard(board));
   CCM = nullptr;
   assert(!CCM);
}

void UnitTest::test_isNotBlack_2()
{
   // Setup
   assert(CCM == nullptr);
   CCM = new CriticalMethods();
   assert(CCM);
   assert(validateBoard(board));


   // Exercise
   // verify
   assert(!CCM->isNotBlack(board, 7, 7));



   //Teardown
   resetBoard();
   assert(validateBoard(board));
   CCM = nullptr;
   assert(!CCM);
}

void UnitTest::test_isBlack_1()
{
   // Setup
   assert(CCM == nullptr);
   CCM = new CriticalMethods();
   assert(CCM);
   assert(validateBoard(board));


   // Exercise
   // verify
   assert(!CCM->isBlack(board, 1, 1));



   //Teardown
   resetBoard();
   assert(validateBoard(board));
   CCM = nullptr;
   assert(!CCM);
}

void UnitTest::test_isBlack_2()
{
   // Setup
   assert(CCM == nullptr);
   CCM = new CriticalMethods();
   assert(CCM);
   assert(validateBoard(board));


   // Exercise
   // verify




   //Teardown
   resetBoard();
   assert(validateBoard(board));
   CCM = nullptr;
   assert(!CCM);
}

void UnitTest::test_move_1()
{
   // Setup
   assert(CCM == nullptr);
   CCM = new CriticalMethods();
   assert(CCM);
   assert(validateBoard(board));


   // Exercise
   // verify
  assert(CCM->move(board,8, 16));



   //Teardown
   resetBoard();
   assert(validateBoard(board));
   CCM = nullptr;
   assert(!CCM);
}

void UnitTest::test_move_2()
{
   // Setup
   assert(CCM == nullptr);
   CCM = new CriticalMethods();
   assert(CCM);
   assert(validateBoard(board));


   // Exercise
   // verify
   assert(!CCM->move(board, 8, 15));



   //Teardown
   resetBoard();
   assert(validateBoard(board));
   CCM = nullptr;
   assert(!CCM);
}