/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <set>
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "spaceObjects.h"

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Point ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {


      ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      // Add GPS units
      gpsGroup.insert(new GPS(0, 26560000, -3880, 0, 3900)); //  value in meters)
      gpsGroup.insert(new GPS(0, -26560000, 3880, 0, 3900)); //  value in meters)

      gpsGroup.insert(new GPS(23001634, 13280000, -1940, 3360, 3900)); //  value in meters)
      gpsGroup.insert(new GPS(23001634, -13280000, 1940, 3360, 3900)); //  value in meters)

      gpsGroup.insert(new GPS(23001634, -13280000, -1940, -3360, 3900)); //  value in meters)
      gpsGroup.insert(new GPS(-23001634, 13280000, 1940, -3360, 3900)); //  value in meters)



      dragonCrew = new DragonCrew(0, 12164000);
      dragonCrew->setGeoTargetVelocity(-7900);

      hubble = new Hubble(0, -42164000);
      hubble->setGeoTargetVelocity(3100);

      sputnik = new Sputnik(-36515095, 21082000);
      sputnik->setGeoTargetVelocity(3362);



      // create multiple instances of starlink units
      for (int i = 0; i < 10; i++)
      {
         starlinks.insert(new Starlink(0, ( -13020000 * random(-0.5, 0.5)), 5800, 0, random(-0.5, 0.5) * 5800));
      }

      // create star instances in background
      for (int i = 0; i < 700; i++)
      {
         stars.insert(new Star(random(-77777777.0, 77777777.0), random(-77777777.0, 77777777.0),   random(-100, 100) ));
      }


      angleShip = 0.0;
      angleEarth = 0.0;




      
   }

  
   

   std::set<GPS*> gpsGroup;
   std::set<Starlink*> starlinks;
   std::set<Fragments*> Fragments;
   std::set<Star*> stars;

   DragonCrew* dragonCrew;
   Hubble* hubble;
   Sputnik* sputnik;


   Point ptShip;

   Point ptStar;
   Point ptUpperRight;

   double angleShip;
   double angleEarth;



private:


   
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //
   

   // move by a little
   if (pUI->isUp())
      
      pDemo->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
      pDemo->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
      pDemo->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
      pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic
   //

   // rotate the earth
   pDemo->angleEarth += 0.01;
   pDemo->angleShip += 0.02;


   //
   // draw everything
   //

   Point pt;




   for (auto i : pDemo->gpsGroup)
   {
      i->updateTransformRelitiveToEarth();
      drawGPS(i->getPostion(), pDemo->angleShip);
   }
      
   for (auto i : pDemo->starlinks)
   {
      i->updateTransformRelitiveToEarth();
      drawStarlink(i->getPostion(), pDemo->angleShip);
   }


   for (auto i : pDemo->stars)
   {
      i->UpdatePhase();
      drawStar(i->getPostion(), i->getPhase());
   }


   pDemo->dragonCrew->updateTransformRelitiveToEarth();
   drawCrewDragon(pDemo->dragonCrew->getPostion(), pDemo->angleShip);



   pDemo->hubble->updateTransformRelitiveToEarth();
   drawHubble(pDemo->hubble->getPostion(), pDemo->angleShip);


   pDemo->sputnik->updateTransformRelitiveToEarth();
   drawSputnik(pDemo->sputnik->getPostion() , pDemo->angleShip);





   // draw satellites
   //drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
  // drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
  // drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
  // drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
   //drawGPS       (pDemo->ptGPS,        pDemo->angleShip);
   drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());


   //pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
   //drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set


   pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   drawFragment(pt, pDemo->angleShip);

   // draw the earth
   pt.setMeters(0.0, 0.0);
   drawEarth(pt, pDemo->angleEarth);
}

double Point::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   
   //unitTests().runner();
   
   
   
   
   // Initialize OpenGL
   Point ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
