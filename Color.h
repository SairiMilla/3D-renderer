#ifndef COLOR_H_
#define COLOR_H_


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>          
#include <vector>         
using namespace std;

class Color{
public:
	Color();
	Color(int, int, int);

	int getR();
	int getG();
	int getB();

	void setR(int);
	void setG(int);
	void setB(int);

private:
	int r;
	int g;
	int b;	
};  

#endif