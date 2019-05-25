
/**********************************************************************************************************
Author: Matthew Solbrack
Date: 7/6/2018
Description: Header file for the ant.cpp. Ant.cpp is used to display the board and run the backend
data for the Langston's Ant Simulation. 
***********************************************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include <iostream>
using namespace std;

class ant
{
private:
	char** playingBoard; // This will be used for the playing board Array
	int rows, // Used for the board for number of rows
		columns, // Used for the board for number of columns
		numberRowDisplay, // Used to initialize the number display for columns 
		plays, // Used for number of steps
		antRow, // Current row for the Ant
		antColumn, //Current column for the Ant
		count; // Used for counting down the steps
	char *antLocationPointer, // Used to keep track of the Ant Address 
		tempHolding; // Used to temporarily hold the " " or "#" when the Ant changes to "*"

public:
	ant(int, int, int, int, int);
	void displayBoard();
	bool orientation();
	void antLocation();
	void firstPlay();
	int boundsChecking(int, bool);
};

#endif
