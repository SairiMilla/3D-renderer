#ifndef TRANSFORMATIONMANAGER_H_
#define TRANSFORMATIONMANAGER_H_

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "PolyMesh.h"
#include "Point.h"

#include <vector>          
#include <queue>      

using std::vector;
using std::string;
using std::queue;


class TransformationManager{
public:
	void addTranslation(float, float, float);  
	void addRotationX(float, Point); 
	void addRotationY(float, Point);        
	void addRotationZ(float, Point);        
	void addScaling(float, float, float, Point);
	PolyMesh projectMesh(float, PolyMesh);
	Point projectPoint(float, Point);

	void applyToPoint(Point&);
	void applyToMesh(PolyMesh&);

private:
	queue< vector< vector<float> > > transformations;
};  

#endif