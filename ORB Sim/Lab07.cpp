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

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
//#include "point2D.h"      // for POINT
#include "gps.h"
#include "unitTests.h"
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Point2D ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
    //  ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
    //  ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

     // ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
    //  ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

    //  ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
    //  ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

    //  ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
    //  ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

    //  ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
    //  ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

     // ptGPS.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptGPS.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
      
     

      gps = new GPS(0, 42164000); //  value in meters

    //  ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
    //  ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      angleShip = 0.0;
      angleEarth = 0.0;
      phaseStar = 0;



      
   }

  
   


   GPS* gps;

   
   Point2D ptHubble;
   Point2D ptSputnik;
   Point2D ptStarlink;
   Point2D ptCrewDragon;
   Point2D ptShip;
   //Point2D ptGPS;
   Point2D ptStar;
   Point2D ptUpperRight;

   unsigned char phaseStar;

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
   pDemo->phaseStar++;

   //
   // draw everything
   //

   Point2D pt;



   //drawGPSCenter(pt, pDemo->angleShip);
   pDemo->gps->updateTransformRelitiveToEarth();
   drawGPS(pDemo->gps->getPostion(), pDemo->angleShip);  // Display the GPS to the Screen.
  









   // draw satellites
   drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
   drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
   drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
   drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
   drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   //drawGPS       (pDemo->ptGPS,        pDemo->angleShip);

   // draw parts
   pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
   drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
   pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
   drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
  // drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
   pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
   drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

   // draw fragments
   pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
   drawFragment(pt, pDemo->angleShip);
   pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   drawFragment(pt, pDemo->angleShip);

   // draw a single star
   drawStar(pDemo->ptStar, pDemo->phaseStar);

   // draw the earth
   pt.setMeters(0.0, 0.0);
   drawEarth(pt, pDemo->angleEarth);
}

double Point2D::metersFromPixels = 40.0;

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
   
   unitTests().runner();
   
   
   
   
   // Initialize OpenGL
   Point2D ptUpperRight;
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
