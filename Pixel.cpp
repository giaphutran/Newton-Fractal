#include "Pixel.hpp"
Pixel::~Pixel() {
}
Pixel::Pixel() :red(0), green(0), blue(0) {

}
Pixel::Pixel(const Pixel& p) :red(p.red), green(p.green), blue(p.blue) {

}
Pixel::Pixel(unsigned int r, unsigned int g, unsigned int b) :red(r), green(g),blue(b) {

}
//first const make return reference immutable
// second const make data in input parameter immutable
//last const make calling obj immutable
const unsigned int& Pixel:: operator[](const char* c) const  { 
	if (strcmp(c, "red") == 0)
		return this->red;
	else if (strcmp(c, "green") == 0)
		return this->green;
	else if (strcmp(c, "blue") == 0)
		return this->blue;
	else
		throw InputOutOfBoundsException("Please only input 'red', 'green', or 'blue'", c); //EXCEPTION IMPLEMENTATION DONE
}
ostream& operator<<(ostream& os, const Pixel& p) {
	try {
		os << p["red"]<<" "<< p["green"]<<" " << p["blue"] <<" ";
	}
	catch (Pixel::InputOutOfBoundsException& e) {
		throw;
	}
	return os;
}

	Pixel::InputOutOfBoundsException::InputOutOfBoundsException() :message("Exception raised"), offendingIndex("Unknown index") {}
	Pixel::InputOutOfBoundsException::InputOutOfBoundsException(const char* msg, const char* index) : message(msg), offendingIndex(index) {
	}
	const char* Pixel::InputOutOfBoundsException:: getMessage() {
		return message;
	}
	const char* Pixel::InputOutOfBoundsException::getOffendingIndex() {
		return offendingIndex;
	}

