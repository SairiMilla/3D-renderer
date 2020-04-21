#include "Edge.h"

Edge::Edge(int vertex1, int vertex2) : v1(vertex1), v2(vertex2) {
	p1 = -1;
	p2 = -1;

}

Edge::~Edge(){
	p1 = -1;
	p2 = -1;
}

void Edge::addPolygon(int p){
	if(p1 < 0){
		p1 = p;
	}
	else
		p2 = p;
}


bool Edge::operator ==(const Edge& e){
	return (v1 == e.v1 && v2 == e.v2) || (v1 == e.v2 && v2 == e.v1);
}

int Edge::getV1(){
	return v1;
}
int Edge::getV2(){
	return v2;
}

int Edge::getP1(){
	return p1;
}
int Edge::getP2(){
	return p2;
}