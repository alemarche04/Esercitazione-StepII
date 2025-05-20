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

void DisplayMenu();
void DisplayFunctions(vector<Function*> Functions);
void InsertFunctions(vector<Function*> Functions);
void DeleteFunction(vector<Function*> Functions);
void DeleteAllFunctions(vector<Function*> Functions);
void SelectFunction(vector<Function*> Functions);

#endif