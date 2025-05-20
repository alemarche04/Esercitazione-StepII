/*! @file CPower.h
	@brief A class for power functions
	@author Alessia Marchese

	Details.
*/ 

#ifndef POWER_H
#define POWER_H

#include "CFunction.h"

class Power : public Function
{
private:
	double k_coeff;
	double e_coeff;

public:
	/// @name CONSTRUCTORs and DESTRUCTOR 
	/// @{
    Power();
	Power(double k, double e);
    Power(const Power& p);
    ~Power();
	/// @}

	/// @name OPERATORS 
	/// @{
    Power& operator=(const Power& p);
	bool operator==(const Power& p);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Power &p);							
	void Reset();												
	/// @}

	/// @name GETTERS / SETTERS
	/// @{
	void SetK(double k);
	void SetE(double e);
	void SetPower(double k, double e);
	double GetValue(double in);
	double GetK();
	double GetE();
	/// @}

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}

};

#endif