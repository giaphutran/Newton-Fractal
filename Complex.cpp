#include "Complex.hpp"

Complex:: ~Complex() {
	//cout << ">Complex destructor called" << endl;
}
Complex:: Complex():real(0), imag(0) {
}
Complex::Complex(double r) :real(r), imag(0) {

}
Complex::Complex(double r, double im) :real(r), imag(im) {

}
Complex::Complex(const Complex& com) :real(com.real), imag(com.imag) {

}
double& Complex::operator[](const char* c) {
	
	if (strcmp(c, "real") == 0)
		return this->real;
	else if (strcmp(c, "imag") == 0)
		return this->imag;
	else
		throw InputOutOfBoundsException("Please input only 'real' or 'imag'",c);
}
const Complex operator+(const Complex& a, const Complex& b) {
	//Complex c=Complex(5,4);
	Complex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}
const Complex operator-(const Complex& a, const Complex& b) {
	Complex c;
	c.real = a.real - b.real;
	c.imag = a.imag - b.imag;
	return c;
}
const Complex operator*(const Complex& a, const Complex& b) {
	Complex c;
	c.real = (a.real * b.real-a.imag*b.imag);
	c.imag = (a.real * b.imag+a.imag*b.real);
	return c;
}
const Complex operator/(const Complex& a, const Complex& b) {
	Complex c;		
		c.real = (a.real*b.real+a.imag*b.imag)/(b.real*b.real+b.imag*b.imag);
		c.imag = (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);
	
	return c;
}
double getMagnitude(const Complex& c) {

	return sqrt(c.real * c.real + c.imag * c.imag);
}
Complex::InputOutOfBoundsException::InputOutOfBoundsException() :message("Exeption raised") {

}
Complex::InputOutOfBoundsException::InputOutOfBoundsException(const char* msg, const char* index) :message(msg), offendingIndex(index) {
}

const char* Complex::InputOutOfBoundsException:: getMessage() const {
	return message;
}
const char* Complex::InputOutOfBoundsException::getOffendingIndex() const {
	return offendingIndex;
}