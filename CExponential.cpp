/*! @file CExponential.cpp
	@brief Implementation of Exponential class 
	@author Alessia Marchese

	Details.
*/ 

#include "CExponential.h"
#include <cmath>

/// @brief default constructor
Exponential::Exponential()
{
	//cout << "Exponential - default constructor" << endl;
	Init();
}


/// @brief constructor
///	@param b base
///	@param k coefficient k
/// @param c coefficient c
Exponential::Exponential(double b, double k, double c)
{
	//cout << "Exponential - constructor with parameters" << endl;
	Init();
	SetExponential(b, k, c);
}


/// @brief copy constructor
Exponential::Exponential(const Exponential& e)
{
	//cout << "Exponential - copy constructor" << endl;
	Init(e);
}


/// @brief destructor
Exponential::~Exponential()
{
	//cout << "Exponential - destructor" << endl;
	Reset();
}


/// @brief overload operator =
Exponential& Exponential::operator=(const Exponential& e)
{
	//cout << "Exponential - operator =" << endl;
	Init(e);
	return *this;
}


/// @brief overload operator ==
bool Exponential::operator==(const Exponential& e)
{
	//cout << "Exponential - operator ==" << endl;
	if (e.b_coeff == b_coeff && e.k_coeff == k_coeff && e.c_coeff == c_coeff)
		return true;
		
	return false;
}


/// @brief default initialization of the object
void Exponential::Init()
{
	b_coeff = 1;
	k_coeff = 1;
	c_coeff = 0;
}


/// @brief initialization of the object as a copy of an object 
/// @param e reference to the object that should be copied 
void Exponential::Init(const Exponential &e)
{
	b_coeff = e.b_coeff;
	k_coeff = e.k_coeff;
	c_coeff = e.c_coeff;
}


/// @brief total reset of the object  
void Exponential::Reset()
{
	b_coeff = 0;
	k_coeff = 0;
	c_coeff = 0;}


/// @brief sets the coefficient and the exponent
/// @param b base
///	@param k coefficient k
///	@param c coefficient c
void Exponential::SetExponential(double b, double k, double c)
{
	if(b <= 0)
	{
		ErrorMessage("SetExponential: base cannot be negative or 0");
		Init();
		cout << endl << "Function set to default: 1*1^(x*0)" << endl;
		return;
	}
	b_coeff = b;
	k_coeff = k;
	c_coeff = c;
}


/// @brief sets the base b
///	@param b coefficient
void Exponential::SetB(double b)
{
	SetExponential(b, k_coeff, c_coeff);
}


/// @brief sets the coefficient k
///	@param k coefficient
void Exponential::SetK(double k)
{
	SetExponential(b_coeff, k, c_coeff);
}


/// @brief sets the coefficient c
///	@param c coefficient
void Exponential::SetC(double c)
{
	SetExponential(b_coeff, k_coeff, c);
}


/// @brief returns the value of b_coeff
double Exponential::GetB()
{
	return b_coeff;
}


/// @brief returns the value of k_coeff
double Exponential::GetK()
{
	return k_coeff;
}


/// @brief returns the value of b_coeff
double Exponential::GetC()
{
	return c_coeff;
}


/// @brief returns the value of the function, given an input 
///	@param in the input
///	@return the value of the function
double Exponential::GetValue(double in)
{
	return k_coeff*pow(b_coeff, (c_coeff * in));
}


/// @brief writes an error message 
/// @param string message to be printed
void Exponential::ErrorMessage(const char *string) 
{	
	cout << endl << "ERROR -- Exponential --";
	cout << string << endl;
}

/// @brief writes a warning message 
/// @param string message to be printed
void Exponential::WarningMessage(const char *string)
{	
	cout << endl << "WARNING -- Exponential --";
	cout << string << endl;
}

/// @brief gives the status of the object 
void Exponential::Dump()
{
	//cout << endl << "Exponential Function -- DUMP" << endl;
	cout << k_coeff << "*" << b_coeff << "^" << "(" << c_coeff << "*x)";
}