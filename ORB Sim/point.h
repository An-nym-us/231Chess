#pragma once





#include <iostream> 
#include <cmath>




/*********************************************
 * Point
 * A single position on the field in Meters
 *********************************************/
class Point
{
    friend class unitTests;
public:


   // constructors
   Point() : x(0.0), y(0.0) {}
   Point(double x, double y) { this->x = x; this->y = y; }
   Point(const Point& pt) : x(pt.x), y(pt.y) {}

   Point operator = (Point pt)
   {
      Point temp;
      temp.x = pt.getMetersX();
      temp.y = pt.getMetersY();
      return temp   ;
   }

   Point operator + (Point rhs)
   {
      Point temp;
      temp.x = rhs.getMetersX();
      temp.y = rhs.getMetersY();

      temp.x += this->x;
      temp.y += this->y;
      return temp;
   }

   // getters
   double getMetersX()       const { return x; }
   double getMetersY()       const { return y; }
   double getPixelsX()       const { return x / metersFromPixels; }
   double getPixelsY()       const { return y / metersFromPixels; }

   // setters
   void setMeters(double xMeters, double yMeters) { x = xMeters; y = yMeters; }
   void setMetersX(double xMeters) { x = xMeters; }
   void setMetersY(double yMeters) { y = yMeters; }
   void setPixelsX(double xPixels) { x = xPixels * metersFromPixels; }
   void setPixelsY(double yPixels) { y = yPixels * metersFromPixels; }
   void addMetersX(double dxMeters) { setMetersX(getMetersX() + dxMeters); }
   void addMetersY(double dyMeters) { setMetersY(getMetersY() + dyMeters); }
   void addPixelsX(double dxPixels) { setPixelsX(getPixelsX() + dxPixels); }
   void addPixelsY(double dyPixels) { setPixelsY(getPixelsY() + dyPixels); }

   // deal with the ratio of meters to pixels
   void setZoom(double metersFromPixels)
   {
      this->metersFromPixels = metersFromPixels;
   }
   double getZoom() const { return metersFromPixels; }

   double computeDistance(const Point& pos1, const Point& pos2)
   {
      return sqrt((pos1.getMetersX() - pos2.getMetersX()) * (pos1.getMetersX() - pos2.getMetersX()) +
         (pos1.getMetersY() - pos2.getMetersY()) * (pos1.getMetersY() - pos2.getMetersY()));
   }


   



private:
   double x;                 // horizontal position
   double y;                 // vertical position
   static double metersFromPixels;
};



// stream I/O useful for debugging
std::ostream& operator << (std::ostream& out, const Point& pt);
std::istream& operator >> (std::istream& in, Point& pt);


/*********************************************
 * PT
 *********************************************/
struct PT
{
   double x;
   double y;
};


