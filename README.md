# Newton-Fractal

## Overview
This Project in C++ will create a Newton Fractal image, which shows where to estimate the root of the function, and points where it will be impossible to estimate the root using Newton's method. The function that is originally represented here is f(z)=z^3-2z+2

The Newton1.ppm, Newton2.ppm, and Newton3.ppm are the outputs of the project when running in the original state. You can see the picture version of it using GIMP

Because Newton1.ppm and Newton2.ppm are >25MB, I cannot upload it here, but Newton3.ppm will do a good job representing the Newton Fractal Image of the function

## Usage
### Changing the function getting estimated
The function getting estimated is define in Function "determinePixelColor(Complex Z)", in Fractal.cpp.
To be more specific, it's this line in the function "determinePixelColor(Complex Z)"
```cplusplus
Znew = Z - ((Z * Z * Z) - (2.0 * Z) + 2.0) / ((3.0 * Z * Z) - 2.0);
```
For the fractal image of the function above, it would look like this
![alt text](newton3-1.jpeg)
``` cplusplus
Once changed to a different function, for example Z^3:
```cplusplus
Znew=Z*Z*Z;
```![alt text](<newton1 z^3.png>)
![alt text](<newton1 z^3-1.png>)
The fractal image would change into a circle like this, which represent all possible places you can start estimating using Newton's method and still get the right answer (Z=0). In fact, you can start with ANY number Z (real and imaginary) and still end up with the root Z=0.
That's also the reason why the possible starting points looks like a circle (no discontinuity, no jump, no cusp, kinda heh!)
Pixel Fractal::determinePixelColor(Complex Z)
{
	//dont uncomment line 16, becayse determinePixelColor will be called thousands of times, which creates  unncessary notifications
	//cout << ">Fractal determinePixelColor called" << endl;
	double tol = 1E-4, diff = 1.0, test = 0.58974;
	unsigned int iter = 0, color = 0;
	Complex Znew;
	
	while (iter < 512)
	{
		iter++;
		Znew = Z - ((Z * Z * Z) - (2.0 * Z) + 2.0) / ((3.0 * Z * Z) - 2.0);
		diff = getMagnitude(Z - Znew);
		Z = Znew;
		if (diff < tol)
		{
			try {
				color = maxIter - min(iter, maxIter);
				if (abs(Z["imag"]) < tol)
					return Pixel(color, color, 0);
				else if (abs(Z["imag"] - test) < tol)
					return Pixel(0, color, color);
				else if (abs(Z["imag"] + test) < tol)
					return Pixel(color, 0, color);
			}
			catch (Complex::InputOutOfBoundsException& e) {
				throw;
			}
		}
	}
	return Pixel(0, 0, 0);
}


```
