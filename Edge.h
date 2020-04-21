#ifndef EDGE_H_
#define EDGE_H_

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Edge.h"
#include "Point.h"


class Edge{
public:
	Edge(int, int);
	~Edge();
	void addPolygon(int);

	int getV1();
	int getV2();

	int getP1();
	int getP2();

	bool operator ==(const Edge& e); 

private:
	int v1;
	int v2;
	int p1;
	int p2;
};  

#endif