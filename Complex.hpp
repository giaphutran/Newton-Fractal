#pragma once
using namespace std;
#include <cmath>
#include <iostream>
#include <string>
#include <exception>
class Complex
{
private:
	double imag;
	double real;
public:
	Complex();
	~Complex();
	Complex(const Complex&);
	Complex(double);
	Complex(double, double);
	double& operator[](const char*);
	friend const Complex operator*(const Complex&, const Complex&);
	friend const Complex operator/(const Complex&, const Complex&);
	friend const Complex operator+(const Complex&, const Complex&);
	friend const Complex operator-(const Complex&, const Complex&);
	friend double getMagnitude(const Complex&);
	//ALL CHECKED
	class InputOutOfBoundsException {
	private:
		const char* message;
		const char* offendingIndex;
	public:	
		InputOutOfBoundsException();
		InputOutOfBoundsException(const char* msg, const char* index);
		const char* getMessage() const;
		const char* getOffendingIndex() const;
	};
};

