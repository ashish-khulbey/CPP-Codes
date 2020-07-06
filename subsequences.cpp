#include <iostream>

using namespace std;

void subsequence(char in[], char out[], int i, int j)
{
	if (in[i]=='\0') //Base Case
	{
		out[j]='\0';
		cout<<out<<", ";
		return;
	}
	//Including in[i]
	out[j]=in[i];
	subsequence(in, out, i+1, j+1); 
	//Excluding in[i]
	out[j]='\0';
	subsequence(in, out, i+1, j);
}

int main()
{
	char in[100]="abc"; //Input
	char out[100]; //Output string
	subsequence(in, out, 0, 0);
}
