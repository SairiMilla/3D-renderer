#ifndef POLYGON_H_
#define POLYGON_H_

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>  
#include "Point.h"
#include "Edge.h"        
using std::vector;

class Polygon{
public:
	Polygon();

	Polygon(vector<int>);


	void addEdge(int);
	void addVertex(int);

	vector<int> getEdges();
	vector<int> getVertices();

	void setBackFacing(bool);
	bool getBackFacing();

	void calculatePlaneEquation(vector<Edge>, vector<Point>,  vector<Polygon>);

	Point getFaceNormal();

	float getD();

	bool operator ==(const Polygon&); 


private:
	bool backFacing;
	vector<int> edges;
	float A;
	float B;
	float C;
	float D;

	vector<int> vertices;
};  

#endif