///***********************************************************************
// * Source File:
// *    Point : The representation of a position on the screen
// * Author:
// *    Br. Helfrich
// * Summary:
// *    Everything we need to know about a location on the screen.
// ************************************************************************/
//
//#include "point.h"
//#include <cassert>
//
//
//Point::Point(double x, double y) : x(0.0), y(0.0)
//{
//   setMetersX(x);
//   setMetersY(y);
//}
//
///******************************************
// * POINT : ASSIGNMENT
// * Assign a point
// *****************************************/
//Point& Point::operator = (const Point& pt)
//{
//   x = pt.x;
//   y = pt.y;
//   return *this;
//}
//
///******************************************
// * POSITION insertion
// *       Display coordinates on the screen
// *****************************************/
//std::ostream& operator << (std::ostream& out, const Point& pt)
//{
//   out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << "m)";
//   return out;
//}
//   
///*******************************************
//* POSITION extraction
//*       Prompt for coordinates
//******************************************/
//std::istream& operator >> (std::istream& in, Point& pt)
//{
//   double x;
//   double y;
//   in >> x >> y;
//
//   pt.setMetersX(x);
//   pt.setMetersY(y);
//
//   return in;
//}
