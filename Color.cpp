#include "Color.h"

Color::Color(int re, int gr, int bl) {
	r = re;
	g = gr;
	b = bl;
}

Color::Color() {
}

int Color::getR(){
	return r;
}

int Color::getG(){
	return g;
}

int Color::getB(){
	return b;
}

void Color::setR(int re){
	r = re;
}

void Color::setG(int gr){
	g = gr;
}

void Color::setB(int bl){
	b = bl;
}




