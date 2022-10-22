
#pragma once
/**********************************************************************
 * Chess:ocation Class
 *
 * Authors:
 *  Jonathan Lee Gunderson
 *  Alex Michael Jacobs
 *
 * Description::
 * class that allows for easy manipulation of 2D location
 *
 **********************************************************************/


class Location
{
public:
   // constructors
   Location() : col(0), row(0) {}
   Location(double x, double y);
   Location(double xy)  {   locationTransposed(xy);  }
   Location(const Location &locationPassed)   {   this->col = locationPassed.col;  this->row = locationPassed.row;  }
   Location( int i, int j) : col(i), row(j) {};

   // getters
   double getCol()       const { return col; }
   double getRow()       const { return row; }
   double locationFlattened() const { return row * 8 + col; }

   // setters
   void setCol(double col) { this->col = col; }
   void setRow(double row) { this->row = row; }

   void locationTransposed(int loc) 
   {
      this->row = loc / 8;
      this->col = loc % 8;
   } 
   void resetLocation() { this->row = 0; this->col = 0; }

   // operations
   void addCol(double col) { this->col += col; }
   void addrow(double row) { this->col += row; }
   void addLocations(Location loc1, Location loc2)
   {
      this->col = loc1.col + loc2.col;
      this->row = loc1.row + loc2.row;
   }

   Location operator = ( Location& loc)
   {
      this->col = loc.col;
      this->row = loc.row;
      return *this;
   }
   Location operator + (const Location& loc)
   {
      this->col += loc.col;
      this->row += loc.row;
      return Location(*this);
   }
   Location operator - (const Location& loc)
   {
      this->col -= loc.col;
      this->row -= loc.row;
      return *this;
   }
   template<typename T, int i>
   Location operator + (const T loc[i])
   {
      this->col += loc[i].col;
      this->row += loc[i].row;
      return Location(*this);
   }



private:
   double col;           // horizontal position
   double row;           // vertical position
};


