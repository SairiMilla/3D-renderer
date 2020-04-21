#ifndef POLYMESH_H_
#define POLYMESH_H_

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Polygon.h"
#include "Point.h"
#include "Edge.h"
#include "Raster.h"
#include "Color.h"
#include "PointLight.h"



#include <vector>         
using std::vector;
using std::string;


class PolyMesh{
public:
	void loadFromRawFile(string);
	int addToVertexList(Point);  
	int addToEdgeList(Edge);
	void addPolygon(Polygon);
	void drawWireFrame(Raster&, int, int, int);
	void drawSolid(Raster&, int, int, int, Color, Point, Color);

	void operator =(const PolyMesh&);  
	void determineBackFacingPolygons();
	void refreshPlaneEquations();
	void defineVertexNormals();

	vector<Point> vertexList;
private:
	vector<Edge> edgeList;
	vector<Polygon> polygons;
	void normalizePolymesh();

};  

#endif