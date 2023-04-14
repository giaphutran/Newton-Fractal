#include "Fractal.hpp"
#include "Complex.hpp"
#include "Pixel.hpp"
#include <algorithm>
Fractal testMoveConstructor(unsigned int rows, unsigned int cols) {
	cout << ">Test move constructor called" << endl;
	Fractal f(rows, cols);
	return f;
}
unsigned int Fractal::maxIter = 30;
int main()
{
	try {
		Fractal m1(2000U, 2000U), m2, m3;
		saveToPPM(m1, "newton1.ppm");
		m2 = Fractal(m1);
		saveToPPM(m2, "newton2.ppm");
		m3 = testMoveConstructor(200U, 200U);
		saveToPPM(m3, "newton3.ppm");
	}
	catch (Complex::InputOutOfBoundsException& e) {
		cout << e.getMessage() <<". You entered: "<< e.getOffendingIndex() << endl;
	}
	catch (Pixel::InputOutOfBoundsException& e) {
		cout << e.getMessage()<<". You entered: " << e.getOffendingIndex() << endl;
	}

	return 0;
}