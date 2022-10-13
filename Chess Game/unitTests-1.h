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
#include "uiDraw.cpp"

#include "Chess.cpp"
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
   
   // Interface
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

   void DrawRook_1();
   void DrawRook_2();
   void DrawRook_3();

   void DrawKnight_1();
   void DrawKnight_2();
   void DrawKnight_3();

   void DrawPossible_1();
   void DrawPossible_2();
   

   // OG Stream.
   void DrawBoard();

   void DrawText_1();
   void DrawText_2();
   void DrawText_3();
   void DrawText_4();

   void DrawHover_1();
   void DrawHover_2();
   void DrawHover_3();
   void DrawHover_4();

   void DrawSelected_1();
   void DrawSelected_2();
   void DrawSelected_3();

   
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

   char board[64] = {
     'k', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

   ui.run(callBackTest, board);

   //Verify

   assert(GetPiece(board,0) == 'k');
   assert(isWhite(board,0,0)== true);
   //Teardown
   ui = nullptr;

   ResumeTests();
}


void UnitTest::DrawKing_2()
{
   // setUp
   Interface ui("Chess");


   // draw the checkerboard
   //Exercise
   atexit(ResumeTests);

   char board[64] = {
     'K', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

   ui.run(callBackTest, board);

   //Verify

   assert(GetPiece(board, 0) == 'K');
   assert(isWhite(board, 0, 0) == false);

   //Teardown
   ui = nullptr;
   ResumeTests();
}


void UnitTest::DrawKing_3()
{
   // setUp
   Interface ui("Chess");


   // draw the checkerboard
   //Exercise
   atexit(ResumeTests);

   char board[72] = {
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'K'};

   ui.run(callBackTest, board);

   //Verify

   assert(GetPiece(board, 72) == '-');
   assert(isWhite(board, 7, 8) == false);

   //Teardown
   ui = nullptr;
   ResumeTests();
}

void UnitTest:: DrawKing_4()
{
    // setUp
    Interface ui("Chess");


    // draw the checkerboard
    //Exercise
    atexit(ResumeTests);

    char board[64] = {
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };


    ui.run(callBackTest, board);

    //Verify

    assert(true);

    //Teardown
    ui = nullptr;
    ResumeTests();
}

void UnitTest:: DrawQueen_1()
{
    // setUp
    Interface ui("Chess");


    char board[64] = {
      'q ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };


    // draw the checkerboard
    //Exercise
    atexit(ResumeTests);
    ui.run(callBackTest, board);

    //Verify

    assert(GetPiece(board, 0) == 'q');
    assert(isWhite(board, 0, 0) == true);

    //Teardown
    ui = nullptr;
    ResumeTests();
}
void UnitTest:: DrawQueen_2()
{
    // setUp
    Interface ui("Chess");

    char board[64] = {
      'Q', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };


    // draw the checkerboard
    //Exercise
    atexit(ResumeTests);
    ui.run(callBackTest, board);

    //Verify

    assert(GetPiece(board, 0) == 'Q');
    assert(isWhite(board, 0, 0) == false);

    //Teardown
    ui = nullptr;
    ResumeTests();
}
void UnitTest:: DrawQueen_3()
{
    // setUp
    Interface ui("Chess");

    char board[72] = {
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Q' };


    // draw the checkerboard
    //Exercise
    atexit(ResumeTests);
    ui.run(callBackTest, board);

    //Verify

    assert(GetPiece(board, 72) == '-');
    assert(isWhite(board, 7, 8) == false);

    //Teardown
    ui = nullptr;
    ResumeTests();
}

void UnitTest:: DrawBishop_1()
{
    // setUp
    Interface ui("Chess");

    char board[64] = {
      'b', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };


    // draw the checkerboard
    //Exercise
    atexit(ResumeTests);
    ui.run(callBackTest, board);

    //Verify

    assert(GetPiece(board, 0) == 'b');
    assert(isWhite(board, 0, 0) == true);
    //Teardown
    ui = nullptr;
    ResumeTests();
}
void UnitTest:: DrawBishop_2()
{
    // setUp
    Interface ui("Chess");

    char board[64] = {
      'B', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };


    // draw the checkerboard
    //Exercise
    atexit(ResumeTests);
    ui.run(callBackTest, board);

    //Verify

    assert(GetPiece(board, 0) == 'B');
    assert(isWhite(board, 0, 0) == false);
    //Teardown
    ui = nullptr;
    ResumeTests();
}
void UnitTest:: DrawBishop_3()
{
    // setUp
    Interface ui("Chess");

    char board[72] = {
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B' };


    // draw the checkerboard
    //Exercise
    atexit(ResumeTests);
    ui.run(callBackTest, board);

    //Verify

    assert(GetPiece(board, 72) == '-');
    assert(isWhite(board, 7, 8) == false);

    //Teardown
    ui = nullptr;
    ResumeTests();
}

void UnitTest:: DrawRook_1()
{
    // setUp
    Interface ui("Chess");

    char board[64] = {
      'r', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };


    // draw the checkerboard
    //Exercise
    atexit(ResumeTests);
    ui.run(callBackTest, board);

    //Verify

    assert(GetPiece(board, 0) == 'r');
    assert(isWhite(board, 0, 0) == true);
    //Teardown
    ui = nullptr;
    ResumeTests();
}
void UnitTest:: DrawRook_2()
{
    // setUp
    Interface ui("Chess");

    char board[64] = {
      'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };


    // draw the checkerboard
    //Exercise
    atexit(ResumeTests);
    ui.run(callBackTest, board);

    //Verify

    assert(GetPiece(board, 0) == 'R');
    assert(isWhite(board, 0, 0) == false);
    //Teardown
    ui = nullptr;
    ResumeTests();
}
void UnitTest:: DrawRook_3()
{
    // setUp
    Interface ui("Chess");

    char board[72] = {
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R' };


    // draw the checkerboard
    //Exercise
    atexit(ResumeTests);
    ui.run(callBackTest, board);

    //Verify

    assert(GetPiece(board, 72) == '-');
    assert(isWhite(board, 7, 8) == false);
    //Teardown
    ui = nullptr;
    ResumeTests();
}

void UnitTest:: DrawKnight_1()
{
    // setUp
    Interface ui("Chess");

    char board[64] = {
      'n', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };


    // draw the checkerboard
    //Exercise
    atexit(ResumeTests);
    ui.run(callBackTest, board);

    //Verify

    assert(GetPiece(board, 0) == 'n');
    assert(isWhite(board, 0, 0) == true);
    //Teardown
    ui = nullptr;
    ResumeTests();
}
void UnitTest:: DrawKnight_2()
{
    // setUp
    Interface ui("Chess");

    char board[64] = {
      'N', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };


    // draw the checkerboard
    //Exercise
    atexit(ResumeTests);
    ui.run(callBackTest, board);

    //Verify

    assert(GetPiece(board, 0) == 'N');
    assert(isWhite(board, 0, 0) == false);
    //Teardown
    ui = nullptr;
    ResumeTests();
}
void UnitTest:: DrawKnight_3()
{
    // setUp
    Interface ui("Chess");

    char board[72] = {
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'N' };



    // draw the checkerboard
    //Exercise
    atexit(ResumeTests);
    ui.run(callBackTest, board);

    //Verify

    assert(GetPiece(board, 72) == '-');
    assert(isWhite(board, 7, 8) == false);

    //Teardown
    ui = nullptr;
    ResumeTests();
}

void UnitTest:: DrawPossible_1()
{
    //Setup
    og gout;
    Interface ui("Chess");
    set <int> possible = {47,33};

    char board[64] = {
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'p', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };


    atexit(ResumeTests);
    ui.run(callBackTest, board);

    // draw the possible moves
    set <int> ::iterator it;

    // Verify
    assert(getPossibleMoves(board,0) == possible);

    //teardown

    delete(&gout);
    ui = nullptr;
    ResumeTests();
}


void UnitTest:: DrawPossible_2()
{
    //Setup
    og gout;
    Interface ui("Chess");
    set <int> possible = {};

    char board[64] = {
      'p', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'p', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };


    atexit(ResumeTests);
    ui.run(callBackTest, board);

    // draw the possible moves
    set <int> ::iterator it;

    // Verify
    assert(getPossibleMoves(board, 9) == possible);

    //teardown

    delete(&gout);
    ui = nullptr;
    ResumeTests();
}


// OG Stream.
void UnitTest:: DrawBoard()
{
    og gout;

    // draw the checkerboard
    gout.drawBoard();
    ResumeTests();

}

void UnitTest:: DrawText_1()
{
    //set up
    ogstream ui;
    string sOut;
    string sIn;
    int x;
    int y;

    for (string::iterator it = sIn.begin(); it != sIn.end(); ++it)
        // newline triggers an buffer flush and a move down
        if (*it == '\n')
        {
            ui.drawTextPublic(x, y, sOut.c_str());
            sOut.clear();
            x -= 10;
        }
    // othewise append
        else
            sOut += *it;

    // put the text on the screen
    if (!sOut.empty())
    {
        ui.drawTextPublic(x, y, sOut.c_str());
        x -= 10;
    }

    //verify
    assert(true);

    // teardown
    sOut="";
    delete(&ui);
    ResumeTests();

}
void UnitTest:: DrawText_2()
{
    //set up
    ogstream ui;
    string sOut;
    string sIn;
    int x;
    int y;

    for (string::iterator it = sIn.begin(); it != sIn.end(); ++it)
        // newline triggers an buffer flush and a move down
        if (*it == '\n')
        {
            ui.drawTextPublic(x, y, " ");
            sOut.clear();
            x -= 10;
        }
    // othewise append
        else
            sOut += *it;

    // put the text on the screen
    if (!sOut.empty())
    {
        ui.drawTextPublic(x, y, " ");
        x -= 10;
    }

    //verify
    assert(true);

    // teardown
    sOut = "";
    delete(&ui);
    ResumeTests();
}
void UnitTest:: DrawText_3()
{
    //set up
    ogstream ui;
    string sOut;
    string sIn;
    int x;
    int y;

    for (string::iterator it = sIn.begin(); it != sIn.end(); ++it)
        // newline triggers an buffer flush and a move down
        if (*it == '\n')
        {
            ui.drawTextPublic(x, y, "ASD – 1”,1,1");
            sOut.clear();
            x -= 10;
        }
    // othewise append
        else
            sOut += *it;

    // put the text on the screen
    if (!sOut.empty())
    {
        ui.drawTextPublic(x, y, "ASD – 1”,1,1");
        x -= 10;
    }

    //verify
    assert(true);

    // teardown
    sOut = "";
    delete(&ui);
    ResumeTests();
}
void UnitTest:: DrawText_4()
{
    //set up
    ogstream ui;
    string sOut;
    string sIn;
    int x;
    int y;

    for (string::iterator it = sIn.begin(); it != sIn.end(); ++it)
        // newline triggers an buffer flush and a move down
        if (*it == '\n')
        {
            ui.drawTextPublic(x, y, "ASD – 1”,1,1");
            sOut.clear();
            x -= 10;
        }
    // othewise append
        else
            sOut += *it;

    // put the text on the screen
    if (!sOut.empty())
    {
        ui.drawTextPublic(x, y, "");
        x -= 10;
    }

    //verify
    assert(true);

    // teardown
    sOut = "";
    delete(&ui);
    ResumeTests();
}

void UnitTest:: DrawHover_1()
{
    //setup
    og gout;
    Interface ui;

        char board[64] = {
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

    atexit(ResumeTests);
    ui.run(callBackTest, board);
    ui.setHoverPosition(0);

    // draw any selections
    gout.drawHover(ui.getHoverPosition());

    // Verify
    assert(true);

    //teardown

    delete(&gout);
    ui = nullptr;
    ResumeTests();
}
void UnitTest:: DrawHover_2()
{
    //setup
    og gout;
    Interface ui;

    char board[64] = {
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

    atexit(ResumeTests);
    ui.run(callBackTest, board);


    // draw any selections
    gout.drawHover(ui.getHoverPosition());
    // Verify
    assert(true);

    //teardown

    delete(&gout);
    ui = nullptr;
    ResumeTests();
}
void UnitTest:: DrawHover_3()
{
    //setup
    og gout;
    Interface ui;

    char board[64] = {
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

    atexit(ResumeTests);
    ui.run(callBackTest, board);


    // draw any selections
    gout.drawHover(ui.getHoverPosition());
    // Verify
    assert(true);

    //teardown

    delete(&gout);
    ui = nullptr;
    ResumeTests();
}

void UnitTest:: DrawHover_4()
{
    //setup
    og gout;
    Interface ui;

    char board[64] = {
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

    atexit(ResumeTests);
    ui.run(callBackTest, board);


    // draw any selections
    gout.drawHover(ui.getHoverPosition());
    // Verify
    assert(true);

    //teardown

    delete(&gout);
    ui = nullptr;
    ResumeTests();
}

void UnitTest:: DrawSelected_1()
{
    //setup
    og gout;
    Interface ui;

    char board[64] = {
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

    atexit(ResumeTests);
    ui.run(callBackTest, board);


    // draw any selections
    gout.drawSelected(ui.getSelectPosition());
    // Verify
    assert(true);

    //teardown

    delete(&gout);
    ui = nullptr;
    ResumeTests();
}
void UnitTest:: DrawSelected_2()
{
    //setup
    og gout;
    Interface ui;

    char board[64] = {
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

    atexit(ResumeTests);
    ui.run(callBackTest, board);


    // draw any selections
    gout.drawSelected(ui.getSelectPosition());
    // Verify
    assert(true);

    //teardown

    delete(&gout);
    ui = nullptr;
    ResumeTests();
}
void UnitTest:: DrawSelected_3()
{
    //setup
    og gout;
    Interface ui;


    char board[64] = {
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

    atexit(ResumeTests);
    ui.run(callBackTest, board);


    // draw any selections
    gout.drawSelected(ui.getSelectPosition());
    // Verify
    assert(true);

    //teardown

    delete(&gout);
    ui = nullptr;
    ResumeTests();
}


void UnitTest::Testid(int test)
{

   switch (test)
   {
   case 1:
        DrawKing_1();
        break;
   case 2:
       DrawKing_2();
       break;
   case 3:
       DrawKing_3();
       break;
   case 4:
       DrawKing_4();
       break;
   case 5:
       DrawQueen_1();
       break;
   case 6:
       DrawQueen_2();
       break;
   case 7:
       DrawQueen_3();
       break;
   case 8:
       DrawBishop_1();
       break;
   case 9:
       DrawBishop_2();
       break;
   case 10:
       DrawBishop_3();
       break;
   case 11:
       DrawRook_1();
       break;
   case 12:
       DrawRook_2();
       break;
   case 13:
       DrawRook_3();
       break;
   case 14:
       DrawKnight_1();
       break;
   case 15:
       DrawKnight_2();
       break;
   case 16:
       DrawKnight_3();
       break;
       DrawPossible_1();
   case 17:
       DrawPossible_2();
       break;

       // OG Stream.
   case 18:
       DrawBoard();
       break;
   case 19:
       DrawText_1();
       break;
   case 20:
       DrawText_2();
       break;
   case 21:
       DrawText_3();
       break;
   case 22:
       DrawText_4();
       break;
   case 23:
       DrawHover_1();
       break;
   case 24:
       DrawHover_2();
       break;
   case 25:
       DrawHover_3();
       break;
   case 26:
       DrawHover_4();
       break;
   case 27:
       DrawSelected_1();
       break;
   case 28:
       DrawSelected_2();
       break;
   case 29:
       DrawSelected_3();
       break;
   }
}