#include <iostream>
#include "tic_tac_toe.h"
using namespace std;

void TicTacToe::play()
{
	int my_row, my_col;
	player1_turn = true;
	display();

	do
	{
		if (player1_turn)
			cout << "Player 1: select a row and column number between 1 and 3 to mark 'X' on the grid: ";
		else if (player2_turn)
			cout << "Player 2: select a row and column number between 1 and 3 to mark 'O' on the grid: ";

		if (cin >> my_row >> my_col)
		{
			if ((my_row >= 1 && my_row <= 3) && (my_col >= 1 && my_col <= 3))
			{
				mark(my_row - 1, my_col - 1);

			}
		}
	} while (!gameOver);
}

bool TicTacToe::IsFull() const
{
	return usedSquares == 9;
}

void TicTacToe::mark(int rowIndex, int colIndex)
{
	if (grid[rowIndex][colIndex] == 'X' || grid[rowIndex][colIndex] == 'O')
	{
		cout << "\nThat row and column number has been used already." << endl;
		return;
	}

	if (player1_turn)
	{
		grid[rowIndex][colIndex] = 'X';
		usedSquares++;

		// Check player1's win condition starting right after the 3rd attempt
		// After player1's 3rd attempt, usedSquares will be equal to 5
		if (usedSquares >= 5)                      
			checkWinCondition();              
		player1_turn = false;
		player2_turn = true;
	}
	else if (player2_turn)
	{
		grid[rowIndex][colIndex] = 'O';
		usedSquares++;

		// Check player2's win condition starting right after the 3rd attempt
        // After player2's 3rd attempt, usedSquares will be equal to 6
		if (usedSquares >= 6)                
			checkWinCondition();
		player2_turn = false;
		player1_turn = true;
	}

	if (!gameOver)
		display();
}

void TicTacToe::checkWinCondition()
{
	char str;
	// Determine which player is playing
	int whichPlayer = usedSquares % 2;     

	if (whichPlayer)                       // if (player == 1) then player1 is playing 
	{
		str = 'X';
		whichPlayer = 1;
	}
	else                                  // if (player == 0) then player2 is playing
	{
		str = 'O';
		whichPlayer = 2;
	}

	if ((grid[0][0] == str && grid[0][1] == str && grid[0][2] == str)
		|| (grid[1][0] == str && grid[1][1] == str && grid[1][2] == str)
		|| (grid[2][0] == str && grid[2][1] == str && grid[2][2] == str)
		|| (grid[0][0] == str && grid[1][0] == str && grid[2][0] == str)
		|| (grid[0][1] == str && grid[1][1] == str && grid[2][1] == str)
		|| (grid[0][2] == str && grid[1][2] == str && grid[2][2] == str)
		|| (grid[0][0] == str && grid[1][1] == str && grid[2][2] == str)
		|| (grid[2][0] == str && grid[1][1] == str && grid[0][2] == str))
	{
		gameOver = true;
		display();
		cout << "Player " << whichPlayer << " wins!" << endl;
		cout << "Game Over!\n" << endl;
		cout << "Do you want to play again?" << endl;
		cout << "Type 'y' for yes or 'n' for no: ";

		if (cin >> str && str == 'y')
		{
			reset();
			play();
		}
	}
	else if (IsFull())
	{
		gameOver = true;
		display();
		cout << "It's a tie!" << endl;
		cout << "Game Over!n" << endl;
		cout << "Do you want to play again?" << endl;
		cout << "Type 'y' for yes or 'n' for no: ";

		if (cin >> str && str == 'y')
		{
			reset();
			play();
		}
	}
}

void TicTacToe::display() const
{
	cout << "\nTic-Tac-Toe" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
			cout << grid[i][k] << " | ";
		cout << endl;
	}
	cout << endl;
}

void TicTacToe::reset()
{
	for (int i = 0; i < 3; i++)
		for (int k = 0; k < 3; k++)
			grid[i][k] = '#';

	player1_turn = player2_turn = gameOver = false;
	usedSquares = 0;
}