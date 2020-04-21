#ifndef RASTER_H_
#define RASTER_H_

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Point.h"
#include "Edge.h"
#include "Polygon.h"
#include "Color.h"
#include "PointLight.h"


using std::vector;
using std::cout;

struct EdgeDrawingData
{
	int ymax;
	int xmin;
	int ymin;
	float inverseSlope;
	float increment;
	int sign;
	bool rightEdge;
	Color uColor;
	Color lColor;
};

class Raster{
public:
	Raster(int, int, int);
	~Raster();
	void print();  
	void printToFile(char*);        
	void drawLine(Point, Point, int, int, int);
	void drawTriangle(Polygon, vector<Edge>, vector<Point>, int, int, int, Color, Point, Color);
	void cleanRaster();

	void setMinxValue(int);

private:
	unsigned char ***ras;
	int rows;
	int columns;
	int colors;
	int **zBuffer;
	vector< vector<EdgeDrawingData> > edgeTable;
	vector<EdgeDrawingData> activeEdgeTable;
	int minxValue;

	int sign(int);
	unsigned char*** allocateRows();
	unsigned char** allocateColumns();
	unsigned char* allocateColors();
	int** allocateZBufferRows();
	int* allocateZBufferColumns();
	void intializeEdgeTables(Polygon, vector<Edge>, vector<Point>, PointLight, Color);

	Color interpolateColor(Color, Color, int, int, int);
};  

#endif