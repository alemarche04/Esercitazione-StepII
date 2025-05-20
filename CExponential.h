/*! @file CExponential.h
	@brief A class for Exponential functions
	@author Alessia Marchese

	Details.
*/ 

#ifndef Exponential_H
#define Exponential_H

#include "CFunction.h"

class Exponential : public Function
{
private: // k*b^(cx) con b>0
	double b_coeff;
	double k_coeff;
	double c_coeff;

public:
	/// @name CONSTRUCTORs and DESTRUCTOR 
	/// @{
    Exponential();
	Exponential(double b, double k, double c);
    Exponential(const Exponential& e);
    ~Exponential();
	/// @}

	/// @name OPERATORS 
	/// @{
    Exponential& operator=(const Exponential& e);
	bool operator==(const Exponential& e);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Exponential& e);							
	void Reset();												
	/// @}

	/// @name GETTERS / SETTERS
	/// @{
	void SetExponential(double b, double k, double c);
	void SetB(double b);
	void SetK(double k);
	void SetC(double c);
	double GetB();
	double GetK();
	double GetC();
	double GetValue(double in);
	/// @}

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}

};

#endif