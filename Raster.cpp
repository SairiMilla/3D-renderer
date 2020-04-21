#include "Raster.h"

Raster::Raster(int r, int cols, int clr) {
	rows = r;
	columns = cols;
	colors = clr;

	ras = allocateRows();
	zBuffer = allocateZBufferRows();
}

Raster::~Raster(){
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			free(ras[i][j]);
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		free(ras[i]);
	}

	free(ras);



	for (int i = 0; i < rows; ++i)
	{
		free(zBuffer[i]);
	}

	free(zBuffer);
}

unsigned char*** Raster::allocateRows(){
	unsigned char ***rs=(unsigned char***)malloc(sizeof(unsigned char**)*rows);

	if(rs == NULL){
		printf("Error while allocating rows. Not enough memory\n");
	}
	else{
	    int i;
	    for(i=0;i<rows;i++){
	        rs[i]= allocateColumns();
	    }
	}
	 
	return rs;

}

unsigned char** Raster::allocateColumns(){
	unsigned char** cols=(unsigned char**)malloc(sizeof(unsigned char*)*columns);
	if(cols == NULL){
		printf("Error while allocating columns. Not enough memory\n");
	}
	else{
    	int i;
	    for(i=0;i<columns;i++){
	        cols[i] = allocateColors();
	    }
	}
	return cols;

}


unsigned char* Raster::allocateColors(){
	unsigned char *clrs=(unsigned char*)malloc(sizeof(unsigned char)*colors);
	if(clrs == NULL){
		printf("Error while allocating colors. Not enough memory\n");
	}
	else{
	    int i;
	    for(i=0;i<colors;i++){
	        clrs[i]=0;
	    }
	}	
	return clrs;

}


int** Raster::allocateZBufferRows(){
	int** zRows=(int**)malloc(sizeof(int*)*rows);
	if(zRows == NULL){
		printf("Error while allocating columns for Z Buffer. Not enough memory\n");
	}
	else{
	    int i;
	    for(i=0;i<rows;i++){
	        zRows[i] = allocateZBufferColumns();
	    }
	}
    return zRows;
}

int* Raster::allocateZBufferColumns(){
	int *zColumns=(int*)malloc(sizeof(int)*columns);
	if(zColumns == NULL){
		printf("Error while allocating columns for Z Buffer. Not enough memory\n");
	}
	else{
	    int i;
	    for(i=0;i<columns;i++){
	        zColumns[i]=0;
	    }
	}
    return zColumns;
}

void Raster::print(){
	printf("P3\n%i %i\n255\n\n", rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%i %i %i\n", ras[i][j][0], ras[i][j][1], ras[i][j][2]);
        }
    }
}

void Raster::printToFile(char* fileName){
	FILE* f;
    f=fopen(fileName, "w+");
	fprintf(f, "P3\n%i %i\n255\n\n", columns, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            fprintf(f, "%i %i %i\n", ras[i][j][0], ras[i][j][1], ras[i][j][2]);
        }
    }
    fclose(f);
}

void Raster::drawLine(Point start, Point end, int r, int g, int b){
	int x,y,dx,dy,swap,temp,s1,s2,p,i;
	int x1,y1,x2,y2;


	x1 = start.getXCoordinate();
	y1 = start.getYCoordinate();

	x2 = end.getXCoordinate();
	y2 = end.getYCoordinate();

	x = x1;
	y = y1;
	dx = abs(x2-x1);
	dy = abs(y2-y1);
	s1 = sign(x2-x1);
	s2 = sign(y2-y1);
	swap=0;

	

	if(dy>dx)
	{
		 temp=dx;
		 dx=dy;
		 dy=temp;
		 swap=1;
	}

	p=2*dy-dx;

	for(i = 0;i < dx;i++)
	{
		if((rows-y-1 < rows && rows-y-1 >= 0) && (x < minxValue + columns && x >= minxValue)){
			ras[rows-y-1][x - minxValue][0] = r;
	    	ras[rows-y-1][x - minxValue][1] = g;
	   		ras[rows-y-1][x - minxValue][2] = b;
   		}
		
		while(p >= 0)
		{
			p=p-2*dx;

			if(swap)
			  	x+=s1;
			else
			   	y+=s2;
		}

		p = p+2*dy;
		if(swap)
			y += s2;
		else
			x += s1;

	}
	if((rows-y2-1 < rows && rows-y2-1 >= 0)  && (x < minxValue + columns && x >= minxValue)){
		ras[rows-y2-1][x2 - minxValue][0] = r;
	    ras[rows-y2-1][x2 - minxValue][1] = g;
	   	ras[rows-y2-1][x2 - minxValue][2] = b;
	}
}

void Raster::drawTriangle(Polygon pol, vector<Edge> edges, vector<Point> points, int r, int g, int b, Color ambColor, Point lightPos, Color surfColor){
	Color lColor(r, g, b);
	PointLight pl(lightPos, lColor, ambColor, 0.25f, 0.25f, 0.5f);

	intializeEdgeTables(pol, edges, points, pl, surfColor);
	int y, maxYmin, contador = 0;
	Point normal = pol.getFaceNormal();
	int d = pol.getD();

	for(y = 0; y < rows; y++){
		if(!edgeTable[y].empty())
			break;
	}



	for(maxYmin = rows-1; maxYmin >= 0; maxYmin--){
		if(!edgeTable[maxYmin].empty())
			break;
	}
	float z;

	for(; y <= maxYmin || !activeEdgeTable.empty() ; y++){
		vector<EdgeDrawingData> auxActiveEdgeTable;

		if(!edgeTable[y].empty()){
			for (int i = 0; i < edgeTable[y].size(); ++i)
			{
				activeEdgeTable.push_back(edgeTable[y][i]);
			}

		}
		for(int i = 0; i < activeEdgeTable.size(); i++){
			if(activeEdgeTable[i].ymax != y){
				auxActiveEdgeTable.push_back(activeEdgeTable[i]);
			}
		}

		activeEdgeTable = auxActiveEdgeTable;

		if(activeEdgeTable.empty()){
			continue;
		}

		if(activeEdgeTable[0].xmin > activeEdgeTable[1].xmin )
		{
			EdgeDrawingData auxEdd = activeEdgeTable[1];
			activeEdgeTable[1] = activeEdgeTable[0];
			activeEdgeTable[0] = auxEdd;

			activeEdgeTable[0].rightEdge = false;
			activeEdgeTable[1].rightEdge = true;

		}
		Color iA = interpolateColor(activeEdgeTable[0].uColor, activeEdgeTable[0].lColor, 
									activeEdgeTable[0].ymax,activeEdgeTable[0].ymin, y);

		Color iB = interpolateColor(activeEdgeTable[1].uColor, activeEdgeTable[1].lColor, 
									activeEdgeTable[1].ymax,activeEdgeTable[1].ymin, y);

		for (int x = activeEdgeTable[0].xmin; x <= activeEdgeTable[1].xmin; ++x)
		{
			if(!normal.isClose(normal.getZCoordinate(), 0)){
				float realPixelZ = (-d - normal.getXCoordinate() * x - normal.getYCoordinate() * y)/normal.getZCoordinate();
				int pixelZ = (int)(realPixelZ + 0.5f);
				Point polyPoint(x,y,realPixelZ);
				if(pixelZ > zBuffer[y][x - minxValue]){
					zBuffer[y][x - minxValue] = pixelZ;
					Color resultColor;

					if(x == activeEdgeTable[0].xmin)
						resultColor = iA;	
					else if(x == activeEdgeTable[1].xmin)
						resultColor = iB;
					else
						resultColor = interpolateColor(iB, iA, activeEdgeTable[1].xmin, activeEdgeTable[0].xmin, x);

						ras[rows-y-1][x - minxValue][0] = (resultColor.getR());
				    	ras[rows-y-1][x - minxValue][1] = (resultColor.getG());
				   		ras[rows-y-1][x - minxValue][2] = (resultColor.getB());
					
			   	}
			}
			
		}	

		activeEdgeTable[0].increment += activeEdgeTable[0].inverseSlope;

		activeEdgeTable[1].increment += activeEdgeTable[1].inverseSlope;

		activeEdgeTable[0].xmin = (int)(activeEdgeTable[0].increment + 0.5f);
		activeEdgeTable[1].xmin = (int)(activeEdgeTable[1].increment + 0.5f);		
	}
}

int Raster::sign(int x){
	if(x>0)
	 	return 1;
	else if(x<0)
	 	return -1;
	else
    	return 0;
}

void Raster::intializeEdgeTables(Polygon pol, vector<Edge> edges, vector<Point> points, PointLight pl, Color surfColor){
	activeEdgeTable.clear();
	edgeTable.clear();
	edgeTable.assign(rows, vector<EdgeDrawingData>());

	vector<int> polygonEdges = pol.getEdges();

	for(int i = 0; i < polygonEdges.size(); i++){
		if(points[edges[polygonEdges[i]].getV1()].getYCoordinate() == points[edges[polygonEdges[i]].getV2()].getYCoordinate())
			continue;

		points[edges[polygonEdges[i]].getV1()].setColor(pl.illuminate(points[edges[polygonEdges[i]].getV1()].getVertexNormal(),
																	  points[edges[polygonEdges[i]].getV1()], surfColor, 0.3f, 0.4f));

		points[edges[polygonEdges[i]].getV2()].setColor(pl.illuminate(points[edges[polygonEdges[i]].getV2()].getVertexNormal(),
																	  points[edges[polygonEdges[i]].getV2()], surfColor, 0.3f, 0.4f));
		int xMin, yMin, xMax, yMax;

		Color upColor, loColor;

		if(points[edges[polygonEdges[i]].getV1()].getYCoordinate() < points[edges[polygonEdges[i]].getV2()].getYCoordinate()){
			yMin = points[edges[polygonEdges[i]].getV1()].getYCoordinate();
			xMin = points[edges[polygonEdges[i]].getV1()].getXCoordinate();

			yMax = points[edges[polygonEdges[i]].getV2()].getYCoordinate();
			xMax = points[edges[polygonEdges[i]].getV2()].getXCoordinate();

			upColor = points[edges[polygonEdges[i]].getV2()].getColor();
			loColor = points[edges[polygonEdges[i]].getV1()].getColor();
		}
		else{	
			xMin = points[edges[polygonEdges[i]].getV2()].getXCoordinate();
			yMin = points[edges[polygonEdges[i]].getV2()].getYCoordinate();

			yMax = points[edges[polygonEdges[i]].getV1()].getYCoordinate();
			xMax = points[edges[polygonEdges[i]].getV1()].getXCoordinate();

			loColor = points[edges[polygonEdges[i]].getV2()].getColor();
			upColor = points[edges[polygonEdges[i]].getV1()].getColor();
		}
		float dy = yMax - yMin;
		float dx = xMax - xMin;

		EdgeDrawingData edd;
		edd.ymax = yMax;
		edd.xmin = xMin;
		edd.ymin = yMin;
		edd.inverseSlope = dx/dy;
		edd.increment = xMin;
		edd.uColor = upColor;
		edd.lColor = loColor;

		edd.sign = sign(xMax - xMin);


		if(edgeTable[yMin].empty())
			edgeTable[yMin].push_back(edd);
		else if(edgeTable[yMin].back().xmin <= xMin){
			edgeTable[yMin].push_back(edd);
		}
		else if(edgeTable[yMin].front().xmin > xMin){
			edgeTable[yMin].insert(edgeTable[yMin].begin(), edd);
		}
		else
			edgeTable[yMin].insert(edgeTable[yMin].begin() + 1, edd);


	}

}


void Raster::cleanRaster(){
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			for (int k = 0; k < colors; ++k)
			{
				ras[i][j][k] = 0;
			}
		}

	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			zBuffer[i][j] = 0;
		}

	}
}

void Raster::setMinxValue(int minx){
	minxValue = minx;
}

Color Raster::interpolateColor(Color upperColor, Color lowerColor, int upperY,int lowerY, int currentY){
	int r = upperColor.getR() - (upperColor.getR() - lowerColor.getR())*((upperY - currentY)/(upperY - lowerY));
	int g = upperColor.getG() - (upperColor.getG() - lowerColor.getG())*((upperY - currentY)/(upperY - lowerY));
	int b = upperColor.getB() - (upperColor.getB() - lowerColor.getB())*((upperY - currentY)/(upperY - lowerY));
	return Color(r, g, b);
}

