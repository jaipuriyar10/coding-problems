#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll par[100005];//parent array which will store the index parent of each index.
#define mod 1000000007//mod value as (10^9+7) to prevent integer overflow.

//find function will find the parent for each element.
//iterative find function.
/*ll find(ll x)
{

	//since we are storing -ve value 
	//for parent and its child have positive value in the par[] array,so until we find -ve value only then we break loop.
	while(par[x]>0)
	x=par[x];
	
	//return parent for x.
	return x;
}
//recursive find function.
ll find(ll x)
{
	//if par[x]<0 then it means that it is a parent.
	if(par[x]<0)
	return x;
	else //call recursive function find to obtain the parent.
	return find(par[x]);
}
*/

//path compression find function.
ll find(ll x)
{
		//check if parent of x if -ve it means 
		//it is itself a parent.
		if(par[x]<0)
		return x;
		else
		return par[x]=find(par[x]);//find parent of x and store it and then return the parent.
}

//union1 function is use to make connection
// between the parent of two different elements.

void union1(ll x,ll y)
{
	//find parent of each element.
	x=find(x);
	y=find(y);
	//if both have of them have some parent 
	//then we dont need to make any connection.
	if(x==y)
	return ;
	else// if their parent is not same then make parent x for y.
	{
		par[x]+=par[y];//increment the number of connection of parent x.
		par[y]=x;	//make parent of y as x.
	}
}
int main()
{
	//take inputs.
	cout<<"Enter N and M: ";
	ll n,m,x,y;
	cin>>n>>m;
	//make parent of each child as -1 initially.
	for(ll i=1;i<=n;i++)
	par[i]=-1;
	
	
	cout<<"Enter pairs:\n";
	//take input of connection between them. 
	for(ll i=1;i<=m;i++)
	{
		cin>>x>>y;
		union1(x,y);//make connection between two child.
	}
	ll ans=1;//initialise ans varible as 1.
	cout<<"Number of ways we can select leaders: " ;
	for(int i=1;i<=n;i++)
	if(par[i]<0)//check if that is a group.
	ans=(ans*abs(par[i]))%mod;
	cout<<ans<<"\n";
	return 0;
}
