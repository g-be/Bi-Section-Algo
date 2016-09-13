#include <cmath>
#include <iostream>

using namespace std;

//.	Use the bisection algorithm to find an approximate 
//	solution z to the equation x^(5.3) + (3.5)^x = N 
//	where N is your 7 - digit phone number, and:
//	 (a)	z is correct to 2 significant figures.
//	 (b)	z is correct to 2 decimal places.

double fx(double x)			// given formula to solve for.
{
	// in this case, x^(5.3) + (3.5)^x
	return pow(x, 5.3) + pow(3.5, x);
}

int main(){		////////// THE BISECTION ALGORITHM //////////

	int T = 2016951;		// phone number
	double A = 0;			// lower guess
	double B = T;			// upper guess
	double z = (A + B) / 2;	// desired number


		//------------------------ delta of 1-------------------------------------------
	cout << "For the equation\n x^(5.3) + (3.5)^x = " << T
		<< "\nWith an lower guess of " << A << " and higher guess of " << B
		<< "\n using a delta of 1\n\t x = ";

	do	{
		if (fx(z)<=T){
			A = z;
		}
		if (fx(z)>=T){
			B = z;
		}
		z = (A + B) / 2;
	} while (abs(z - A) >= 1);	

	cout << z << "\n\n"


		//------------------------ delta of .01-------------------------------------------
		<< "Retrying with a new lower guess of " << A << " and higher guess of " << B
		<< "\n using a delta of 0.01\n\t x = ";

	do	{
		if (fx(z) <= T){
			A = z;
		}
		if (fx(z) >= T){
			B = z;
		}
		z = (A + B) / 2;
	} while (abs(z - A) >= 0.01);

	cout << z << "\n\n"


		//------------------------ delta of 0.00001-------------------------------------------
		<< "Retrying with a new lower guess of " << A << " and higher guess of " << B
		<< "\n using a delta of 0.0001\n\t x = ";

	do	{
		if (fx(z) <= T){
			A = z;
		}
		if (fx(z) >= T){
			B = z;
		}
		z = (A + B) / 2;
	} while (abs(z - A) >= 0.0001);

	cout << z << "\n\n";



	system("pause");
	return 0;
}