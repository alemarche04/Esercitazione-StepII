/*! @file Interface.cpp
	@brief Implementation of a User Interface to work with Functions
	@author Alessia Marchese

	Details.
*/

#include "Interface.h"

/// @brief Displays the menu and takes the user input
void DisplayMenu()
{
	int user_choice = -1;
	vector<Function*> Functions;
	cout << endl << "######## FUNCTIONS MENU ########" << endl << endl;	
	do
	{
		PrintActions();

		cin >> user_choice;
		
		if (cin.fail() == true)
		{
	
			InputError(user_choice);
			user_choice = -1;
		}
		else
		{
			switch (user_choice)
			{
				case 1:
			
					DisplayFunctions(Functions);
					break;
				case 2:
			
					InsertFunctions(Functions);
					break;
				case 3:
			
					DeleteFunction(Functions);
					break;
				case 4:
			
					DeleteAllFunctions(Functions);
					break;
				case 5:
			
					SelectFunction(Functions);
					break;
				case 0:
			
					break;
				default:
			
					ErrorMessage("Invalid selection");
					user_choice = -1;
					break;
			}
		}
	}
	while (user_choice != 0);
	DeleteAllFunctions(Functions);
	cout << endl << "bye bye" << endl;
}

/// @brief Prints the different actions the user can select
void PrintActions()
{
	cout << endl << "Select an action:" << endl;

		cout 
		<< "1) Display all the functions" << endl
		<< "2) Insert a new function" << endl
		<< "3) Delete a function" << endl
		<< "4) Delete all functions" << endl
		<< "5) Select a function and calculate the value" << endl
		<< "0) Exit" << endl;
}

/// @brief Displays all the functions inserted by the user
///	@param Functions vector of pointers to objects of class Function
void DisplayFunctions(vector<Function*>& Functions)
{
	if (Functions.empty())
	{
		ErrorMessage("No function available");
		return;
	}

	int n = 0;
	cout << endl << endl << "---FUNCTIONS---" << endl;
	for(Function* Func : Functions)
	{
		cout << ++n << ") ";
		Func->Dump();
		cout << endl;
	}

	cout << endl;
}

/// @brief Allows the user to insert a new function in the Functions vector
///	@param Functions vector of pointers to objects of class Function
void InsertFunctions(vector<Function*>& Functions)
{
	size_t func_choice = 0;

	do{
		cout << endl << "Available functions:" << endl;
		cout << 
		"1) Polynomial" << endl << 
		"2) Power" << endl << 
		"3) Exponential" << endl << endl <<
		"4) Go back to main menu" << endl;
		cout << endl << "Choose a function: ";
		cin >> func_choice;

		if (cin.fail() == true)
		{
			InputError(func_choice);
		}
		else if( func_choice == 1 )
		{
	
			InsertPolynomial(Functions);		
		}
		else if( func_choice == 2 )
		{
	
			InsertPower(Functions);
		}
		else if ( func_choice == 3 )
		{
	
			InsertExponential(Functions);
		}
		else if( func_choice == 4)
		{
	
			return;
		}
		else
		{
			ErrorMessage("Invalid selection");
			func_choice = 0;
		}
	} 
	while (func_choice == 0);
	cout << endl;
}

/// @brief Handles the creation of a new polynomial function
///	@param Functions vector of pointers to objects of class Function
void InsertPolynomial(vector<Function*>& Functions)
{
	Polynomial* NewPol = new Polynomial;

	if(!NewPol)
	{			
		ErrorMessage("Memory not allocated");
		exit(-1);
	}

	int deg;
	int confirm = 0;

	do
	{
		cout << endl << "Insert the degree: ";
		cin >> deg;
		if (cin.fail() == true)
		{
			ErrorMessage("Invalid selection");
			cin.clear(); 
			cin.ignore(256, '\n');
			delete NewPol;
			return;
		}

		double* coeff = new double[deg + 1];
		if(!coeff)
		{
			exit(-1);
		}

		cout << endl << "Insert the coefficients: " << endl;
		for (int i =  0; i <= deg; i++)
		{
			cout << endl << "Coefficient of x^" << i << ":";
			cin >> coeff[i];
			if (cin.fail() == true)
			{
				ErrorMessage("Invalid selection");
				cin.clear(); 
				cin.ignore(256, '\n');
				delete NewPol;
				return;
			}
		}

		NewPol->SetPolynomial(coeff, (deg + 1));

		do
		{
			cout << endl << "Is this your function?" << endl;
			NewPol->Dump();
			cout << endl
			<< "1) Yes" << endl
			<< "2) No" << endl;

			cin >> confirm;
			if (cin.fail() == true)
			{
				InputError(confirm);
			}
			else if (confirm != 1 && confirm != 2)
			{
				ErrorMessage("Invalid selection");
			}
		} 
		while (confirm != 1 && confirm != 2);

		delete[] coeff;
	}
	while (confirm != 1);
	
	Functions.push_back(NewPol);
}

/// @brief Handles the creation of a new power function
///	@param Functions vector of pointers to objects of class Function
void InsertPower(vector<Function*>& Functions)
{
	Power* NewPow = new Power;

	if(!NewPow)
	{
		cout << endl << "Memory not allocated" << endl;
		exit(-1);
	}

	int confirm = 0;
	double p_e_coeff = 0;
	double p_k_coeff = 0;

	do
	{
		cout << endl << "Insert the exponent: ";
		cin >> p_e_coeff;
		if (cin.fail() == true)
		{
			ErrorMessage("Invalid selection");
			cin.clear(); 
			cin.ignore(256, '\n');
			delete NewPow;
			return;
		}
		cout << endl << "Insert the coefficient: ";
		cin >> p_k_coeff;
		if (cin.fail() == true)
		{
			ErrorMessage("Invalid selection");
			cin.clear(); 
			cin.ignore(256, '\n');
			delete NewPow;
			return;
		}
		NewPow->SetPower(p_k_coeff, p_e_coeff);

		do
		{
			cout << endl << "Is this your function?" << endl;
			NewPow->Dump();
			cout << endl
			<< "1) Yes" << endl
			<< "2) No" << endl;
			cin >> confirm;
			if (cin.fail() == true)
			{
				InputError(confirm);
			}
			else if (confirm != 1 && confirm != 2)
			{
				ErrorMessage("Invalid selection");

			}
		} 
		while (confirm != 1 && confirm != 2);
	}
	while (confirm != 1);

	Functions.push_back(NewPow);
}

/// @brief Handles the creation of a new exponential function
///	@param Functions vector of pointers to objects of class Function
void InsertExponential(vector<Function*>& Functions)
{
	Exponential* NewExp = new Exponential;

	if(!NewExp)
	{
		ErrorMessage("Memory not allocated");
		exit(-1);
	}

	int confirm = 0;

	double e_c_coeff = 0;
	double e_k_coeff = 0;
	double e_b_coeff = 0;

	do
	{
		cout << endl << "Insert the exponent coefficient: ";
		cin >> e_c_coeff;
		if (cin.fail() == true)
		{
			ErrorMessage("Invalid selection");
			cin.clear(); 
			cin.ignore(256, '\n');
			delete NewExp;
			return;
		}
		cout << endl << "Insert the base (cannot be negative or 0): ";
		cin >> e_b_coeff;
		if (cin.fail() == true)
		{
			ErrorMessage("Invalid selection");
			cin.clear(); 
			cin.ignore(256, '\n');
			delete NewExp;
			return;
		}
		cout << endl << "Insert the base coefficient: ";
		cin >> e_k_coeff;
		if (cin.fail() == true)
		{
			ErrorMessage("Invalid selection");
			cin.clear(); 
			cin.ignore(256, '\n');
			delete NewExp;
			return;
		}
		NewExp->SetExponential(e_b_coeff, e_k_coeff, e_c_coeff);
		do
		{
			cout << endl << "Is this your function?" << endl;
			NewExp->Dump();
			cout << endl
			<< "1) Yes" << endl
			<< "2) No" << endl;
			cin >> confirm;
			
			if (cin.fail() == true)
			{
				InputError(confirm);
			}
			else if (confirm != 1 && confirm != 2)
			{
				ErrorMessage("Invalid selection");
			}
		} 
		while (confirm != 1 && confirm != 2);
	}
	while (confirm != 1);

	Functions.push_back(NewExp);
}

/// @brief Allows the user to delete a function in the Functions vector
///	@param Functions vector of pointers to objects of class Function
void DeleteFunction(vector<Function*>& Functions)
{
	size_t del_choice = 0;
	int confirm = 0;

	if (Functions.empty())
	{
		ErrorMessage("No function available");
		return;
	}

	do
	{
		do
		{
			del_choice = Choose(Functions, "Select the function to be deleted:");
			if (del_choice == (Functions.size() + 1))
			{
				return;
			}
		} 
		while (del_choice < 1 || del_choice > Functions.size());
		
		do
		{
			confirm = Confirm(Functions, del_choice, "Is this the function you want to delete?");
		} 
		while (confirm != 1 && confirm != 2);
	}
	while (confirm != 1);

	if(Functions.at(del_choice - 1) != NULL)
	{
		delete Functions.at(del_choice - 1);
	}
	Functions.erase(Functions.begin()+(del_choice - 1));
}

/// @brief Deletes all the functions in the Functions vector
///	@param Functions vector of pointers to objects of class Function
void DeleteAllFunctions(vector<Function*>& Functions)
{
	if (Functions.empty())
	{
		cout << endl << "No function to delete" << endl;
		return;
	}

	for(Function* Func : Functions)
	{
		if(Func != NULL)
		{
			delete Func;
		}
	}

	Functions.clear();
	cout << endl << "All Functions were deleted" << endl;
}

/// @brief Allows the user to select a function in the Functions vector and get the value given an input
///	@param Functions vector of pointers to objects of class Function
void SelectFunction(vector<Function*>& Functions)
{
	size_t sel_choice = -1;
	size_t confirm = 0;
	int in = 0;

	if (Functions.empty())
	{
		ErrorMessage("No function available");
		return;
	}

	do
	{
		do
		{
			sel_choice = Choose(Functions, "Select the function you want to calculate the value of:");
			if (sel_choice == (Functions.size() + 1))
			{
				return;
			}
		} 
		while (sel_choice < 1 || sel_choice > Functions.size());

		do
		{
			confirm = Confirm(Functions, sel_choice, "Is this the function you want to select?");
		} 
		while (confirm != 1 && confirm != 2);
	}
	while (confirm != 1);

	cout << endl << "Insert the value of x: " << endl;
	cin >> in;
	if(cin.fail() == true)
	{
		InputError(in);
		return;
	}
	else
	{
		cout << endl << "The result is: " << Functions.at((sel_choice - 1))->GetValue(in) << endl;
	}
}

/// @brief asks the user wich one of the available functions they want to select
///	@param Functions vector of pointers to objects of class Function
/// @param text string of text used to ask the user to select a function
///	@return ID of the selected function
size_t Choose(vector<Function*>& Functions, const string text)
{
	size_t choice;
	cout << endl << endl << text;
	DisplayFunctions(Functions);
	cout << (Functions.size() + 1) << ") Go back to main menu" << endl;
	cin >> choice;
	if (cin.fail() == true) 
	{
		InputError(choice);
    }
	else if (choice < 1 || choice > (Functions.size() + 1))
	{
		ErrorMessage("Invalid selection");
	}
	return choice;
}

/// @brief asks confirmation to the user
///	@param Functions vector of pointers to objects of class Function
/// @param chioce ID of the selected function
/// @param text string of text used to ask confirmation to the user
///	@return confirmation number
size_t Confirm(vector<Function*>& Functions, size_t choice, const string text)
{
	int confirm;
	cout << endl << text << endl;
	Functions.at((choice - 1))->Dump();
	cout << endl
	<< "1) Yes" << endl
	<< "2) No" << endl;

	cin >> confirm;
	if (cin.fail() == true)
	{
		InputError(choice);
	}
	else if (confirm != 1 && confirm != 2)
	{
		ErrorMessage("Invalid selection");
	}
	return confirm;
}


/// @brief writes an error message 
/// @param error message to be printed
void ErrorMessage(const string error)
{
	cout << endl << endl << "ERROR: " << error << endl << endl;
}


/// @brief handles invalid input from the user in the selection menu
void InputError(size_t input)
{
	ErrorMessage("Invalid selection");
	cin.clear(); 
	cin.ignore(256, '\n');
	input = 0;
}