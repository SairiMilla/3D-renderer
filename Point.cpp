#include "Point.h"
#include <math.h>
#define PI 3.1415
#define EPSILON 0.001
Point::Point(float xcoord, float ycoord, float zcoord) {
	x = xcoord;
	y = ycoord;
	z = zcoord;
	w = 0;
}

Point::Point(){
	
}


Point::~Point(){
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

void Point::homogenize(){
	if(w == 0)
		w = 1;
	else{
		float auxX = x/w;
		float auxY = y/w;
		float auxZ = z/w;
		x = auxX;
		y = auxY;
		z = auxZ;
		w = 1;
	}
}

bool Point::operator ==(const Point& p){

	return (isClose(x, p.x)) && (isClose(y, p.y)) && (isClose(z, p.z));
}  

void Point::operator =(const Point& p){
	x = p.x;
	y = p.y;
	z = p.z;
}  

Point Point::operator -(const Point& p){
	return Point(x - p.x, y - p.y, z - p.z);
}  

Point Point::operator +(const Point& p){
	return Point(x + p.x, y + p.y, z + p.z);
}  

float Point::getXCoordinate(){
	return x;
}

float Point::getYCoordinate(){
	return y;
}


float Point::getZCoordinate(){
	return z;
}

float Point::getWCoordinate(){
	return w;
}

Point Point::getVertexNormal(){
	return Point(vNormalX, vNormalY, vNormalZ);
}

void Point::setVertexNormal(Point vNormal){
	vNormalX = vNormal.getXCoordinate();
	vNormalY = vNormal.getYCoordinate();
	vNormalZ = vNormal.getZCoordinate();
}

Color Point::getColor(){
	return color;
}

void Point::setColor(Color c){
	color = c;
}

void Point::setXCoordinate(float xcoord){
	x = xcoord ;
}

void Point::setYCoordinate(float ycoord){
	y = ycoord ;
}

void Point::setZCoordinate(float zcoord){
	z = zcoord ;
}

void Point::setWCoordinate(float wcoord){
	w = wcoord ;
}

Point Point::normalize(){
	float magn = sqrt(pow(x,2) + pow(y,2) + pow(z,2));

	return Point(x/magn, y/magn, z/magn);
}

Point Point::origin(){
	return Point(0, 0, 0);
}

bool Point::isClose(float f1, float f2){
	return (abs(f1 - f2) <= EPSILON * fmaxf(fmaxf(1.0f, abs(f1)), abs(f2)));
}

