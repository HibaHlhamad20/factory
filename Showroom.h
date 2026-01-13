#pragma once

#include <gl/GL.h>
#include "Building.h"
#include <vector>
#include "SimpleStreet.h"


class Showroom {
private:
 
    float width, height, depth;
    void drawNeonSign(); // œ«·… œ«Œ·Ì… ·—”„ Õ—Ê› «··ÊÕ…
    std::vector<Building*> leftStreet;
   
   Texture roadTex;
   SimpleStreet* sideRoad;
   SimpleStreet* frontRoad;
   SimpleStreet* parkingLanes[5];
  std:: vector<Building*> rightStreet;


public:
    Showroom(float w, float h, float d);
    void draw();
    void drawRoadLines();
};