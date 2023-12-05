#include<iostream>
using namespace std;

#include <iostream>
using namespace std;
//global vars
			 // fake array
char fakearray[5][5] = {
	{ '-', '-' ,'-', '-', '-' },
	{ '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-' }
};
//real array
int realarray[5][5], row, col, mine;

//check if cell opened
bool opened(char fakearray[5][5], int row, int col)
{
	if (fakearray[row][col] == '-')
	{
		return false;
	}
}
//check if cell is valid
bool isValid(int row, int col)
{
	if ((row > 0) && (row < 5) && (col >= 0) && (col < 5))
	{
		return true;
	}
}

//check is cell is a mine
bool isMine(int row, int col, int realarray[5][5])
{
	if (realarray[row][col] == 11)
	{
		return(true);
	}
	else {
		return(false);
	}
}

//initializing real board
void iniarray(int realarray[5][5]) {

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++)
		{
			realarray[i][j] = 0;
		}
	}

	for (int mineCount = 0; mineCount < 5; ++mineCount) {
		int randomRow = rand() % 5 + 0;
		int randomCol = rand() % 5 + 0;

		// Place the mine in the selected cell
		realarray[randomRow][randomCol] = 11;
	}
	//	 for (int i=0;i<5;i++){
	//    	for (int j=0;j<5;j++)
	//    	{
	//    		cout<< realarray[i][j];
	//    	}
	//    }
	//   
}

//checking adjacent mines
int	checkadjacentmines(int realarray[5][5], int row, int col)
{
	mine = 0;
	//north
	if (isValid(row - 1, col) == true)
	{
		if (isMine(row - 1, col, realarray) == true)
		{
			mine++;
		}
	}
	//north-east
	if (isValid(row - 1, col + 1) == true)
	{
		if (isMine(row - 1, col + 1, realarray) == true)
		{
			mine++;
		}
	}
	//north-west
	if (isValid(row - 1, col - 1) == true)
	{
		if (isMine(row - 1, col - 1, realarray) == true)
		{
			mine++;
		}
	}
	//east
	if (isValid(row, col + 1) == true)
	{
		if (isMine(row, col + 1, realarray) == true)
		{
			mine++;
		}
	}
	//west
	if (isValid(row, col - 1) == true)
	{
		if (isMine(row, col + 1, realarray) == true)
		{
			mine++;
		}
	}
	//south
	if (isValid(row + 1, col) == true)
	{
		if (isMine(row + 1, col, realarray) == true)
		{
			mine++;
		}
	}
	//south-east
	if (isValid(row + 1, col + 1) == true)
	{
		if (isMine(row + 1, col + 1, realarray) == true)
		{
			mine++;
		}
	}
	//south-west
	if (isValid(row + 1, col - 1) == true)
	{
		if (isMine(row - 1, col, realarray) == true)
		{
			mine++;
		}
	}
	return (mine);
}

void printboard(char fakearray[5][5]) {

	// guides
	int guiderow[5] = { 0, 1, 2, 3, 4 };
	int guidecol[5] = { 0, 1, 2, 3, 4 };

	// outputting guides
	cout << "  ";
	for (int i = 0; i < 5; i++) {
		cout << guiderow[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 5; i++) {
		cout << guidecol[i] << " ";
		for (int j = 0; j < 5; j++) {
			cout << fakearray[i][j] << " ";
		}
		cout << endl;
	}
}

//getinput from user
int input(char fakearray[5][5], int& row, int& col) {
	do {
		cout << "Please enter your row and column: " << endl;
		cin >> row >> col;
	} while (!isValid(row, col) || opened(fakearray, row, col));
	return (row,col); // Placeholder, modify as needed
}



void game(char fakearray[5][5], int realarray[5][5], int row, int col)
{
	iniarray(realarray);
	printboard(fakearray);
	input(fakearray, row, col);

	if (isMine(row,col,realarray)==true)
	{	
		fakearray[row][col] == '11';
		printboard(fakearray);
		cout << "\nGame Over!";
	}
	else{

		checkadjacentmines(realarray, row, col);
			if (mine == 0)
			{
				fakearray[row][col] = '0';
				printboard(fakearray);
			}
			else {
				fakearray[row][col] = mine;
				printboard(fakearray);
			}
	}

}


int main() {

	game(fakearray, realarray, row, col);

	return 0;

	system("pause");
}
