/**********************************************************************************************************
Author: Matthew Solbrack
Date: 7/5/2018
Description: Header file for the menuClass.cpp. These constructors, variables, and methods are used
to create a menu for the program about Langston's Ant Simulation. 
***********************************************************************************************************/

#ifndef MENUCLASS_HPP
#define MENUCLASS_HPP
#include <iostream>
#include "ant.hpp"
#include <cstdlib>
#include <string>
using namespace std;

class menuClass
{
private:
	char random; // used for random choice option for random starting location
	int choice; // used for input for first menu
	int rows; // how many rows?
	int columns; // how many columns
	int steps; // how many steps
	int startingColumn; // starting column
	int startingRow; // starting row

public:
	menuClass(bool);
	void secondMenu();
	void randomChoice();
	void manualChoice();
	void checkInput(int*);
	void checkSteps(int*);
	void initialize();

};

#endif

