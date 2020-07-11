#ifndef TIC_TAC_TOE_H_
#define TIC_TAC_TOE_H_

class TicTacToe
{
private:
	char grid[3][3]{
		{'#', '#', '#'},
		{'#', '#', '#'},
		{'#', '#', '#'}
	};
	bool player1_turn{false};
	bool player2_turn{ false };
	bool gameOver{ false };
	int usedSquares{ 0 };
public:
	void play();
	void mark(int rowIndex, int colIndex);
	bool IsFull() const;
	void checkWinCondition();
	void display() const;
	void reset();
};

#endif