
/**********************************************************************************************************
Author: Matthew Solbrack
Date: 07/06/2018
Description: These constructors, methods, and variables play the simulation for Langston's Ant Simulation.
This robust program creates a dynamic 2D array for the board (and deletes it when finished). Controls
the Ant and follows the instructions of the Langston's Ant Simulation. 
***********************************************************************************************************/
#include "ant.hpp"
#include "menuClass.hpp"

ant::ant(int getRow, int getColumn, int startingRow, int startingColumn, int steps)
{
	// initialize rows, columns, number of steps, initial Ant Row, initial Ant Column, 
	rows = getRow;
	columns = getColumn;
	plays = steps;
	antRow = startingRow-1;
	antColumn = startingColumn-1;

	//initialize the number 1 to start the Row display on the left, initilize the counter 
	//for the steps
	numberRowDisplay = 1;
	count = 1;

	// Creat the dynamic 2D array board
	playingBoard = new char*[rows];
	for (int makeColumn = 0; makeColumn < rows; ++makeColumn)
		playingBoard[makeColumn] = new char[columns];

	//Put spaces into each spot on the board
	for (int inputRow = 0; inputRow < rows; ++inputRow)
	{
		for (int inputColumn = 0; inputColumn < columns; ++inputColumn)
			playingBoard[inputRow][inputColumn] = ' ';
	}
	
	// Initialize the starting location of the ant
	antLocationPointer = &playingBoard[startingRow - 1][startingColumn - 1];

	//Take the next steps with the first step
	firstPlay();
}

/****************************************************************************************
Description: This constructor initializes all the variables for the program. It creates
the board for the simulation using a dynamic 2D array. 
****************************************************************************************/


void ant::displayBoard()
{	
	if (orientation() == true)
		cout << "Step: " << count << " (Ant oritentation is north/south)" << endl;
	else
		cout << "Step: " << count << " (Ant oritentation is west/east)" << endl;

	//first row display the column numbers
	for (int displayColumn = 1; displayColumn < columns + 1; ++displayColumn)
		cout << "  " << displayColumn;
	cout << endl;

	//display the remaining parts of the board
	for (int eachRow = 0; eachRow < rows; ++eachRow)
	{
		cout << numberRowDisplay;
		for (int eachColumn = 0; eachColumn < columns; ++eachColumn)
			cout << " " << playingBoard[eachRow][eachColumn] << " ";
		cout << endl;
		++numberRowDisplay;
	}
	numberRowDisplay = 1;
	++count;
}

/****************************************************************************************
Description: This method displays the board for the simulation. It also displays
the Step # and the orientation of the Ant.
****************************************************************************************/

bool ant::orientation()
{
	if (plays % 2 == 0)
		return true;
	else
		return false;
}

/****************************************************************************************
Description: This method decideds the orientation of the ant. 
****************************************************************************************/

void ant::firstPlay()
{
	//Put * in the location of the ant
	*antLocationPointer = '*';

	//display the initial board
	displayBoard();

	//If the Ant is facing north/south
	if (orientation() == true)
	{
		//Change the Ant location to #
		*antLocationPointer = '#';

		//Move the ant location 90 degrees to the right and check the bounds
		int changeColumn = antColumn + 1;
		int checkColumn = boundsChecking(changeColumn, true);
		antLocationPointer = &playingBoard[antRow][checkColumn];
		antColumn = checkColumn;

		//Hold the char for the current pointer location before it is changed to "*"
		tempHolding = *antLocationPointer;

		//Change the Ant location to "*"
		*antLocationPointer = '*';

		//minus one from number of steps
		--plays;

		//display the board
		displayBoard();
	}

	//If the Ant is facing west/east
	else
	{
		//Change the Ant location to #
		*antLocationPointer = '#';

		//Move the Ant location 90 degrees to the right and check the bounds
		int changeRow = antRow - 1;
		int checkRow = boundsChecking(changeRow, false);
		antLocationPointer = &playingBoard[checkRow][antColumn];
		antRow = checkRow;

		//Hold the char for the current pointer location before it is changed to "*"
		tempHolding = *antLocationPointer;

		//Change the Ant location to "*"
		*antLocationPointer = '*';

		//minus one from number of steps
		--plays;

		//display the board
		displayBoard();
	}

	//run the program for the next steps
	antLocation();

}

/****************************************************************************************
Description: This method is the first two steps of the simulation. If the simulation is
longer than two steps it continues to the next step. 
****************************************************************************************/


void ant::antLocation()
{
	//While there are steps left to do follow these instructions
	do 
	{
		//if the Ant location is <blank> and north/south orientation follow these instructions
		if (orientation() == true && tempHolding == ' ')
		{
			//Change the Ant location to #
			*antLocationPointer = '#';

			//Move the Ant location 90 degrees to the right and check the bounds
			int changeColumn = antColumn + 1;
			int checkColumn = boundsChecking(changeColumn, true);
			antLocationPointer = &playingBoard[antRow][checkColumn];
			antColumn = checkColumn;

			//Hold the char for the current pointer location before it is changed to "*"
			tempHolding = *antLocationPointer;

			//Change the Ant location to "*"
			*antLocationPointer = '*';

			//minus one from number of steps
			--plays;

			//display the board
			displayBoard();
		}

		//if the Ant location is "#" and north/south orientation follow these instructions
		else if (orientation() == true && tempHolding == '#')
		{
			//Change the Ant location to <blank>
			*antLocationPointer = ' ';

			//Move the Ant location 90 degrees to the left and check the bounds
			int changeColumn = antColumn - 1;
			int checkColumn = boundsChecking(changeColumn, true);
			antLocationPointer = &playingBoard[antRow][checkColumn];
			antColumn = checkColumn;

			//Hold the char for the current pointer location before it is changed to "*"
			tempHolding = *antLocationPointer;

			//Change the Ant location to "*"
			*antLocationPointer = '*';

			//minus one from number of steps
			--plays;

			//display the board
			displayBoard();
		}

		//if the Ant location is <blank> and west/east orientation follow these instructions
		else if (orientation() == false && tempHolding == ' ')
		{
			//Change the Ant location to "#"
			*antLocationPointer = '#';

			//Move the Ant location 90 degrees to the right and check the bounds
			int changeRow = antRow - 1;
			int checkRow = boundsChecking(changeRow, false);
			antLocationPointer = &playingBoard[checkRow][antColumn];
			antRow = checkRow;

			//Hold the char for the current pointer location before it is changed to "*"
			tempHolding = *antLocationPointer;

			//Change the Ant location to "*"
			*antLocationPointer = '*';

			//minus one from number of steps
			--plays;

			//display the board
			displayBoard();
		}

		//if the Ant location is "#" and west/east orientation follow these instructions
		else if (orientation() == false && tempHolding == '#')
		{
			//Change the Ant location to <blank>
			*antLocationPointer = ' ';

			//Move the Ant location 90 degrees to the left and check the bounds
			int changeRow = antRow + 1;
			int checkRow = boundsChecking(changeRow, false);
			antLocationPointer = &playingBoard[checkRow][antColumn];
			antRow = checkRow;

			//Hold the char for the current pointer location before it is changed to "*"
			tempHolding = *antLocationPointer;

			//Change the Ant location to "*"
			*antLocationPointer = '*';

			//minus one from number of steps
			--plays;

			//display the board
			displayBoard();
		}
		//Repeat these instructions until the steps run out
	} while (plays > 1);


	// Delete the Data in the array. 
	for (int i = 0; i < rows; ++i) {
		delete[] playingBoard[i];
	}
	//Delete the array
	delete[] playingBoard;

	//Send back to menu's to see if the user would like to play again.
	menuClass(false);
}

/****************************************************************************************
Description: This method is the play of the Ant. It follows the following rules:
If the ant is on a <blank> space, turn right 90 degrees and change the space to "#".
If the ant is on a "#" space, turn left 90 degrees and change the space to <blank>.
After the steps run out the array is deleted and a "play again" menu is prompted. 
****************************************************************************************/

int ant::boundsChecking(int check, bool orientation)
{
	// If the Ant orientation is north/south follow these instructions
	if (orientation == true)
	{
		//if the Ant is going off the edge on the east side revert it back to the far left
		if (check >= columns)
			return 0;

		//if the Ant is going off the edge on the west side revert it back to the far right
		else if (check < 0)
			return columns - 1;

		//If no chnages are needed return the orginal location
		else
			return check;
	}

	// If the Ant orientation is west/east follow these instructions
	else
	{
		// If the Ant is going too far south revert it to the far north
		if (check >= rows)
			return 0;
		
		//If the Ant is going too far north revert it to the far south
		else if (check < 0)
			return rows - 1;

		//If no changes are needed send the row back
		else
			return check;
	}
}

/****************************************************************************************
Description: This method checks the edges of the array. If the Ant is about to run 
off the board it is wrapped to the otherside. 
****************************************************************************************/
