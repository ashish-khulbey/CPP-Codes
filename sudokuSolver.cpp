#include <iostream>
#include <ctype.h>
#include <cmath>
#include <iomanip>

using namespace std;

int n; //NxN board
int board[10][10] = //initial sample board
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };


void print(int board[10][10], int n) //print board
{
	for(int i=0; i< n ; i++) //row no.
	{
		for(int j=0; j < n; j++) //col no.
		{
			cout<<setw(3)<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool canPlace(int board[10][10], int n, int row, int col, int currNum) //check if CurrNum can be placed in board[row][col]
{
	if(board[row][col]!=0)	return false; //if already a number present in the given board[row][col] 
	for(int x=0;x<n;x++) 
	{
		if(board[row][x]==currNum)	return false; //check if currNum in row RULE-1
		if(board[x][col]==currNum)	return false; //check if currNum in col RULE-2
	}
	int root = sqrt(n); //toal 9x9 board has 9 3x3 boards (assume)
	int r = row - row%root; //starting row of box
	int c = col-col%root; //starting columnm of box
	for(int i=r;i<r+root;i++) //check id CurrNum in the box RULE-3
	{
		for(int j=c;j<c+root;j++)
		{
			if(board[i][j]==currNum)
				return false;
		}
	}
	return true;
}

bool solveSudoku(int board[10][10], int n, int row, int col)
{
	if(row==n) //all rows checked
	{
		return true;
	}
	if(col==n) //fixing a row and checking for all columns in that row
	{
		return solveSudoku(board, n, row+1, 0);
	}
	if(board[row][col] != 0) //filled already
	{
		return solveSudoku(board, n, row, col+1);
	}
	for(int currNum=1;currNum<=n;currNum++)
	{
		if(canPlace(board, n, row, col, currNum)) //check if CurrNum can be inserted
		{
			board[row][col] = currNum; //num inserted
			bool success = solveSudoku(board, n, row, col+1); //Recusion
			if(success)	
				return true;
			board[row][col] = 0; //Backtracking
		}
	}
	return false;
}

int main()
{
	cin>>n;
	bool success = solveSudoku(board, n, 0, 0);
	if(success) //Solved
		print(board, n);
	else //Can't be solved
		cout<<"Can't Solve!!"<<endl;
}
