#include "PolyMesh.h"

void PolyMesh::loadFromRawFile(string fileName){
	FILE * f;
    if(!(f=fopen(const_cast<char*>(fileName.c_str()), "r"))){
        return;
    }
    int i = 0;
    printf("File opening successful.\n");
    printf("Starting data gathering.\n");
    while(!feof(f)){
        double vx1, vx2, vx3, vx4, vx5, vx6, vx7, vx8, vx9;
        fscanf(f,"%lf %lf %lf %lf %lf %lf %lf %lf %lf \n", &vx1, &vx2, &vx3, &vx4, &vx5, &vx6, &vx7, &vx8, &vx9);


        Point v1((float)(vx1), (float)(vx2), (float)(vx3));
        Point v2((float)(vx4), (float)(vx5), (float)(vx6));
        Point v3((float)(vx7), (float)(vx8), (float)(vx9));


        int i1 = addToVertexList(v1);
        int i2 = addToVertexList(v2);
       	int i3 = addToVertexList(v3);



       	Edge e1(i1, i2);
       	Edge e2(i2, i3);
       	Edge e3(i3, i1);

       	Polygon p;

       	p.addEdge(addToEdgeList(e1));
       	p.addEdge(addToEdgeList(e2));
       	p.addEdge(addToEdgeList(e3));

       	p.addVertex(i1);
       	p.addVertex(i2);
       	p.addVertex(i3);

       	addPolygon(p);
       	printf("Polygon %i added .\n", i);
       	i++;


    }
    fclose(f);
    printf("done.\n");

}

int PolyMesh::addToVertexList(Point p){
	int i=0;
	for( ;i < vertexList.size(); i++ ){
		if(vertexList[i] == p)
			return i;
	}
	vertexList.push_back(p);

	return i;
}

int PolyMesh::addToEdgeList(Edge e){
	int i = 0;
	for(  ;i < edgeList.size(); i++ ){
		if(edgeList[i] == e)
			return i;
	}

	edgeList.push_back(e);

	return i;
}

void PolyMesh::addPolygon(Polygon pol){
	polygons.push_back(pol);
	vector<int> edgesInPolygon = pol.getEdges();
	for (int i = 0; i < edgesInPolygon.size(); ++i)
	{
		edgeList[edgesInPolygon[i]].addPolygon(polygons.size() - 1);
	}
	polygons.back().calculatePlaneEquation(edgeList, vertexList, polygons);
}

void PolyMesh::determineBackFacingPolygons(){

	for (int i = 0; i < polygons.size(); ++i)
	{
		
	    polygons[i].calculatePlaneEquation(edgeList, vertexList, polygons);
	    vector<int> verticesInPolygon = polygons[i].getVertices();

	    Point faceNormal = polygons[i].getFaceNormal();
	  	Point corToPoly = vertexList[verticesInPolygon[0]] - Point::origin();
	    float dotProduct = corToPoly.getXCoordinate() * faceNormal.getXCoordinate() +
	     				   corToPoly.getYCoordinate() * faceNormal.getYCoordinate() +
	     				   corToPoly.getZCoordinate() * faceNormal.getZCoordinate();
	    if(dotProduct > 0){
	    	polygons[i].setBackFacing(true);
	    }
	    else{
	    	polygons[i].setBackFacing(false);
	    }

	}
	
}

void PolyMesh::refreshPlaneEquations(){
	for (int i = 0; i < polygons.size(); ++i)
	{
		
	    polygons[i].calculatePlaneEquation(edgeList, vertexList, polygons);

	}
}


void PolyMesh::drawWireFrame(Raster& ras, int r, int g, int b){

	for( int i=0;i < edgeList.size(); i++ ){
		if(!polygons[edgeList[i].getP1()].getBackFacing() || !polygons[edgeList[i].getP2()].getBackFacing() )
			ras.drawLine(vertexList[edgeList[i].getV1()], vertexList[edgeList[i].getV2()], r, g, b);
	}
}

void PolyMesh::drawSolid(Raster& ras, int r, int g, int b, Color ambientLight, Point lightPos, Color surface){

	for( int i=0;i < polygons.size(); i++ ){
		if(!polygons[i].getBackFacing())
			ras.drawTriangle(polygons[i],edgeList, vertexList, r, g, b, ambientLight, lightPos, surface);
	}
}

void PolyMesh::operator =(const PolyMesh& poly){
	vertexList = poly.vertexList;
	edgeList = poly.edgeList;
	polygons = poly.polygons;
}  

void PolyMesh::normalizePolymesh(){
	vector<bool> polygonCheck;

	polygonCheck.assign(polygons.size(), false);

	int currentPolygon = 1;
	int currentEdge = 0;

	vector<int> polyEdges = polygons[0].getEdges();

	polygonCheck[0] = true;

	for (int i = 0; i < polyEdges.size(); ++i)
	{
		if(edgeList[polyEdges[i]].getP2() != -1){
			currentEdge = polyEdges[i];
			currentPolygon = edgeList[currentEdge].getP2();
			polyEdges = polygons[currentPolygon].getEdges();
		}
	}

	for(int checkedPolygons = 1; checkedPolygons < polygons.size();){
		if(currentPolygon == edgeList[currentEdge].getP1()){
			for(int j = 0; j < polyEdges.size(); j++){
				if(edgeList[polyEdges[j]].getV1()){

				}
			}
		}
	}
}

void PolyMesh::defineVertexNormals(){
	for (int i = 0; i < vertexList.size(); ++i)
	{
		Point vertexNormal = Point::origin();
		for (int j = 0; j < polygons.size(); ++j)
		{
			vector<int> polyVertices = polygons[j].getVertices();
			if(polyVertices[0] == i || polyVertices[1] == i || polyVertices[2] == i)
				vertexNormal = vertexNormal + polygons[j].getFaceNormal();

		}
		vertexList[i].setVertexNormal(vertexNormal.normalize());
	}
}


