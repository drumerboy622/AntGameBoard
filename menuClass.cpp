
/**********************************************************************************************************
Author: Matthew Solbrack
Date: 6/30/2018
Description: These methods are menu's in conjuction with the Ant Simulation for project 1 in 
cs 162/400. Each item entered goes through a checkInput method that does input validation.
Input information is sent to ant.cpp to run the simulation. 
***********************************************************************************************************/
#include "menuClass.hpp"


menuClass::menuClass(bool menuOption)
{
	//Initial menu options
	if (menuOption == true)
	{
		cout << "Langston's Ant simulation  	by Matthew Solbrack" << endl << endl;
	FirstMenu:
		cout << "MENU	" << endl;
		cout << "1. Start Langston's Ant simulation" << endl;
	}

	//Used only when simulation is finished
	else if (menuOption == false)
		cout << "\n1. Would you like to play Again?" << endl;
	cout << "2. Quit" << endl << endl;
	cout << "Please choose one option from above: ";
	cin >> choice;

	//input validation for non-integers and negative integers 
	checkInput(&choice);

	//If the user wants to play the simulation move on to the second menu
	if (choice == 1)
		secondMenu();

	//If the user decides to quit
	else if (choice == 2)
	{
		cout << "\nThanks for stopping by!" << endl;
		exit;
	}
	//input validation for other integers
	else
	{
		cout << "\nPlease enter either 1 or 2\n" << endl;
		goto FirstMenu;
	}
}

/****************************************************************************************
Description: This constructor is used in two different ways. It is used as the initial
menu display for the program. It is also used when the simulation is finished
(although the output is different). 
****************************************************************************************/

void menuClass::secondMenu()
{
SecondMenu:
	cout << "[Extra Credit] Would you like a random starting location? (Y/N): ";
	cin >> random;
	if (random == 'y' || random == 'Y')
		randomChoice();
	else if (random == 'n' || random == 'N')
		manualChoice();
	else
	{
		cout << "Please enter Y or N only!" << endl;
		goto SecondMenu;
	}
}

/****************************************************************************************
Description: [Extra Credit] - This method asks if the user would like to start at 
a random point on the board. 
****************************************************************************************/

void menuClass::randomChoice()
{

	cout << "How many rows would you like on the board? ";
	cin >> rows;

	//input Validation
	checkSteps(&rows);

	cout << "How many columns would you like on the board? ";
	cin >> columns;

	//input Validation
	checkSteps(&columns);

	cout << "How many steps would you like to play? ";
	cin >> steps;

	//input Validation
	checkSteps(&steps);

	//This is the equation to find the random number
	//reference https://stackoverflow.com/questions/12657962/how-do-i-generate-a-random-number-between-two-variables-that-i-have-stored
	startingRow = rand() % (rows - 1 + 1) + 1;
	startingColumn = rand() % (columns - 1 + 1) + 1;

	//This method sends the variables to the ant.cpp
	initialize();

}

/****************************************************************************************
Description: This method is used when the user would like the ant to start in a random 
location. Each input goes through checkInput for input validation. The values are put 
into their variable locations and sent through the initialize method. 
****************************************************************************************/

void menuClass::manualChoice()
{
	cout << "How many rows would you like on the board? ";
	cin >> rows;

	//input Validation
	checkSteps(&rows);

	cout << "How many columns would you like on the board? ";
	cin >> columns;

	//input Validation
	checkSteps(&columns);

	cout << "How many steps would you like to play? ";
	cin >> steps;

	//input Validation
	checkSteps(&steps);

	cout << "What row would you like to start on? ";
StartingRow:
	cin >> startingRow;

	//input Validation
	checkInput(&startingRow);

	//Bounds checking on intial row location
	if (startingRow > rows || startingRow < 1)
	{
		cout << "Please pick a number between 1 and " << rows << ": ";
		goto StartingRow;
	}

	cout << "What column would you like to start on? ";
StartingColumn:
	cin >> startingColumn;

	//input Validation
	checkInput(&startingColumn);

	//Bounds checking on intial column location
	if (startingColumn > columns || startingColumn < 1)
	{
		cout << "Please pick a number between 1 and " << columns << ": ";
		goto StartingColumn;
	}

	//This method sends the variables to the ant.cpp
	initialize();

}

/****************************************************************************************
Description: This method is used when the user wants to manually input the ant's initial
location on the board. Each input goes through checkInput for input validation. The 
values are put into their variable locations and sent through the initialize method. 
****************************************************************************************/

void menuClass::checkInput(int * var)
{
	while (!cin || *var < 1)
	{
		cout << "Try Again:  ";
		cin.clear();
		cin.ignore();
		cin >> *var;
	}
}

/****************************************************************************************
Description: This method checks the input to make sure it is an int and greater or 
equal to one. If it is not the previously entered data is cleared and you are prompted
to enter another option. 
****************************************************************************************/

void menuClass::checkSteps(int * var)
{
	while (!cin || *var < 3)
	{
		cout << "Try Again (Must be larger than 2):  ";
		cin.clear();
		cin.ignore();
		cin >> *var;
	}
}

/****************************************************************************************
Description: This method checks the input to make sure it is an int and greater or
equal to three. If it is not the previously entered data is cleared and you are prompted
to enter another option.  This method helps to ensure the board is large enough and 
the there are enough steps to ensure a good simulation experience. 
****************************************************************************************/

void menuClass::initialize()
{
	ant(rows, columns, startingRow, startingColumn, steps);
}

/****************************************************************************************
Description: This method is used to send the data over to the ant.cpp
****************************************************************************************/
