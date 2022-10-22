
/**********************************************************************
 * Chess: main
 *
 * Authors:
 *  Jonathan Lee Gunderson
 *  Alex Michael Jacobs
 *
 * Description::
 * Main location for chess functions
 *
 **********************************************************************/

#include "unitTest.h"
#include "location.h"


#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for draw*
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
using namespace std;


/****************************************************
 * IS NOT WHITE
 * Is the current location valid and the piece is either
 * black (uppercase) or space
 ***************************************************/
inline bool isNotWhite(const char* board, Location loc )
{
   // not white if we are off the board or if we are looking at a space
   if (loc.getRow() < 0 || loc.getRow() >= 8 || loc.getCol() < 0 || loc.getCol() >= 8)
      return false;

  // const int temp = static_cast<int> (loc.getRow() * 8+ loc.getCol());
   char piece = board[static_cast<int> (loc.getRow() * 8 + loc.getCol())];

   return piece == ' ' || (piece >= 'A' && piece <= 'Z');
}

/****************************************************
 * IS  WHITE
 * Is the current location valid and the piece is white
 ***************************************************/

inline bool isWhite(const char* board, Location loc)
{
   // not white if we are off the board or if we are looking at a space
   if (loc.getRow() < 0 || loc.getRow() >= 8 || loc.getCol() < 0 || loc.getCol() >= 8)
      return false;
  // static_cast<int> (loc.getRow() * 8 + loc.getCol());
   char piece = board[static_cast<int> (loc.getRow() * 8 + loc.getCol())];

   return (piece >= 'a' && piece <= 'z');
}

/****************************************************
 * IS NOT BLACK
 * Is the current location valid and the piece is either
 * white (lowercase) or space
 ***************************************************/
inline bool isNotBlack(const char* board, Location loc)
{
   // not white if we are off the board or if we are looking at a space
   if (loc.getRow() < 0 || loc.getRow() >= 8 || loc.getCol() < 0 || loc.getCol() >= 8)
      return false;
   char piece = board[  static_cast<int> (loc.getRow() * 8 + loc.getCol())];

   return piece == ' ' || (piece >= 'a' && piece <= 'z');
}


/****************************************************
 * IS  BLACK
 * Is the current location valid and the piece is black
 ***************************************************/
inline bool isBlack(const char* board, Location loc)
{
   // not white if we are off the board or if we are looking at a space
   if (loc.getRow() < 0 || loc.getRow() >= 8 || loc.getCol() < 0 || loc.getCol() >= 8)
      return false;
   char piece = board[static_cast<int> (loc.getRow() * 8 + loc.getCol())];

   return (piece >= 'A' && piece <= 'Z');
}

/*********************************************************
 * GET POSSIBLE MOVES
 * Determine all the possible moves for a given chess piece
 *********************************************************/
set <int> getPossibleMoves(const char* board, int locationPassed)
{
   set <int> possible;


   Location loc(locationPassed); // row col
   Location loc2Chek; // rc
   Location list[8];

   // return the empty set if there simply are no possible moves
   if (loc.locationFlattened() < 0 || loc.locationFlattened() >= 64 || board[static_cast<int>(loc.locationFlattened())] == ' ')
      return possible;

   bool amBlack = isBlack(board, loc);

   //
   // PAWN
   //
   if (board[static_cast<int>(loc.locationFlattened())] == 'P')
   {
      loc2Chek = loc;

      loc2Chek.setRow(loc.getRow() - 2);

      if (loc.getRow() == 6 && board[static_cast<int>(loc2Chek.locationFlattened())] == ' ')
         possible.insert(static_cast<int>(loc2Chek.locationFlattened()));  // forward two blank spaces
   
      loc2Chek.setRow(loc.getRow() - 1);
      if (loc2Chek.getRow() >= 0 && board[static_cast<int>(loc2Chek.locationFlattened())] == ' ')
         possible.insert(static_cast<int>(loc2Chek.locationFlattened()));  // forward one black space
     

      loc2Chek.setCol(loc.getCol() - 1);
      if (isWhite(board, loc2Chek))
         possible.insert(static_cast<int>(loc2Chek.locationFlattened()));    // attack left
      loc2Chek.setCol(loc.getCol() + 1);

      if (isWhite(board, loc2Chek))
         possible.insert(static_cast<int>(loc2Chek.locationFlattened()));    // attack right
      
   }
   if (board[static_cast<int>(loc.locationFlattened())] == 'p')
   {
      //c = col;
      //r = row + 2;
      loc2Chek = loc;
      loc2Chek.setRow(loc.getRow() + 2);
      if (loc.getRow() == 1 && board[static_cast<int>(loc2Chek.locationFlattened())] == ' ')
         possible.insert(static_cast<int>(loc2Chek.locationFlattened()));  // forward two blank spaces
      
      //r = row + 1;
      loc2Chek.setRow(loc.getRow() + 1);
      if (loc2Chek.getRow() < 8 && board[static_cast<int>(loc2Chek.locationFlattened())] == ' ')
         possible.insert(static_cast<int>(loc2Chek.locationFlattened()));    // forward one blank space
   
      //  c = col - 1;
      loc2Chek.setCol(loc.getCol() - 1);

      if (isBlack(board, loc2Chek))
         possible.insert(static_cast<int>(loc2Chek.locationFlattened()));      // attack left
     
      // c = col + 1;
      loc2Chek.setCol(loc.getCol() + 1);
      if (isBlack(board, loc2Chek))
         possible.insert(static_cast<int>(loc2Chek.locationFlattened()));      // attack right
      // what about en-passant and pawn promotion
   }

   //
   // KNIGHT
   //
   if (board[static_cast<int>(loc.locationFlattened())] == 'N' || board[static_cast<int>(loc.locationFlattened())] == 'n')
   {

      list[0] = Location(-1, 2);
      list[1] = Location(1, 2);
      list[2] = Location(-2, 1);
      list[3] = Location(2, 1);
      list[4] = Location(-2, -1);
      list[5] = Location(2, -1);
      list[6] = Location(-1, -2);
      list[7] = Location(1, -2);



      for (int i = 0; i < 8; i++)
      {
         loc2Chek.addLocations(loc, list[i]);

         if ( amBlack && isNotBlack(board, loc2Chek))
            possible.insert(loc2Chek.locationFlattened());
         if (!amBlack && isNotWhite(board, loc2Chek))
            possible.insert(loc2Chek.locationFlattened());
      }
   }

   //
   // KING
   //
   if (board[static_cast<int>(loc.locationFlattened())] == 'K' || board[static_cast<int>(loc.locationFlattened())] == 'k')
   {

      list[0] = Location(-1, 1);
      list[1] = Location(0, 1);
      list[2] = Location(1, 1);
      list[3] = Location(1, 0);
      list[4] = Location(-1, 0);
      list[5] = Location(-1, -1);
      list[6] = Location(0, -1);
      list[7] = Location(1, -1);
      for (int i = 0; i < 8; i++)
      {
         loc2Chek.addLocations(loc, list[i]);

         if ( amBlack && isNotBlack(board, loc2Chek))
            possible.insert(loc2Chek.locationFlattened());
         if (!amBlack && isNotWhite(board, loc2Chek))
            possible.insert(loc2Chek.locationFlattened());
      }

   }

   //
   // QUEEN
   //
   if (board[static_cast<int>(loc.locationFlattened())] == 'Q' || board[static_cast<int>(loc.locationFlattened())] == 'q')
   {
      list[0] = Location(-1, 1);
      list[1] = Location(0, 1);
      list[2] = Location(1, 1);
      list[3] = Location(1, 0);
      list[4] = Location(-1, 0);
      list[5] = Location(-1, -1);
      list[6] = Location(0, -1);
      list[7] = Location(1, -1);

      for (int i = 0; i < 8; i++)
      {
         loc2Chek.setRow(loc.getRow() + list[i].getRow());
         loc2Chek.setCol(loc.getCol() + list[i].getCol());

         while (loc2Chek.getRow() >= 0 && loc2Chek.getRow() < 8 && loc2Chek.getCol() >= 0 && loc2Chek.getCol() < 8 &&
                board[static_cast<int>(loc2Chek.locationFlattened())] == ' ')
         {
            possible.insert(loc2Chek.locationFlattened());
            
            loc2Chek.addrow(list[i].getRow());
            loc2Chek.addCol(list[i].getCol());
         }
         if ( amBlack && isNotBlack(board, loc2Chek))
            possible.insert(loc2Chek.locationFlattened());
         if (!amBlack && isNotWhite(board, loc2Chek))
            possible.insert(loc2Chek.locationFlattened());
      }
   }

   //
   // ROOK
   //
   if (board[static_cast<int>(loc.locationFlattened())] == 'R' || board[static_cast<int>(loc.locationFlattened())] == 'r')
   {
      list[0] = Location(0, 1);
      list[1] = Location(-1, 0);
      list[2] = Location(1, 0);
      list[3] = Location(0, -1);

      for (int i = 0; i < 4; i++)
      {
         loc2Chek.setRow(loc.getRow() + list[i].getRow());
         loc2Chek.setCol(loc.getCol() + list[i].getCol());

         while (loc2Chek.getRow() >= 0 && loc2Chek.getRow() < 8 && loc2Chek.getCol() >= 0 && loc2Chek.getCol() < 8 &&
            board[static_cast<int>(loc2Chek.locationFlattened())] == ' ')
         {
            possible.insert(loc2Chek.locationFlattened());
            loc2Chek.addrow(list[i].getRow());
            loc2Chek.addCol(list[i].getCol());
         }
         if (amBlack && isNotBlack(board, loc2Chek))
            possible.insert(loc2Chek.locationFlattened());
         if (!amBlack && isNotWhite(board, loc2Chek))
            possible.insert(loc2Chek.locationFlattened());
      }
   }

   //
   // BISHOP
   //
   if (board[static_cast<int>(loc.locationFlattened())] == 'B' || board[static_cast<int>(loc.locationFlattened())] == 'b')
   {
      list[0] = Location(-1, 1);
      list[1] = Location(1,1);
      list[2] = Location(-1,-1);
      list[3] = Location(1, -1);

      for (int i = 0; i < 4; i++)
      {
         loc2Chek.setRow(loc.getRow() + list[i].getRow());
         loc2Chek.setCol(loc.getCol() + list[i].getCol());
         while (loc2Chek.getRow() >= 0 && loc2Chek.getRow() < 8 && loc2Chek.getCol() >= 0 && loc2Chek.getCol() < 8 &&
            board[static_cast<int>(loc2Chek.locationFlattened())] == ' ')
         {
            possible.insert(loc2Chek.locationFlattened());
            loc2Chek.addrow(list[i].getRow());
            loc2Chek.addCol(list[i].getCol());
         }
         if (amBlack && isNotBlack(board, loc2Chek))
            possible.insert(loc2Chek.locationFlattened());
         if (!amBlack && isNotWhite(board, loc2Chek))
            possible.insert(loc2Chek.locationFlattened());
      }
   }

   return possible;
}

/***************************************************
 * DRAW
 * Draw the current state of the game
 ***************************************************/
void draw(const char* board, const Interface & ui, const set <int> & possible)
{
   ogstream gout;
   
   // draw the checkerboard
   gout.drawBoard();

   // draw any selections
   gout.drawHover(ui.getHoverPosition());
   gout.drawSelected(ui.getSelectPosition());

   // draw the possible moves
   set <int> :: iterator it;
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
}

/*********************************************
 * MOVE 
 * Execute one movement. Return TRUE if successful
 *********************************************/
bool move(char* board, int positionFrom, int positionTo)
{
   // do not move if a move was not indicated
   if (positionFrom == -1 || positionTo == -1)
      return false;
   assert(positionFrom >= 0 && positionFrom < 64);
   assert(positionTo >= 0 && positionTo < 64);


   // find the set of possible moves from our current location
   set <int> possiblePrevious = getPossibleMoves(board, positionFrom);

   // only move there is the suggested move is on the set of possible moves
   if (possiblePrevious.find(positionTo) != possiblePrevious.end())
   {
      board[positionTo] = board[positionFrom];
      board[positionFrom] = ' ';
      return true;
   }

   return false;

}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface *pUI, void * p)
{
   set <int> possible;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   char * board = (char *)p;  

   // move 
   if (move(board, pUI->getPreviousPosition(), pUI->getSelectPosition()))
      pUI->clearSelectPosition();
   else
      possible = getPossibleMoves(board, pUI->getSelectPosition());

   // if we clicked on a blank spot, then it is not selected
   if (pUI->getSelectPosition() != -1 && board[pUI->getSelectPosition()] == ' ')
      pUI->clearSelectPosition();

   // draw the board
   draw(board, *pUI, possible);

}

/********************************************************
 * PARSE
 * Determine the nature of the move based on the input.
 * This is the only function understanding Smith notation
 *******************************************************/
void parse(const string& textMove, int& positionFrom, int& positionTo)
{
   string::const_iterator it = textMove.cbegin();

   // get the source
   int col = *it - 'a';
   it++;
   int row = *it - '1';
   it++;
   positionFrom = row * 8 + col;

   // get the destination
   col = *it - 'a';
   it++;
   row = *it - '1';
   it++;
   positionTo = row * 8 + col;

   // capture and promotion information
   char capture = ' ';
   char piecePromotion = ' ';
   bool castleK = false;
   bool castleQ = false;
   bool enpassant = false;
   for (; it != textMove.end(); ++it)
   {
      switch (*it)
      {
      case 'p':   // capture a pawn
      case 'n':   // capture a knight
      case 'b':   // capture a bishop
      case 'r':   // capture a rook
      case 'q':   // capture a queen
      case 'k':   // !! you can't capture a king you silly!
         capture = tolower(*it);
         break;

      case 'c':  // short castling or king's castle
         castleK = true;
         break;
      case 'C':  // long castling or queen's castle
         castleQ = true;
         break;
      case 'E':  // En-passant
         enpassant = true;
         break;

      case 'N':  // Promote to knight
      case 'B':  // Promote to Bishop
      case 'R':  // Promote to Rook
      case 'Q':  // Promote to Queen
         piecePromotion = *it;
         break;

      }
   }

   // error checking
   if (positionFrom < 0 || positionFrom >= 64 ||
       positionTo   < 0 || positionTo   >= 64)
      positionFrom = positionTo = -1;
}

/********************************************************
 * READ FILE
 * Read a file where moves are encoded in Smith notation
 *******************************************************/
void readFile(const char* fileName, char* board)
{
   // open the file
   ifstream fin(fileName);
   if (fin.fail())
      return;

   // read the file, one move at a time
   string textMove;
   bool valid = true;
   while (valid && fin >> textMove)
   {
      int positionFrom;
      int positionTo;
      parse(textMove, positionFrom, positionTo);
      valid = move(board, positionFrom, positionTo);
   }

   // close and done
   fin.close();
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   UnitTest().RunTests();

   
   Interface ui("Chess");    

   // Initialize the game class
   // note this is upside down: 0 row is at the bottom
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
   
#ifdef _WIN32
 //  int    argc;
 //  LPWSTR * argv = CommandLineToArgvW(GetCommandLineW(), &argc);
 //  string filename = argv[1];
   if (__argc == 2)
      readFile(__argv[1], board);
#else // !_WIN32
   if (argc == 2)
      readFile(argv[1], board);
#endif // !_WIN32

   // set everything into action
   ui.run(callBack, board);             

   return 0;
}
