#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> v1,v2,sv1,sv2;

vector<ll> subsets(vector<ll> v)
{
	vector<ll> ans;
	int n = v.size();
	for(int i=0; i<(1<<n); i++) //while i<(2^n), left shift
	{
		ll sum = 0; //holds subset sum
		ll index = 0; //index for v
		for(int j=i; j>0; j=j>>1) //to sum all bits(vector-v ka index) of i
		{
			if(j&1) //if LSB is 1, add that v[index]
			{	
				sum+=v[index];
			}
			++index; //index of v
		}
		ans.push_back(sum);
	}
	return ans;
}

int main()
{
	ll n, a, b;
	cin>>n>>a>>b; //take inputs
	ll temp;
	int n1 = n/2; //divide the vectors
	int n2 = n-n1;
	for(int i=0; i<n1; i++) //input half elements
	{
		cin>>temp;
		v1.push_back(temp);
	}
	for(int i=0; i<n2; i++) //input rest half elements
	{
		cin>>temp;
		v2.push_back(temp);
	}
	sv1 = subsets(v1); //sum of subset vector v1
	sv2 = subsets(v2); //sum of subset vector v2

	sort(sv2.begin(), sv2.end()); //sort sv2
	ll u,l,ans,li,ui;
	for(int i=0;i<sv1.size();i++) //binary search on sv2 for every sv1 element
	{
		l = a-sv1[i]; //lower bound for sv2
		u = b-sv1[i]; //upper bound for sv2

		auto it1 = lower_bound(sv2.begin(), sv2.end(), l); //lower bound iterator
		auto it2 = upper_bound(sv2.begin(), sv2.end(), u); //upper bound iterator--value greater than actual bound
		//so don't include this value, i.e. take 1 less

		li = it1 - sv2.begin(); //lower bound index
		ui = it2 - sv2.begin(); //upper bound index

		ans+=(ui-li);
	}
	cout<<ans<<endl;
}