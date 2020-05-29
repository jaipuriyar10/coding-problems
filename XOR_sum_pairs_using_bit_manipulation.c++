#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll arr[],ll n)
{
	//declare res variable as 0 initially.
	ll res=0;
	//iterate through the size of int(32 bit)
	for(ll i=0;i<=31;i++)
	{
		//declare two variable count 0 and count 1.
		ll cnt1=0;
		ll cnt0=0;
		
		//iterate through each element and count 
		//set bits and non set bits.
		for(ll j=0;j<n;j++)
		{
			//if bit is set in increment cnt1
			if(arr[j]&(1<<i))
			cnt1++;
			else//increment count if bit is not set.
			cnt0++;
		}
		
		//number of bits which contribute in total sum.
		ll p=cnt1*cnt0;
		//adding the values.
		res+=(1<<i)*p;
	}
	return res;
}
		
int main()
{
	cout<<"Enter number of test cases: ";
	ll t;
	cin>>t;
	while(t--)
	{
		cout<<"Enter size of array: ";
		ll n;
		cin>>n;
		ll arr[n];
		cout<<"Enter elements: ";
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<"Final XOR pair sum: ";
		cout<<solve(arr,n)<<"\n";
	}
	return 0;
}
				
