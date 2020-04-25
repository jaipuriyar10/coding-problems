#include<bits/stdc++.h>
using namespace std;
int dp[1003][1003];
int solve(int arr[],int i,int j)
{
	if(i>=j)
	return 0;
	if(dp[i][j]!=-1)
	return dp[i][j];
	int temp;
	int res=INT_MAX;
	for(int k=i;k<j;k++)
	{
		temp=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
		res=min(res,temp);
	}
	dp[i][j]=res;
	return dp[i][j];
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	memset(dp,-1,sizeof(dp));
	int res=solve(arr,1,n-1);
	cout<<res<<"\n";
	return 0;
}
