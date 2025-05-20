/*! @file Main.cpp
	@brief A main file used to test the classes: Function, Polynomial, Power
	@author Alessia Marchese

	Details.
*/ 
#include "CPower.h"
#include"CPolynomial.h"
#include "CExponential.h"

int main()
{
	Power pow1; // pow1 = 1*x^0
	pow1.Dump();

	pow1.SetPower(3, 0.5); // pow1 = 3*x^0.5
	pow1.Dump();
	//cout << endl << "Value of pow1 = 3*x^0.5 if x = -2: " << pow1.GetValue(-2) << endl; // expected error
	cout << endl << "Value of pow1 = 3*x^0.5 if x = 2: " << pow1.GetValue(2) << endl; // expected 4,24264

	Power pow2(2, -3);  // pow2 = 2*x^-3
	pow2.Dump();
	cout << endl << "Value of pow2 = 2*x^-3 if x = 4: " << pow2.GetValue(4) << endl; // expected 0,03125

	pow2 = pow1;  // pow2 = 3*x^0.5
	pow2.Dump();

	if (pow1 == pow2)
		cout << endl << "pow1 and pow2 are equal" << endl; //should happen

	Power pow3(pow2); // pow3 = 3*x^0.5
	pow3.Dump();

	pow3.SetPower(5, 3);
	cout << endl << "Value of pow3 = 5*x^3 if x = 2: " << pow3.GetValue(2) << endl; // expected 40

	pow1.Reset();
	pow1.Dump();

	if (pow1 == pow3)
		cout << endl << "pow1 and pow3 are equal" << endl; // should not happen

	Exponential e1(2, 3.3, 4);
	e1.Dump();

	Exponential e2(e1);
	e2.Dump();

	if (e1 == e2)
		cout << endl << "e1 and e2 are equal" << endl; // should happen

	Exponential e3(2, 1, 2);
	e3.Dump();

	if (e1 == e3)
		cout << endl << "e1 and e3 are equal" << endl; // should not happen
	
	e2 = e3;
	e2.Dump();

	cout << endl << "1*2^(2*2) = " << e3.GetValue(2) << endl; // expected 16
	
	e1.SetExponential(1, -2, 0.5);	
	//cout << endl << "-2^(0.5) = " << e1.GetValue(1) << endl; // expected error

	e1.Reset();
	e1.Dump();
	

    double cf1[3] = {1, 2, 3};
	double cf2[5] = {4, 7, 2, 5, 8};
	
	Polynomial p1(cf1, 3);
	Polynomial p2(cf2, 5);
	Polynomial p3 = p1;

	p1.Dump();
	p2.Dump();
	p3.Dump();

	if(p3 == p1)
		cout << endl << "p1 and p3 are equal" << endl; // should happen
	if(p2 == p1)
		cout << endl << "p1 and p2 are equal" << endl; // should not happen

	p1.Reset(); 
	p1.Dump();

	Function* F;
	
	F = &pow3;
	F->Dump();
	cout << endl << "Value of pow3 = 5*x^3 if x = 2: " << F->GetValue(2) << endl; // expected 40

	F = &p3;
	F->Dump();
	cout << endl << "Value of p3 = 1 + 2*x + 3*x^2 if x = 2: " << F->GetValue(2) << endl; // expected 17

	F = &e3;
	F->Dump();

	return 0;
}