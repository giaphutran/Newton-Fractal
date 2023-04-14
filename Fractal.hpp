#pragma once
#include <iostream>
#include <fstream>
#include "Complex.hpp"
#include "Pixel.hpp"
#include "Fractal.hpp"
#include <cmath>
using namespace std;

class Fractal {
private: 
	static unsigned int maxIter ;
	unsigned int cols, rows;
	Pixel** grid;
	Pixel determinePixelColor(Complex); //
	void makeNewtonFractal();//
public:
	Fractal(); //
	~Fractal(); //
	Fractal(const Fractal&); //
	Fractal(Fractal&&); 
	Fractal(unsigned int, unsigned int);//
	const Fractal& operator=(const Fractal&);//
	Fractal& operator=(Fractal&&);//
	friend void saveToPPM(const Fractal& , const char*);

};