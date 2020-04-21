#ifndef Point_H_
#define Point_H_


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>          
#include <vector>          
#include "Color.h"
using namespace std;

class Point{
public:
	Point();
	Point(float, float, float);
	~Point();
	bool operator ==(const Point& p);  
	void operator =(const Point& p);  
	Point operator -(const Point& p);  
	Point operator +(const Point& p);  

	
	void homogenize();

	Point normalize();

	float getXCoordinate();
	float getYCoordinate();
	float getZCoordinate();
	float getWCoordinate();

	void setXCoordinate(float);
	void setYCoordinate(float);
	void setZCoordinate(float);
	void setWCoordinate(float);
	bool isClose(float, float);

	void setVertexNormal(Point);
	Point getVertexNormal();

	void setColor(Color);
	Color getColor();

	static Point origin();

private:
	float x;
	float y;
	float z;
	float w;

	float vNormalX;
	float vNormalY;
	float vNormalZ;

	Color color;
};  

#endif