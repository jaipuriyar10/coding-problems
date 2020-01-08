#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define n 8
bool issafe(ll x,ll y,ll sol[n][n])
{
	if(x>=0 and x<n and y>=0 and y<n and sol[x][y]==-1)
	return true;
	else
	return false;
}
ll solve(ll x,ll y,ll move,ll dx[],ll dy[],ll sol[n][n])
{
	if(move==n*n)
	return 1;
	ll nx,ny;
	for(ll i=0;i<8;i++)
	{
		
			nx=x+dx[i];
			ny=y+dy[i];
			if(issafe(nx,ny,sol))
			{
				sol[nx][ny]=move;
				if(solve(nx,ny,move+1,dx,dy,sol))
				return true;
				else
				sol[nx][ny]=-1;
			}
		
	}
	return 0;
}
int main()
{
	ll sol[n][n];
	memset(sol,-1,sizeof(sol));
	sol[0][0]=0;
	ll dx[]={  2, 1, -1, -2, -2, -1,  1,  2 };
	ll dy[]={  1, 2,  2,  1, -1, -2, -2, -1 };
	if(solve(0,0,1,dx,dy,sol)==0)
	cout<<"NO solution"<<"\n";
	else
	{
		for(ll i=0;i<n;i++)
		{for(ll j=0;j<n;j++)
		{cout<<sol[i][j]<<" ";}cout<<"\n";}
	}
	return 0;
}
	
