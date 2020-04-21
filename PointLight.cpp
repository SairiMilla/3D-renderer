#include "PointLight.h"

PointLight::PointLight(Point pos,Color col, Color ca,float cone,float ctwo,float cthree) {
	color = col;
	position = pos;
	ambientColor = ca;
	c1 = cone;
	c2 = ctwo;
	c3 = cthree;
}

PointLight::PointLight() {
}

Color PointLight::illuminate(Point normal, Point point, Color surfaceColor, float ka, float kd){
	Point l = (position - point);
	Point normalL = l.normalize();

	float distance = sqrt(pow(l.getXCoordinate(),2) + pow(l.getYCoordinate(),2) + pow(l.getZCoordinate(),2));
	float fatt = fminf(1.0f/(c1 + c2 * distance + c3 * pow(distance,2)), 1.0f);

	float lDotN = normalL.getXCoordinate() * normal.getXCoordinate() + normalL.getYCoordinate() * normal.getYCoordinate() +
					normalL.getZCoordinate() * normal.getZCoordinate();

	int iR = ambientColor.getR() * ka * surfaceColor.getR() + fatt * color.getR() * kd * lDotN * surfaceColor.getR();
	int iG = ambientColor.getG() * ka * surfaceColor.getG() + fatt * color.getG() * kd * lDotN * surfaceColor.getG();
	int iB = ambientColor.getB() * ka * surfaceColor.getB() + fatt * color.getB() * kd * lDotN * surfaceColor.getB();
	Color resultColor(iR, iG, iB);

	return resultColor;
}




