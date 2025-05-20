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
	vector<Function*> Functions = {0};

	cout << endl << "### Functions ###" << endl;
	cout << endl << "Select and action:" << endl;

	cout 
	<< "1) Visualizza la lista delle funzioni" << endl
	<< "2) Inserisci una funzione" << endl
	<< "3) Elimina una funzione" << endl
	<< "4) Elimina tutte le funzioni" << endl
	<< "5) Seleziona una funzione" << endl
	<< "0) Esci dal menu'" << endl;

	while (user_choice != 0)
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
				cout << "Invalid choice" << endl;
				break;
		}
	}
	DeleteAllFunctions(Functions);
	cout << endl << "bye bye" << endl;
}

/// @brief Displays all the functions inserted by the user
///	@param Functions vecotr of pointers to objects of class Function
void DisplayFunctions(vector<Function*> Functions)
{
	if (Functions.empty())
	{
		cout << endl << "No function available" << endl;
		return;
	}

	int n = 0;
	cout << endl << "---FUNCTIONS---" << endl;
	for(Function* Func : Functions)
	{
		cout << ++n << ")" << endl;
		Func->Dump();
		cout << endl;
	}
	
}

/// @brief Allows the user to insert a new function in the Functions vector
///	@param Functions vecotr of pointers to objects of class Function
void InsertFunctions(vector<Function*> Functions)
{
	Function* NewFunction;
	int func_choice;
	cout << "Select the function:" << endl;
	cout << "1) Polynomial" << endl << "2) Power" << "3) Exponential" << endl;
	
	if( func_choice == 1 )
	{
		Polynomial* NewPol = new Polynomial;

		if(NewPol = NULL)
		{
			cout << endl << "Allocation error: Memory not allocated" << endl;
			exit(-1);
		}

		int deg;
		int confirm = -1;

		do
		{
			cout << endl << "Insert the degree: ";
			cin >> deg;

			double* coeff = new double[deg + 1];

			cout << endl << "Insert the coefficients: " << endl;
			for (int i =  0; i <= deg; i++)
			{
				cout << endl << "Coefficient of x^" << deg << ":";
				cin >> coeff[i];
			}

			NewPol->SetPolynomial(coeff, (deg + 1));

			do
			{
				cout << endl << "Is this your function?" << endl;
				NewPol->Dump();
				cout 
				<< "1) Yes" << endl
				<< "2) No" << endl;

				cin >> confirm;
				if (confirm != 1 || confirm != 2)
				{
					cout << endl << "Invalid selection" << endl;
				}
			} 
			while (confirm != 1 || confirm != 2);

			delete coeff;
		}
		while (confirm != 1);
		
		NewFunction = NewPol;
	}


	else if( func_choice == 2 )
	{
		Power* NewPow = new Power;

		if(NewPow = NULL)
		{
			cout << endl << "Allocation error: Memory not allocated" << endl;
			exit(-1);
		}

		int confirm = -1;
		double p_e_coeff = 0;
		double p_k_coeff = 0;

		do
		{
			cout << endl << "Insert the exponent: ";
			cin >> p_e_coeff;
			cout << endl << "Insert the coefficient: ";
			cin >> p_k_coeff;
			NewPow->SetPower(p_k_coeff, p_e_coeff);

			do
			{
				cout << endl << "Is this your function?" << endl;
				NewPow->Dump();
				cout 
				<< "1) Yes" << endl
				<< "2) No" << endl;
				if (confirm != 1 || confirm != 2)
				{
					cout << endl << "Invalid selection" << endl;
				}
			} 
			while (confirm != 1 || confirm != 2);
		}
		while (confirm != 1);

		NewFunction = NewPow;
	}


	else if ( func_choice == 3 )
	{
		Exponential* NewExp = new Exponential;

		if(NewExp = NULL)
		{
			cout << endl << "Allocation error: Memory not allocated" << endl;
			exit(-1);
		}

		int confirm = -1;

		double p_c_coeff = 0;
		double p_k_coeff = 0;
		double p_b_coeff = 0;

		do
		{
			cout << endl << "Insert the exponent coefficient: ";
			cin >> p_c_coeff;
			cout << endl << "Insert the base: ";
			cin >> p_b_coeff;
			cout << endl << "Insert the base coefficient: ";
			cin >> p_k_coeff;
			NewExp->SetExponential(p_b_coeff, p_k_coeff, p_c_coeff);
			do
			{
				cout << endl << "Is this your function?" << endl;
				NewExp->Dump();
				cout 
				<< "1) Yes" << endl
				<< "2) No" << endl;
				if (confirm != 1 || confirm != 2)
				{
					cout << endl << "Invalid selection" << endl;
				}
			} 
			while (confirm != 1 || confirm != 2);
		}
		while (confirm != 1);

		NewFunction = NewExp;
	}
	else
	{
		cout << endl << "Invalid selection" << endl;
	}

	Functions.push_back(NewFunction);
}

/// @brief Allows the user to delete a function in the Functions vector
///	@param Functions vecotr of pointers to objects of class Function
void DeleteFunction(vector<Function *> Functions)
{
	int del_choice = -1;
	int confirm = 0;

	if (Functions.empty())
	{
		cout << endl << "No function available" << endl;
		return;
	}

	do
	{
		do
		{
			cout << endl << "Select the function to be deleted: " << endl;
			DisplayFunctions(Functions);
			cin >> del_choice;
			if(del_choice < 1 || del_choice > Functions.size())
				cout << endl << "Invalid selection" << endl;
		} while (del_choice < 1 || del_choice > Functions.size());
		
		
		do
		{
			cout << endl << "Is this the function you want to delete?" << endl;
			Functions.at((del_choice - 1))->Dump();
			cout 
			<< "1) Yes" << endl
			<< "2) No" << endl;

			cin >> confirm;
			if (confirm != 1 || confirm != 2)
			{
				cout << endl << "Invalid selection" << endl;
			}
		} 
		while (confirm != 1 || confirm != 2);
	}
	while (confirm != 1);

	if(Functions.at(del_choice - 1) != NULL)
	{
		delete Functions.at(del_choice - 1);
	}
	Functions.erase(Functions.begin()+(del_choice - 1));
}

/// @brief Deletes all the functions in the Functions vector
///	@param Functions vecotr of pointers to objects of class Function
void DeleteAllFunctions(vector<Function *> Functions)
{
	if (Functions.empty())
	{
		cout << endl << "No function available" << endl;
		return;
	}



	Functions.clear();
	cout << endl << "All Functions were deleted" << endl;
}

/// @brief Allows the user to select a function in the Functions vector and get the value given an input
///	@param Functions vecotr of pointers to objects of class Function
void SelectFunction(vector<Function *> Functions)
{
	int sel_choice = -1;
	int confirm = 0;
	int in = 0;

	if (Functions.empty())
	{
		cout << endl << "No function available" << endl;
		return;
	}

	do
	{
		do
		{
			cout << endl << "Select the function to be deleted: " << endl;
			DisplayFunctions(Functions);
			cin >> sel_choice;
			if(sel_choice < 1 || sel_choice > Functions.size())
				cout << endl << "Invalid selection" << endl;
		} while (sel_choice < 1 || sel_choice > Functions.size());

		do
		{
			cout << endl << "Is this the function you want to select" << endl;
			Functions.at((sel_choice - 1))->Dump();
			cout 
			<< "1) Yes" << endl
			<< "2) No" << endl;

			cin >> confirm;
			if (confirm != 1 || confirm != 2)
			{
				cout << endl << "Invalid selection" << endl;
			}
		} 
		while (confirm != 1 || confirm != 2);
	}
	while (confirm != 1);

	cout << endl << "Insert the value of x: " << endl;
	cin >> in;
	Functions.at((sel_choice - 1))->GetValue(in);
}