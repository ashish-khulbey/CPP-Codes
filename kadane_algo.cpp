//Kadane's Algorithm to find Maximum Subarray Sum

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n; //array length
	cin>>n;
	int a[100]; //array
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; 
	}
	int cs=0,ms=0; //cs->current sum, ms->maximum sum
	for(int i=0;i<n;i++) //O(N)
	{
		cs=cs+a[i];
		if (cs<0) //If negative current sum, make it 0
		{
			cs=0;
		}
		ms=max(ms,cs);
	}
	cout<<ms<<endl; //max sub array sum
	return 0;
}
