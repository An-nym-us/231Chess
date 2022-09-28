#pragma once

#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include <memory>
#include <chrono>
#include <thread>

#include "uiDraw.h"
#include "uiInteract.h"
class UnitTest;
typedef ogstream og;
using namespace std;

int counter = 0;
int testID = 1;





class UnitTest 
{
public:


   void Testid(int test);

private:
   

   void DrawKing_1();
   void DrawKing_2();
   void DrawKing_3();
   void DrawKing_4();

   void DrawQueen_1();
   void DrawQueen_2();
   void DrawQueen_3();

   void DrawBishop_1();
   void DrawBishop_2();
   void DrawBishop_3();
   
   
   char board[64] = {
     'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
     'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
     'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
   };


};
inline void RunTests()
{
   UnitTest temp = UnitTest();
   temp.Testid(testID);

}


void ResumeTests()
{
   testID++;
   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
   RunTests();
}






void drawTest(const char* board, const Interface& ui, const set <int>& possible)
{
   og gout;

   // draw the checkerboard
   gout.drawBoard();

   // draw any selections
   gout.drawHover(ui.getHoverPosition());
   gout.drawSelected(ui.getSelectPosition());

   // draw the possible moves
   set <int> ::iterator it;
   for (it = possible.begin(); it != possible.end(); ++it)
      gout.drawPossible(*it);

   // draw the pieces
   for (int i = 0; i < 64; i++)
      switch (board[i])
      {
      case 'P':
         gout.drawPawn(i, true);
         break;
      case 'p':
         gout.drawPawn(i, false);
         break;
      case 'K':
         gout.drawKing(i, true);
         break;
      case 'k':
         gout.drawKing(i, false);
         break;
      case 'Q':
         gout.drawQueen(i, true);
         break;
      case 'q':
         gout.drawQueen(i, false);
         break;
      case 'R':
         gout.drawRook(i, true);
         break;
      case 'r':
         gout.drawRook(i, false);
         break;
      case 'B':
         gout.drawBishop(i, true);
         break;
      case 'b':
         gout.drawBishop(i, false);
         break;
      case 'N':
         gout.drawKnight(i, true);
         break;
      case 'n':
         gout.drawKnight(i, false);
         break;
      }
};

         
void callBackTest(Interface* pUI, void* p)
{
   set <int> possible;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   char* board = (char*)p;
   counter++;
   if (counter == 20)
   {
      counter = 0;
      exit(-1);
   }



   // draw the board
   drawTest(board, *pUI, possible);
   
}


void UnitTest::DrawKing_1()
{
   // setUp
   Interface ui("Chess");


   // draw the checkerboard
   //Exercise
   atexit(ResumeTests);
   ui.run(callBackTest, board);

   //Verify


   //Teardown
    ui;
   //ogin = nullptr;
   //assert(ogin == nullptr);
}
void UnitTest::DrawKing_2()
{
   // setUp
   Interface ui("Chess");


   // draw the checkerboard
   //Exercise
   atexit(ResumeTests);
   ui.run(callBackTest, board);

   //Verify


   //Teardown
   ui;
   //ogin = nullptr;
   //assert(ogin == nullptr);
}
void UnitTest::DrawKing_3()
{
   // setUp
   Interface ui("Chess");


   // draw the checkerboard
   //Exercise
   atexit(ResumeTests);
   ui.run(callBackTest, board);

   //Verify


   //Teardown
   ui;
   //ogin = nullptr;
   //assert(ogin == nullptr);
}

void UnitTest::Testid(int test)
{

   switch (test)
   {
   case 1:
      DrawKing_1();
   case 2:
       DrawKing_2();
   case 3 :
       DrawKing_3();
   default :
      break;
   }
}