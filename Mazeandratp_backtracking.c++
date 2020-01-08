#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define n 4
bool issafe(ll maze[n][n],ll x,ll y)
{
	if(x>=0 and x<n and y>=0 and y<n and maze[x][y]==1)
	return true;
	else
	return false;
}
bool solve(ll x,ll y,ll maze[n][n],ll sol[n][n])
{
	if(x==n-1 and y==n-1)
	{sol[x][y]=1;return true;}
	if(issafe(maze,x,y))
	{
		sol[x][y]=1;
		if(solve(x+1,y,maze,sol)==true)
		return true;
		if(solve(x,y+1,maze,sol)==true)
		return true;
		sol[x][y]=0;
	} 
	return false;
}

int main()
{
	//cin>>n;
	ll maze[n][n];
	for(ll i=0;i<n;i++)
	for(ll j=0;j<n;j++)
	cin>>maze[i][j];
	ll sol[n][n];
	memset(sol,0,sizeof(sol));
	if(solve(0,0,maze,sol)==false)
	cout<<"NO SOLUTION"<<"\n";
	else
	{
	for(ll i=0;i<n;i++)
	{for(ll j=0;j<n;j++)
	{cout<<sol[i][j]<<" ";}cout<<"\n";}
	}
	return 0;
	
}
