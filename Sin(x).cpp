#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>


int factorial(int i)
{
	if (i == 0) return 1;
	else return i * factorial(i - 1);
}


double SIN(double x) {

	int n = 11;

	int z = (int)(x / (2 * M_PI));

	double y = x -z*(2*M_PI);

	double sin = 0;
	double monom = y;

	for (int i = 1; i < n; i++) {
		sin += monom;
		monom = monom * (-1) * y*y/((2*i+1)*2*i);
	}

	return sin;
}

int main(){

	/*float sum = 0;*/

	/*for (int i = 1; i < 100000; i++) {
		sum += pow(i,-1);
		std::cout << sum << "\n";
	}*/

	double x = 0.1;

	for (int i = 0; i < 600; i++) {
		std::cout << -30 + x * i << "\t" << SIN(-30 + x*i) << "\n";
	}

	/*for (int n = 1; n <= 30; n++) {
		int i = 0;
		do {
			i += 1;
		} while ((sin(x * i) - SIN(x * i, n)) * (sin(x * i) - SIN(x * i, n)) < 1);
		std::cout << n << "\t" << x * i << "\n";
	}*/

	return 0;
}

