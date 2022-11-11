#pragma once



/*********************************************
 * Point2D
 * A single position on the field in Meters
 *********************************************/

class Point
{

   friend class unitTests;
public:


   // constructors
   Point() : x(0.0), y(0.0) {}
   Point(double x, double y);
   Point(const Point& pt) : x(pt.x), y(pt.y) {}
   Point& operator = (const Point& pt);

   double getMetersX()       const { return x; }
   double getMetersY()       const { return y; }


   // setters
   void setMeters(double xMeters, double yMeters) { x = xMeters; y = yMeters; }
   void setMetersX(double xMeters) { x = xMeters; }
   void setMetersY(double yMeters) { y = yMeters; }

   void addMetersX(double dxMeters) { setMetersX(getMetersX() + dxMeters); }
   void addMetersY(double dyMeters) { setMetersY(getMetersY() + dyMeters); }
   // getters


   // deal with the ratio of meters to pixels
   double computeDistance(const Point2D& pos1, const Point2D& pos2)
   {
      return sqrt((pos1.getMetersX() - pos2.getMetersX()) * (pos1.getMetersX() - pos2.getMetersX()) +
         (pos1.getMetersY() - pos2.getMetersY()) * (pos1.getMetersY() - pos2.getMetersY()));
   }

private:
   double x;                 // horizontal position
   double y;                 // vertical position




protected:


};


