/*! @file CPolynomial.cpp
	@brief Implementation of Polynomial class 
	@author Alessia Marchese

	Details.
*/ 



#include "CPolynomial.h"

/// @brief default constructor
Polynomial::Polynomial() 
{
	degree = -1;
	coeff = NULL;
}

/// @brief constructor
///	@param coefficients array with the coefficients (format: c0+c1*x+ ...)
///	@param size size of the array
Polynomial::Polynomial(const double* coefficients, int size) 
{
	degree = -1;
	coeff = NULL;
	SetPolynomial(coefficients,size);
}

/// @brief destructor
Polynomial::~Polynomial() 
{    
	if (coeff != NULL) {
		delete coeff;
		coeff = NULL;
	}
}

/// @brief copy constructor
Polynomial::Polynomial(const Polynomial& p) 
{	
	int i;
	
	if (p.coeff == NULL) {
		ErrorMessage("Copy constructor: the object to be copied has no coefficients");
		exit(-1);
	}
	degree = p.degree;
	coeff = new double[degree + 1];
	if (coeff == NULL) {
		ErrorMessage("Copy constructor: cannot allocate memory");
		exit(-1);
	}
	
    for (i=0;i<=degree;i++)
		coeff[i]= p.coeff[i];
}


/// @brief overload operator =
Polynomial& Polynomial::operator=(const Polynomial& p) 
{    
	int i; 
	
	if (this != &p) {
		if (coeff != NULL)
			delete coeff;
        degree = p.degree;
        coeff = new double[degree + 1];
		if (coeff == NULL) {
			ErrorMessage("Operator =: cannot allocate memory");
			exit(-1);
		}
        for (i=0;i<=degree;i++)
			coeff[i]= p.coeff[i];
    }
    return *this;
}

/// @brief overload operator +
Polynomial Polynomial::operator+(const Polynomial& p) 
{    
	int i;
	Polynomial newP;
	int newSize = max(degree, p.degree) + 1;
    
	double* newCoeff = new double[newSize];
	if (newCoeff == NULL) {
		ErrorMessage("Operator +: cannot allocate memory");
		exit(-1);
	}
	
	for (i = 0; i < newSize; ++i) 
        newCoeff[i] = 0.;
        
    for (i = 0; i <= degree; ++i) 
        newCoeff[i] += coeff[i];
        
    for (i = 0; i <= p.degree; ++i) 
        newCoeff[i] += p.coeff[i];
       
    newP= Polynomial(newCoeff, newSize);
	
	delete newCoeff;
    
    return newP;
}

/// @brief overload operator ==
bool Polynomial::operator==(const Polynomial& p) 
{	
	int i;
	
	if (degree != p.degree)
		return false;
	
	for (i=0; i<=degree; i++) {
		if (coeff[i] != p.coeff[i])
			return false;
	}
	
	return true;
}

/// @brief sets the coefficients of the polynomial 
///	@param coefficients array with the coefficients (format: c0+c1*x+ ...)
///	@param size size of the array
void Polynomial::SetPolynomial(const double* coefficients, int size) 
{	
	int i= 0;
	
	if (size < 1) {
		ErrorMessage("SetPolynomial: the degree of the Polynomial cannot be negative");
		exit(-1);
	}
	
	if (coeff != NULL)
		Reset();
	
	degree= size - 1;
    coeff = new double[size];
	if (coeff == NULL) {
		ErrorMessage("SetPolynomial: cannot allocate memory");
		exit(-1);
	}
	
	for (i=0;i<=degree;i++)
		coeff[i]= coefficients[i];
}

/// @brief returns the value of the function, given an input 
///	@param in the input
///	@return the value of the function
double Polynomial::GetValue(double in) 
{        
		int i;
		double x = in;
		double result = 0.0;
        
		result = coeff[0];
		for (i=1; i<=degree; i++) {
			result += coeff[i]*x;
			x *= in;			/* x^i */
		}
        
		return result;
}

/// @brief resets the polynomial 
void Polynomial::Reset() 
{
	degree = -1; 
	if (coeff != NULL) {
		delete coeff;
		coeff = NULL;
	}
}


/// @brief writes an error message 
/// @param string message to be printed
void Polynomial::ErrorMessage(const char *string) 
{
	cout << endl << "ERROR -- Polynomial --";
	cout << string << endl;
}

/// @brief writes a warning message 
/// @param string message to be printed
void Polynomial::WarningMessage(const char *string) 
{	
	cout << endl << "WARNING -- Polynomial --";
	cout << string << endl;
}

/// @brief gives the status of the object 
void Polynomial::Dump() 
{
	cout << endl << "Polynomial Function -- DUMP" << endl;
	int i;
	
	if (degree == -1) {
		cout << "Uninitialized polynomial" << endl;
		return;
	}
	
	if (coeff == NULL) {
		cout << "Degree: " << degree << endl;
		cout << "No coefficients available" << endl;
		return;
	}
	
    for (i = 0; i <= degree; ++i) {
		if (coeff[i] != 0.) {
			cout << (coeff[i] > 0 && i > 0 ? " + " : " ") << coeff[i];
                if (i > 0) {
                    cout << "x";
                    if (i > 1) 
                        cout << "^" << i;
                }
        }
    }
	cout << endl;
}