#pragma once



/*********************************************
 * Point2D
 * A single position on the field in Meters
 *********************************************/

class Point
{
public:


   // constructors
   Point() : x(0.0), y(0.0) {}
   Point(double x, double y);
   Point(const Point& pt) : x(pt.x), y(pt.y) {}
   Point& operator = (const Point& pt);

   // getters


   // deal with the ratio of meters to pixels


private:
   double x;                 // horizontal position
   double y;                 // vertical position




protected:

   virtual void help() {};

   double getMetersX()       const { return x; }
   double getMetersY()       const { return y; }


   // setters
   void setMeters(double xMeters, double yMeters) { x = xMeters; y = yMeters; }
   void setMetersX(double xMeters) { x = xMeters; }
   void setMetersY(double yMeters) { y = yMeters; }

   void addMetersX(double dxMeters) { setMetersX(getMetersX() + dxMeters); }
   void addMetersY(double dyMeters) { setMetersY(getMetersY() + dyMeters); }

};


