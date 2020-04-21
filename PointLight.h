#ifndef POINTLIGHT_H_
#define POINTLIGHT_H_


#include <iostream>
#include <string.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <queue>          
#include <vector>          
#include "Point.h"
#include "Color.h"

using namespace std;

class PointLight{
public:
	PointLight();
	PointLight(Point, Color, Color, float, float, float);
	
	Color illuminate(Point, Point, Color, float, float);

private:
	Color color;
	Point position;
	Color ambientColor;
	float c1, c2, c3;
};  

#endif