/*! @file Interface.h
	@brief User Interface to work with Functions
	@author Alessia Marchese

	Details.
*/ 

#ifndef Interface_H
#define Interface_H

#include <iostream>
#include <vector>
#include "CPower.h"
#include "CPolynomial.h"
#include "CExponential.h"
using namespace std;

/// @name Display and print
/// @{
void DisplayMenu();
void PrintActions();
void DisplayFunctions(vector<Function*>& Functions);
/// @}

/// @name Insertion
/// @{
void InsertFunctions(vector<Function*>& Functions);
void InsertPolynomial(vector<Function*>& Functions);
void InsertPower(vector<Function*>& Functions);
void InsertExponential(vector<Function*>& Functions);
/// @}

/// @name Deletion
/// @{
void DeleteFunction(vector<Function*>& Functions);
void DeleteAllFunctions(vector<Function*>& Functions);
/// @}

/// @name Selection
/// @{
void SelectFunction(vector<Function*>& Functions);
/// @}

/// @name Choice and confirmation
/// @{
size_t Choose(vector<Function*>& Functions, const string text);
size_t Confirm(vector<Function*>& Functions, size_t sel_choice, const string text);
/// @}

/// @name Error Handling
/// @{
void ErrorMessage(const string error);
void InputError(size_t input);
/// @}

#endif