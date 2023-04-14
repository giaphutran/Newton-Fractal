#include "Fractal.hpp"
Fractal::~Fractal() {
	cout << "> Destructor called ..." << endl;
	for (unsigned int i = 0; i < rows; i++) {
		delete[] grid[i];
	}
	delete[]grid;
	

}


Pixel Fractal::determinePixelColor(Complex Z)
{
	//dont do this
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

void Fractal::makeNewtonFractal()
{
	cout << "> Now creating the Newton Fractal..." << endl;
	Complex Z;
	double step_height = 4.0 / rows;
	double step_width = 4.0 / cols;
	for (int j = 0; j < rows; j++)
	{
		for (int k = 0; k < cols; k++)
		{
			try {
				Z["imag"] = 2.0 - (j * step_height);
				Z["real"] = (k * step_width) - 2.0;
				grid[j][k] = determinePixelColor(Z);
			}
			catch (Complex::InputOutOfBoundsException& e) {
				throw;
			}
		}
	}
}

Fractal::Fractal() : cols(0), grid(nullptr), rows(0) {
	cout << "> Default constructor called..." << endl;
}

Fractal::Fractal(const Fractal& f) : cols(f.cols), rows(f.rows)
{
	cout << "> Copy constructor called..." << endl;
	grid = new Pixel * [rows];
	for (int i = 0; i < rows; i++)
	{
		grid[i] = new Pixel[cols];
		for (int j = 0; j < cols; j++)
		{
			grid[i][j] = f.grid[i][j];
		}
	}
}

Fractal::Fractal(Fractal&& f)
{
	cout << "> Move constructor called..." << endl;
	cols = f.cols;
	rows = f.rows;
	grid = f.grid;

	f.cols = 0;
	f.rows = 0;
	f.grid = nullptr;
}

Fractal::Fractal(unsigned int r, unsigned int c) : rows(r), cols(c)
{
	cout << "> Two-arg constructor called..." << endl;
	grid = new Pixel * [rows];
	for (int i = 0; i < rows; i++)
	{
		grid[i] = new Pixel[cols];
	}
	makeNewtonFractal();
}

const Fractal& Fractal::operator=(const Fractal& f)
{
	//cout << ">Fractal overloaded assignment operator called" << endl;
	if (this != &f)
	{
		if (grid != nullptr)
		{
			for (int i = 0; i < rows; i++)
			{
				delete[] grid[i];
			}
			delete[] grid;
		}
		rows = f.rows;
		cols = f.cols;
		grid = new Pixel * [rows];
		for (int i = 0; i < rows; i++)
		{
			grid[i] = new Pixel[cols];
			for (int j = 0; j < cols; j++)
			{
				grid[i][j] = f.grid[i][j];
			}
		}
	}
	return *this;
}

Fractal& Fractal::operator=(Fractal&& f)
{
	cout << "> Move assignment operator called..." << endl;
	if (this != &f)
	{
		swap(rows, f.rows);
		swap(cols, f.cols);
		swap(grid, f.grid);
	}
	return *this;
}

void saveToPPM(const Fractal& f, const char* fn)
{
	cout << "> Saving Fractal object to PPM file..." << endl;
	ofstream outfile(fn);
	outfile << "P3" << endl;
	outfile << "# " << fn << endl;
	outfile << f.cols << ' ' << f.rows << endl;
	outfile << f.maxIter << endl;
	for (int i = 0; i < f.rows; i++)
	{
		for (int j = 0; j < f.cols; j++)
		{
			outfile << f.grid[i][j] << ' ';
		}
		outfile << endl;
	}
}