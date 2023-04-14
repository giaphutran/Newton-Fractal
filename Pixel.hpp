#pragma once
#include<string>
#include <iostream>
using namespace std;

class Pixel
{
private:
	unsigned int red,green,blue;
public:
	~Pixel();////
	const unsigned int& operator[](const char*) const;////
	Pixel();////
	Pixel(const Pixel&);////
	Pixel(unsigned int, unsigned int, unsigned int);////

	friend ostream& operator<<(ostream& os, const Pixel& p);////
	class InputOutOfBoundsException {
	private:
		const char* message;
		const char* offendingIndex;
	public:
		InputOutOfBoundsException();
		InputOutOfBoundsException(const char* msg, const char* index);
		const char* getMessage();
		const char* getOffendingIndex();
	};
};

