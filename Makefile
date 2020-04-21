tester.o:  Raster.o PolyMesh.o TransformationManagaer.o Polygon.o Edge.o Point.o PointLight.o Color.o
	g++ tester.cpp Polygon.o Edge.o Raster.o Point.o PolyMesh.o TransformationManager.o PointLight.o Color.o -o tester

TransformationManagaer.o:
	g++ TransformationManager.cpp -c
 
PolyMesh.o:
	g++ PolyMesh.cpp -c 

Polygon.o: 
	g++ Polygon.cpp -c

Edge.o:
	g++ Edge.cpp -c

Raster.o:
	g++ Raster.cpp -c

PointLight.o:
	g++ PointLight.cpp -c

Color.o:
	g++ Color.cpp -c

Point.o:
	g++ Point.cpp -c
