#include "TransformationManager.h"
#include <math.h>
#define PI 3.1415

void TransformationManager::addTranslation(float xtranslation, float ytranslation, float ztranslation){

	float row1[4] = {	1, 0, 0, xtranslation};
	float row2[4] = {0, 1, 0, ytranslation};
	float row3[4] = {0, 0, 1, ztranslation};
	float row4[4] = {0, 0, 0, 1};
	vector< vector<float> > translationMatrix;

	vector<float> aux(row1, row1 + sizeof(row1) / sizeof(float));
	translationMatrix.push_back(aux);

	vector<float> aux2(row2, row2 + sizeof(row2) / sizeof(float));
	translationMatrix.push_back(aux2);

	vector<float> aux3(row3, row3 + sizeof(row3) / sizeof(float));
	translationMatrix.push_back(aux3);	

	vector<float> aux4(row4, row4 + sizeof(row4) / sizeof(float));
	translationMatrix.push_back(aux4);	


    transformations.push(translationMatrix);


}

void TransformationManager::addRotationX(float angleOfRotation, Point centerOfRotation){
	vector< vector<float> > rotationMatrix;
	angleOfRotation = (angleOfRotation/180.0) * PI;

		float row1[4] = {1, 0, 0, 0};
		float row2[4] = {0, cos(angleOfRotation), -sin(angleOfRotation), 0};
		float row3[4] = {0, sin(angleOfRotation), cos(angleOfRotation), 0};
		float row4[4] = {0, 0, 0, 1};

		vector<float> aux(row1, row1 + sizeof(row1) / sizeof(float));
		rotationMatrix.push_back(aux);

		vector<float> aux2(row2, row2 + sizeof(row2) / sizeof(float));
		rotationMatrix.push_back(aux2);

		vector<float> aux3(row3, row3 + sizeof(row3) / sizeof(float));
		rotationMatrix.push_back(aux3);	

		vector<float> aux4(row4, row4 + sizeof(row4) / sizeof(float));
		rotationMatrix.push_back(aux4);

	
	if(centerOfRotation.getXCoordinate() == 0 && centerOfRotation.getYCoordinate() == 0 && centerOfRotation.getZCoordinate() == 0){
		transformations.push(rotationMatrix);

	}
	else{
		addTranslation(-centerOfRotation.getXCoordinate(), -centerOfRotation.getYCoordinate(), -centerOfRotation.getZCoordinate());
    	transformations.push(rotationMatrix);
    	addTranslation(centerOfRotation.getXCoordinate(), centerOfRotation.getYCoordinate(), centerOfRotation.getZCoordinate());
	}

}

void TransformationManager::addRotationY(float angleOfRotation, Point centerOfRotation){
	vector< vector<float> > rotationMatrix;
	angleOfRotation = (angleOfRotation/180.0) * PI;

		float row1[4] = {cos(angleOfRotation), 0, sin(angleOfRotation), 0};
		float row2[4] = {0, 1, 0, 0};
		float row3[4] = {-sin(angleOfRotation), 0, cos(angleOfRotation), 0};
		float row4[4] = {0, 0, 0, 1}; 

		vector<float> aux(row1, row1 + sizeof(row1) / sizeof(float));
		rotationMatrix.push_back(aux);

		vector<float> aux2(row2, row2 + sizeof(row2) / sizeof(float));
		rotationMatrix.push_back(aux2);

		vector<float> aux3(row3, row3 + sizeof(row3) / sizeof(float));
		rotationMatrix.push_back(aux3);	

		vector<float> aux4(row4, row4 + sizeof(row4) / sizeof(float));
		rotationMatrix.push_back(aux4);

	if(centerOfRotation.getXCoordinate() == 0 && centerOfRotation.getYCoordinate() == 0 && centerOfRotation.getZCoordinate() == 0){
		transformations.push(rotationMatrix);

	}
	else{
		addTranslation(-centerOfRotation.getXCoordinate(), -centerOfRotation.getYCoordinate(), -centerOfRotation.getZCoordinate());
    	transformations.push(rotationMatrix);
    	addTranslation(centerOfRotation.getXCoordinate(), centerOfRotation.getYCoordinate(), centerOfRotation.getZCoordinate());
	}

}

void TransformationManager::addRotationZ(float angleOfRotation, Point centerOfRotation){
	vector< vector<float> > rotationMatrix;
	angleOfRotation = (angleOfRotation/180.0) * PI;

	cout << angleOfRotation << endl;

		float row1[4] = {cos(angleOfRotation), -sin(angleOfRotation), 0, 0};
		float row2[4] = {sin(angleOfRotation), cos(angleOfRotation), 0, 0};
		float row3[4] = {0, 0, 1, 0};
		float row4[4] = {0, 0, 0, 1}; 

		vector<float> aux(row1, row1 + sizeof(row1) / sizeof(float));
		rotationMatrix.push_back(aux);

		vector<float> aux2(row2, row2 + sizeof(row2) / sizeof(float));
		rotationMatrix.push_back(aux2);

		vector<float> aux3(row3, row3 + sizeof(row3) / sizeof(float));
		rotationMatrix.push_back(aux3);	

		vector<float> aux4(row4, row4 + sizeof(row4) / sizeof(float));
		rotationMatrix.push_back(aux4);


	if(centerOfRotation.getXCoordinate() == 0 && centerOfRotation.getYCoordinate() == 0 && centerOfRotation.getZCoordinate() == 0){
		transformations.push(rotationMatrix);

	}
	else{
		addTranslation(-centerOfRotation.getXCoordinate(), -centerOfRotation.getYCoordinate(), -centerOfRotation.getZCoordinate());
    	transformations.push(rotationMatrix);
    	addTranslation(centerOfRotation.getXCoordinate(), centerOfRotation.getYCoordinate(), centerOfRotation.getZCoordinate());
	}

}

void TransformationManager::addScaling(float xscaling, float yscaling, float zscaling, Point centerOfScaling){
	float row1[4] = {xscaling, 0, 0, 0};
	float row2[4] = {0, yscaling, 0, 0};
	float row3[4] = {0, 0, zscaling, 0};
	float row4[4] = {0, 0, 0, 1};

	vector< vector<float> > scalingMatrix;


	vector<float> aux(row1, row1 + sizeof(row1) / sizeof(float));
	scalingMatrix.push_back(aux);

	vector<float> aux2(row2, row2 + sizeof(row2) / sizeof(float));
	scalingMatrix.push_back(aux2);

	vector<float> aux3(row3, row3 + sizeof(row3) / sizeof(float));
	scalingMatrix.push_back(aux3);	

	vector<float> aux4(row4, row4 + sizeof(row4) / sizeof(float));
	scalingMatrix.push_back(aux4);

	if(centerOfScaling.getXCoordinate() == 0 && centerOfScaling.getYCoordinate() == 0 && centerOfScaling.getZCoordinate() == 0){
		transformations.push(scalingMatrix);
	}
	else{
		addTranslation(-centerOfScaling.getXCoordinate(), -centerOfScaling.getYCoordinate(), -centerOfScaling.getZCoordinate());
    	transformations.push(scalingMatrix);
    	addTranslation(centerOfScaling.getXCoordinate(), centerOfScaling.getYCoordinate(), centerOfScaling.getZCoordinate());
	}

}

PolyMesh TransformationManager::projectMesh(float planePos, PolyMesh mesh){

	float perspMatrix[4][4] = { {1, 0, 0, 0},
								{0, 1, 0, 0},
								{0, 0, 1, 0},
								{0, 0, 1/planePos, 0}
							  };

	mesh.determineBackFacingPolygons();
	mesh.defineVertexNormals();


		for(int j = 0; j < mesh.vertexList.size(); j++){
				mesh.vertexList[j].homogenize();
				float auxX = perspMatrix[0][0] * mesh.vertexList[j].getXCoordinate() + perspMatrix[0][1] * mesh.vertexList[j].getYCoordinate() + perspMatrix[0][2] * mesh.vertexList[j].getZCoordinate() + perspMatrix[0][3] * mesh.vertexList[j].getWCoordinate();		
				float auxY = perspMatrix[1][0] * mesh.vertexList[j].getXCoordinate() + perspMatrix[1][1] * mesh.vertexList[j].getYCoordinate() + perspMatrix[1][2] * mesh.vertexList[j].getZCoordinate() + perspMatrix[1][3] * mesh.vertexList[j].getWCoordinate();
				float auxZ = perspMatrix[2][0] * mesh.vertexList[j].getXCoordinate() + perspMatrix[2][1] * mesh.vertexList[j].getYCoordinate() + perspMatrix[2][2] * mesh.vertexList[j].getZCoordinate() + perspMatrix[2][3] * mesh.vertexList[j].getWCoordinate();
				float auxW = perspMatrix[3][0] * mesh.vertexList[j].getXCoordinate() + perspMatrix[3][1] * mesh.vertexList[j].getYCoordinate() + perspMatrix[3][2] * mesh.vertexList[j].getZCoordinate() + perspMatrix[3][3] * mesh.vertexList[j].getWCoordinate();

				mesh.vertexList[j].setXCoordinate(auxX);
				mesh.vertexList[j].setYCoordinate(auxY);
				mesh.vertexList[j].setZCoordinate(auxZ);
				mesh.vertexList[j].setWCoordinate(auxW);
				mesh.vertexList[j].homogenize();
		}
		mesh.refreshPlaneEquations();
		return mesh;
}

Point TransformationManager::projectPoint(float planePos, Point point){

	float perspMatrix[4][4] = { {1, 0, 0, 0},
								{0, 1, 0, 0},
								{0, 0, 1, 0},
								{0, 0, 1/planePos, 0}
							  };

	point.homogenize();
	float auxX = perspMatrix[0][0] * point.getXCoordinate() + perspMatrix[0][1] * point.getYCoordinate() + perspMatrix[0][2] * point.getZCoordinate() + perspMatrix[0][3] * point.getWCoordinate();		
	float auxY = perspMatrix[1][0] * point.getXCoordinate() + perspMatrix[1][1] * point.getYCoordinate() + perspMatrix[1][2] * point.getZCoordinate() + perspMatrix[1][3] * point.getWCoordinate();
	float auxZ = perspMatrix[2][0] * point.getXCoordinate() + perspMatrix[2][1] * point.getYCoordinate() + perspMatrix[2][2] * point.getZCoordinate() + perspMatrix[2][3] * point.getWCoordinate();
	float auxW = perspMatrix[3][0] * point.getXCoordinate() + perspMatrix[3][1] * point.getYCoordinate() + perspMatrix[3][2] * point.getZCoordinate() + perspMatrix[3][3] * point.getWCoordinate();
	point.setXCoordinate(auxX);
	point.setYCoordinate(auxY);
	point.setZCoordinate(auxZ);
	point.setWCoordinate(auxW);
	point.homogenize();
	return point;
}

void TransformationManager::applyToPoint(Point& p){
	p.homogenize();

    if(!transformations.empty()){
        vector< vector<float> > composition = transformations.front();
	    transformations.pop();
		cout << "Initial values: x = " << p.getXCoordinate() << ", y = " << p.getYCoordinate() << ", z = " << p.getZCoordinate() << endl;
		float sum;


		while(!transformations.empty()){
	 			vector< vector<float> > trans = transformations.front();
				vector< vector<float> > auxV(composition);

				for (int multiplyRows = 0; multiplyRows < 4; multiplyRows++) {
			      for (int d = 0; d < 4; d++) {
			        for (int k = 0; k < 4; k++) {
			          sum = sum + (trans[multiplyRows][k]*auxV[k][d]);
			        }
			 		
			        composition[multiplyRows][d] = sum;


			        sum = 0;

			      }
			    }
				transformations.pop();
		}
		
		float auxX = composition[0][0] * p.getXCoordinate() + composition[0][1] * p.getYCoordinate() + composition[0][2] * p.getZCoordinate() + composition[0][3] * p.getWCoordinate();		
		float auxY = composition[1][0] * p.getXCoordinate() + composition[1][1] * p.getYCoordinate() + composition[1][2] * p.getZCoordinate() + composition[1][3] * p.getWCoordinate();
		float auxZ = composition[2][0] * p.getXCoordinate() + composition[2][1] * p.getYCoordinate() + composition[2][2] * p.getZCoordinate() + composition[2][3] * p.getWCoordinate();
		float auxW = composition[3][0] * p.getXCoordinate() + composition[3][1] * p.getYCoordinate() + composition[3][2] * p.getZCoordinate() + composition[3][3] * p.getWCoordinate();

		p.setXCoordinate(auxX);
		p.setYCoordinate(auxY);
		p.setZCoordinate(auxZ);
		p.setWCoordinate(auxW);
		cout << "Before homenize: x = " << p.getXCoordinate() << ", y = " << p.getYCoordinate() << ", z = " << p.getZCoordinate() << endl;

		p.homogenize();
		cout << "Final values: x = " << p.getXCoordinate() << ", y = " << p.getYCoordinate() << ", z = " << p.getZCoordinate() << endl;
		cout << endl;

	}

}

void TransformationManager::applyToMesh(PolyMesh& mesh){
	for(int i = 0; i < mesh.vertexList.size(); i++){
		mesh.vertexList[i].homogenize();
	}

    if(!transformations.empty()){
    	vector< vector<float> > composition = transformations.front();
	    transformations.pop();
		float sum;


		while(!transformations.empty()){
	 			vector< vector<float> > trans = transformations.front();
				vector< vector<float> > auxV(composition);

				for (int multiplyRows = 0; multiplyRows < 4; multiplyRows++) {
			      for (int d = 0; d < 4; d++) {
			        for (int k = 0; k < 4; k++) {
			          sum = sum + (trans[multiplyRows][k]*auxV[k][d]);
			        }
			 		
			        composition[multiplyRows][d] = sum;


			        sum = 0;

			      }
			    }
				transformations.pop();
		}

		for(int j = 0; j < mesh.vertexList.size(); j++){
			float auxX = composition[0][0] * mesh.vertexList[j].getXCoordinate() + composition[0][1] * mesh.vertexList[j].getYCoordinate() + composition[0][2] * mesh.vertexList[j].getZCoordinate() + composition[0][3] * mesh.vertexList[j].getWCoordinate();		
			float auxY = composition[1][0] * mesh.vertexList[j].getXCoordinate() + composition[1][1] * mesh.vertexList[j].getYCoordinate() + composition[1][2] * mesh.vertexList[j].getZCoordinate() + composition[1][3] * mesh.vertexList[j].getWCoordinate();
			float auxZ = composition[2][0] * mesh.vertexList[j].getXCoordinate() + composition[2][1] * mesh.vertexList[j].getYCoordinate() + composition[2][2] * mesh.vertexList[j].getZCoordinate() + composition[2][3] * mesh.vertexList[j].getWCoordinate();
			float auxW = composition[3][0] * mesh.vertexList[j].getXCoordinate() + composition[3][1] * mesh.vertexList[j].getYCoordinate() + composition[3][2] * mesh.vertexList[j].getZCoordinate() + composition[3][3] * mesh.vertexList[j].getWCoordinate();

			mesh.vertexList[j].setXCoordinate(auxX);
			mesh.vertexList[j].setYCoordinate(auxY);
			mesh.vertexList[j].setZCoordinate(auxZ);
			mesh.vertexList[j].setWCoordinate(auxW);
			mesh.vertexList[j].homogenize();
		}
	}

}