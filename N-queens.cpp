/*Problem Link :-
https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/n-queensrecursion-tutorial/
*/

#include <iostream>

using namespace std;

int n, board[10][10]={0}; //globals

bool isvalid(int r, int c) //check if given row and column is a valid on the board --Not Required for this code to run.
{
	if(r>=0 && r<n && c>=0 && c<n)
		return true;
	return false;
}

bool canPlace(int board[10][10], int row, int col) //check if any square (given by row, col) on the board is valid to place the queen.
{
	for(int i=0;i<col;i++) //checking for attacing queen in that row
	{
		if(board[row][i]==1)
			return false;
	}
	for(int i=row,j=col;i>=0 && j>=0;i--,j--) //check upper left diagonal
	{
		if(board[i][j]==1)
			return false;
	}
	for(int i=row,j=col;i<n && j>=0;i++,j--) //check lower left diagonal
	{
		if(board[i][j]==1)
			return false;
	}
	return true;	
}

bool place(int board[10][10], int col)
{
	if (col>=n) //base case, when all N queens have been placed
	{
		return true;
	}
	for(int row=0;row<n;row++) //placing the queens column wise, 0,1,2.....
	{
		if (canPlace(board, row, col))
		{
			board[row][col] = 1; //if the square is available place 1 there
			if(place(board, col+1)) //Recursion
				return true;
			board[row][col] = 0; //Backtracking
		}
	}
	return false; //Cannot place all N queens
}

void print(int board[10][10], int n) //print the board
{
	for(int i=0; i< n ; i++)
	{
		for(int j=0; j < n; j++)
		{
			cout<<board[j][i]<<" "; //transposed just for the sake of correct output
		}
		cout<<endl;
	}
}

int main()
{
	cin>>n; //Board size NxN
	bool ans = place(board, 0);
	if (ans)
		print(board, n);
	else
	{
		cout<<"Not possible";
	}
}
