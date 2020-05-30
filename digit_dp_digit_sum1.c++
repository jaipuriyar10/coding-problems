#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//declare dp states.
ll dp[11][100];
//declare solve function.
ll solve(ll pos,ll n,ll val)
{
	//if pos > digit size then return sum.
	if(pos>n)
	return val;
	
	//check if dp state is already calculated.
	if(dp[pos][val]!=-1)
	return dp[pos][val];
	else
	{
		//temporary variable res as 0.
		ll res=0;
		
		//iterate through the loop.
		for(ll i=0;i<=9;i++)
		{
			//call solve function recursively.
			res+=solve(pos+1,n,val+i);
		}
		//store and return res value.
		return dp[pos][val]=res;
	}
}

int main()
{
	ll t;
	cout<<"Enter number of test cases: ";
	cin>>t;
	while(t--)
	{
		cout<<"Enter digit size: ";
		ll n;
		cin>>n;
		//fill all dp elements with -1.
		memset(dp,-1,sizeof(dp));
		
		//call solve function with initial sum as 0.
		ll res=solve(1,n,0);
		cout<<"Final sum: ";
		cout<<res<<"\n";
	}
	return 0;
}
