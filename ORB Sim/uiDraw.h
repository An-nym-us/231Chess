/***********************************************************************
 * Header File:
 *    User Interface Draw : put pixels on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This is the code necessary to draw on the screen. We have a collection
 *    of procedural functions here because each draw function does not
 *    retain state. In other words, they are verbs (functions), not nouns
 *    (variables) or a mixture (objects)
 ************************************************************************/

#pragma once

#include <string>     // To display text on the screen
#include <cmath>      // for M_PI, sin() and cos()
#include <algorithm>  // used for min() and max()
#include "point.h" // Where things are drawn
using std::string;
using std::min;
using std::max;

#include <sstream>


#define GL_SILENCE_DEPRECATION

/*************************************************************************
 * GRAPHICS STREAM
 * A graphics stream that behaves much like COUT except on a drawn screen
 *************************************************************************/
class ogstream : public std::ostringstream
{
public:
   ogstream(const Point& pt) : pt(pt) {}
   ~ogstream() { flush(); }; 
   void flush();

   void setPosition(const Point& pt) { flush(); this->pt = pt; }
   ogstream& operator = (const Point& pt)
   {
      setPosition(pt);
      return *this;
   }
private:
   Point pt;
};

/************************************************************************
 * DRAW FRAGMENT
 * Draw a fragment on the screen.
 *   INPUT  pt     The location of the projectile
 *          age    The age in seconds. The younger, the brighter
 *************************************************************************/
void drawFragment(const Point& center, double rotation);

/************************************************************************
 * DRAW PROJECTILE
 * Draw a projectile on the screen at a given point.
 *   INPUT  pt     The location of the projectile
 *************************************************************************/
void drawProjectile(const Point& pt);

/************************************************************************
 * DRAW Crew Dragon
 * Draw a crew dragon on the screen. It consists of three components
 *  INPUT point   The position of the ship
 *        angle   Which direction it is pointed
 *        offset  For pieces of the satellite, this is the relative position of the center
 *                of rotation when it is connected to the main satellite
 *************************************************************************/
void drawCrewDragon      (const Point& center, double rotation);
void drawCrewDragonRight (const Point& center, double rotation, const Point& offset = Point());
void drawCrewDragonLeft  (const Point& center, double rotation, const Point& offset = Point());
void drawCrewDragonCenter(const Point& center, double rotation);

/************************************************************************
 * DRAW Sputnik
 * Draw the satellite on the screen
 *  INPUT point   The position of the ship
 *        angle   Which direction it is point
 *************************************************************************/
void drawSputnik(const Point& center, double rotation);

/************************************************************************
 * DRAW GPS
 * Draw a GPS satellite on the screen. It consists of three parts
 *  INPUT point   The position of the ship
 *        angle   Which direction it is pointed
 *        offset  For pieces of the satellite, this is the relative position of the center
 *                of rotation when it is connected to the main satellite
 *************************************************************************/
void drawGPS      (const Point& center, double rotation);
void drawGPSCenter(const Point& center, double rotation);
void drawGPSRight (const Point& center, double rotation, const Point& offset = Point());
void drawGPSLeft  (const Point& center, double rotation, const Point& offset = Point());

/************************************************************************
 * DRAW Hubble
 * Draw a Hubble satellite on the screen. It consists of 4 parts
 *  INPUT point   The position of the ship
 *        angle   Which direction it is ponted
 *        offset  For pieces of the satellite, this is the relative position of the center
 *                of rotation when it is connected to the main satellite
 *************************************************************************/
void drawHubble         (const Point& center, double rotation);
void drawHubbleComputer (const Point& center, double rotation, const Point& offset = Point());
void drawHubbleTelescope(const Point& center, double rotation, const Point& offset = Point());
void drawHubbleLeft     (const Point& center, double rotation, const Point& offset = Point());
void drawHubbleRight    (const Point& center, double rotation, const Point& offset = Point());

/************************************************************************
 * DRAW Starlink
 * Draw a Starlink satellite on the screen. It consists of 2 components
 *  INPUT point   The position of the ship
 *        angle   Which direction it is pointed
 *        offset  For pieces of the satellite, this is the relative position of the center
 *                of rotation when it is connected to the main satellite
 *************************************************************************/
void drawStarlink     (const Point& center, double rotation);
void drawStarlinkBody (const Point& center, double rotation, const Point& offset = Point());
void drawStarlinkArray(const Point& center, double rotation, const Point& offset = Point());

/************************************************************************
 * DRAW Ship
 * Draw a spaceship on the screen
 *  INPUT point   The position of the ship
 *        angle   Which direction it is pointed
 *        thrust  Whether the thrusters are on
 *************************************************************************/
void drawShip(const Point& center, double rotation, bool thrust);
/************************************************************************
 * DRAW Earth
 * Draw Earth
 *  INPUT point   The position of the ship
 *        angle   Which direction it is pointed (time of day!)
 *************************************************************************/
void drawEarth(const Point& center, double rotation);

/************************************************************************
* DRAW STAR
* Draw a star
*   INPUT  POINT     The position of the beginning of the star
*          PHASE     The phase of the twinkling
*************************************************************************/
void drawStar(const Point& point, unsigned char phase);

/******************************************************************
 * RANDOM
 * This function generates a random number.  The user specifies
 * The parameters 
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer/double
 ****************************************************************/
int    random(int    min, int    max);
double random(double min, double max);


