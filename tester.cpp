#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "Raster.h"
#include "PolyMesh.h"
#include "TransformationManager.h"
#include "Point.h"
#include "Edge.h"
#include "Polygon.h"
#include "PointLight.h"
#include "Color.h"
#include <sstream>
#include <vector>         

using std::string;
using std::cout;
using std::vector;

int main() {
    TransformationManager tm;
    Raster raster(1080,1920,3);

    
    PolyMesh chango ,projectedChango;
    chango.loadFromRawFile("changote.raw");


	string file = "animationTest/prueba";
	string ext = ".ppm";
	string fileName2= "pruebitita.ppm";
	string fileName3= "bleh.ppm";

	raster.setMinxValue(-600); 

   	tm.addTranslation(-500, -100,700);
   	tm.applyToMesh(chango);
   	Point cor = chango.vertexList[0];
	tm.addRotationX(-60, cor);
	tm.addRotationY(10, cor);
	tm.addRotationZ(-10, cor);

   	tm.applyToMesh(chango);

	Point lightPosition(50, 400, 300);
	Color ambientColor(80, 80, 80);
	Color surfaceColor(27, 62, 119);

   for (int i = 0; i < 576; ++i)
   	{
   		std::ostringstream oss;
		oss << file << i << ext;

		string fileName = oss.str();
   		
   		tm.addRotationX(0.625, cor);
   		tm.applyToMesh(chango);

   		projectedChango = tm.projectMesh(530, chango);
		printf("Frame %i done projecting\n" , i);
		projectedChango.drawSolid(raster, 128, 128, 128, ambientColor,lightPosition, surfaceColor);

		projectedChango.drawWireFrame(raster, 200, 200, 200);
		printf("done drawing frame %i \n", i);
		raster.printToFile(const_cast<char*>(fileName.c_str()));

		raster.cleanRaster();
   	}

   	for (int i = 576; i < 1152; ++i)
   	{
   		std::ostringstream oss;
		oss << file << i << ext;

		string fileName = oss.str();
   		
   		tm.addRotationY(0.625, cor);
   		tm.applyToMesh(chango);

   		projectedChango = tm.projectMesh(530, chango);
		printf("Frame %i done projecting\n" , i);
		projectedChango.drawSolid(raster, 128, 128, 128, ambientColor,lightPosition, surfaceColor);

		projectedChango.drawWireFrame(raster, 200, 200, 200);
		printf("done drawing frame %i \n", i);
		raster.printToFile(const_cast<char*>(fileName.c_str()));

		raster.cleanRaster();
   	}

   	for (int i = 1152; i < 1728; ++i)
   	{
   		std::ostringstream oss;
		oss << file << i << ext;

		string fileName = oss.str();
   		
   		tm.addRotationZ(0.625, cor);
   		tm.applyToMesh(chango);

   		projectedChango = tm.projectMesh(530, chango);
		printf("Frame %i done projecting\n" , i);
		projectedChango.drawSolid(raster, 128, 128, 128, ambientColor,lightPosition, surfaceColor);

		projectedChango.drawWireFrame(raster, 200, 200, 200);
		printf("done drawing frame %i \n", i);
		raster.printToFile(const_cast<char*>(fileName.c_str()));

		raster.cleanRaster();
   	}

   	for (int i = 1728; i < 2016; ++i)
   	{
   		std::ostringstream oss;
		oss << file << i << ext;

		string fileName = oss.str();
   		
   		tm.addScaling(0.9975, 0.9975, 0.9975, cor);
   		tm.applyToMesh(chango);

   		projectedChango = tm.projectMesh(530, chango);
		printf("Frame %i done projecting\n" , i);
		projectedChango.drawSolid(raster, 128, 128, 128, ambientColor,lightPosition, surfaceColor);

		projectedChango.drawWireFrame(raster, 200, 200, 200);
		printf("done drawing frame %i \n", i);
		raster.printToFile(const_cast<char*>(fileName.c_str()));

		raster.cleanRaster();
   	}

   	for (int i = 2016; i < 2304; ++i)
   	{
   		std::ostringstream oss;
		oss << file << i << ext;

		string fileName = oss.str();
   		
   		tm.addScaling(1.0024, 1.0024, 1.0024, cor);
   		tm.applyToMesh(chango);

   		projectedChango = tm.projectMesh(530, chango);
		printf("Frame %i done projecting\n" , i);
		projectedChango.drawSolid(raster, 128, 128, 128, ambientColor,lightPosition, surfaceColor);

		projectedChango.drawWireFrame(raster, 200, 200, 200);
		printf("done drawing frame %i \n", i);
		raster.printToFile(const_cast<char*>(fileName.c_str()));

		raster.cleanRaster();
   	}

   	for (int i = 2304; i < 2880; ++i)
   	{
   		std::ostringstream oss;
		oss << file << i << ext;

		string fileName = oss.str();
   		
   		tm.addTranslation(0.5, 0, 0);
   		tm.applyToMesh(chango);

   		projectedChango = tm.projectMesh(530, chango);
		printf("Frame %i done projecting\n" , i);
		projectedChango.drawSolid(raster, 128, 128, 128, ambientColor,lightPosition, surfaceColor);

		projectedChango.drawWireFrame(raster, 200, 200, 200);
		printf("done drawing frame %i \n", i);
		raster.printToFile(const_cast<char*>(fileName.c_str()));

		raster.cleanRaster();
   	}

   	for (int i = 2880; i < 3456; ++i)
   	{
   		std::ostringstream oss;
		oss << file << i << ext;

		string fileName = oss.str();
   		
   		tm.addTranslation(0, 0.5, 0);
   		tm.applyToMesh(chango);

   		projectedChango = tm.projectMesh(530, chango);
		printf("Frame %i done projecting\n" , i);
		projectedChango.drawSolid(raster, 128, 128, 128, ambientColor,lightPosition, surfaceColor);

		projectedChango.drawWireFrame(raster, 200, 200, 200);
		printf("done drawing frame %i \n", i);
		raster.printToFile(const_cast<char*>(fileName.c_str()));

		raster.cleanRaster();
   	}

   	for (int i = 3456; i < 4032; ++i)
   	{
   		std::ostringstream oss;
		oss << file << i << ext;

		string fileName = oss.str();
   		
   		tm.addTranslation(0, 0, 0.5);
   		tm.applyToMesh(chango);

   		projectedChango = tm.projectMesh(530, chango);
		printf("Frame %i done projecting\n" , i);
		projectedChango.drawSolid(raster, 128, 128, 128, ambientColor,lightPosition, surfaceColor);

		projectedChango.drawWireFrame(raster, 200, 200, 200);
		printf("done drawing frame %i \n", i);
		raster.printToFile(const_cast<char*>(fileName.c_str()));

		raster.cleanRaster();
   	}

   	for (int i = 4032; i < 4608; ++i)
   	{
   		std::ostringstream oss;
		oss << file << i << ext;

		string fileName = oss.str();
   		
   		tm.addTranslation(-0.5, -0.5, 0.5);
   		tm.addRotationY(0.625,cor);
   		tm.addScaling(0.9975, 0.9975, 0.9975, cor);

   		tm.applyToMesh(chango);

   		projectedChango = tm.projectMesh(530, chango);
		printf("Frame %i done projecting\n" , i);
		projectedChango.drawSolid(raster, 128, 128, 128, ambientColor,lightPosition, surfaceColor);

		projectedChango.drawWireFrame(raster, 200, 200, 200);
		printf("done drawing frame %i \n", i);
		raster.printToFile(const_cast<char*>(fileName.c_str()));

		raster.cleanRaster();
   	}
    return 0;
}
