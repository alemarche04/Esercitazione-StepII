/*! @file CPolynomial.h
	@brief A class for polynomial functions 
	@author Alessia Marchese

	Details.
*/ 


#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <cmath>
#include <cstring>

#include "CFunction.h"

using namespace std;

class Polynomial : public Function
{
private:
    double* coeff;
    int degree;

public:
    
	/// @name CONSTRUCTORs and DESTRUCTOR 
	/// @{
    Polynomial();
	Polynomial(const double* coefficients, int size);
    Polynomial(const Polynomial& p);
    ~Polynomial();
	/// @}

	/// @name OPERATORS 
	/// @{
    Polynomial& operator=(const Polynomial& p);
	Polynomial operator+(const Polynomial& p);
	bool operator==(const Polynomial& p);
	/// @}


	void SetPolynomial(const double* coefficients, int size);
    double GetValue(double in);
	
	void Reset();

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}
   
};

#endif