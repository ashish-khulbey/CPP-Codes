#include <iostream>

using namespace std;

int n, board[10][10]={0}; //globals

bool isvalid(int r, int c)
{
	if(r>=0 && r<n && c>=0 && c<n)
		return true;
	return false;
}

void print(int board[10][10], int n)
{
	for(int i=0; i< n ; i++)
	{
		for(int j=0; j < n; j++)
		{
			cout<<board[j][i]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool canPlace(int board[10][10], int row, int col)
{
	for(int i=0;i<col;i++) //checking for attacing queen in that row
	{
		if(board[row][i]==1)
			return false;
	}
	for(int i=row,j=col;i>=0 && j>=0;i--,j--)
	{
		if(board[i][j]==1)
			return false;
	}
	for(int i=row,j=col;i<n && j>=0;i++,j--)
	{
		if(board[i][j]==1)
			return false;
	}
	return true;	
}

bool place(int board[10][10], int col)
{
	if (col>=n)
	{
		print(board, n); //print when all N queens placed
		return true;
	}
	for(int row=0;row<n;row++)
	{
		if (canPlace(board, row, col))
		{
			board[row][col] = 1;
			bool ans = place(board, col+1); //Recursion
			//if(place(board, col+1))
				//return true; //Now not returning true, so it checks all solutions possible
			board[row][col] = 0; //Backtracking
		}
	}
	return false;
}

int main()
{
	cin>>n;
	bool ans = place(board, 0);
	// if (ans) //No need to print here as we print in the recursion function itself
	// // 	print(board, n);
	// else
	// {
	// 	cout<<"Not possible";
	// }
}
