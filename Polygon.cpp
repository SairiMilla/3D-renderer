#include "Polygon.h"

Polygon::Polygon(vector<int> es) {
	edges = es;
	backFacing = false;
}

Polygon::Polygon() {
	backFacing = false;
}

void Polygon::addEdge(int e){
	edges.push_back(e);
}

void Polygon::addVertex(int v){
	vertices.push_back(v);
}

void Polygon::setBackFacing(bool bFace){
	backFacing = bFace;
}

bool Polygon::getBackFacing(){
	return backFacing;
}

vector<int> Polygon::getEdges(){
	return edges;
}

vector<int> Polygon::getVertices(){
	return vertices;
}


void Polygon::calculatePlaneEquation(vector<Edge> edgeList, vector<Point> vertexList, vector<Polygon> polygonList){
		Point vectorEdg1, vectorEdg2;

		vectorEdg1 = vertexList[vertices[1]] - vertexList[vertices[0]];
		vectorEdg2 = vertexList[vertices[2]] - vertexList[vertices[0]];

		A = vectorEdg1.getYCoordinate() * vectorEdg2.getZCoordinate() - vectorEdg2.getYCoordinate() * vectorEdg1.getZCoordinate();
	    B = vectorEdg2.getXCoordinate() * vectorEdg1.getZCoordinate() - vectorEdg1.getXCoordinate() * vectorEdg2.getZCoordinate();
	    C = vectorEdg1.getXCoordinate() * vectorEdg2.getYCoordinate() - vectorEdg2.getXCoordinate() * vectorEdg1.getYCoordinate();

	    Point vertex = vertexList[vertices[1]];

	    D = -(A * vertex.getXCoordinate()) - (B * vertex.getYCoordinate()) - (C * vertex.getZCoordinate());
}

Point Polygon::getFaceNormal(){
	Point normal(A, B, C);
	return normal;
}

float Polygon::getD(){
	return D;
}

bool Polygon::operator ==(const Polygon& p){

	return edges == p.edges;
}



