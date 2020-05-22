#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>v1[100005];
bool vis[100005];
ll dist[100005];
bool isprime(ll x)
{
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0)
		return false;
	}
	return true;
}
bool isvalid(ll a,ll b)
{
	ll cnt=0;
	while(a>0)
	{
		if(a%10!=b%10)cnt++;
		a/=10;
		b/=10;
	}
	if(cnt==1)
	return true;
	else
	return false;
}
vector<ll>primes;
void graph()
{
	for(ll i=1000;i<=9999;i++)
	{
		if(isprime(i))
		primes.push_back(i);
	}
	for(ll i=0;i<primes.size();i++)
	{
		for(ll j=i+1;j<primes.size();j++)
		{
			ll a=primes[i];
			ll b=primes[j];
			if(isvalid(a,b))
			{
				v1[a].push_back(b);
				v1[b].push_back(a);
			}
		}
	}	
}
void bfs(ll x)
{
	vis[x]=true;
	dist[x]=0;
	queue<ll>q;
	q.push(x);
	while(!q.empty())
	{
		ll y=q.front();
		q.pop();
		for(ll i=0;i<v1[y].size();i++)
		{
			if(vis[v1[y][i]]==false)
			{
				q.push(v1[y][i]);
				dist[v1[y][i]]=dist[y]+1;
				vis[v1[y][i]]=true;
			}
		}
	}
}	
int main()
{
	ll t;
	cin>>t;
	graph();
	while(t--)
	{
		
		ll n,m;
		cin>>n>>m;
		for(ll i=1000;i<=9999;i++)
		dist[i]=-1,vis[i]=false;
		bfs(n);
		if(dist[m]!=-1)
		cout<<dist[m]<<"\n";
		else
		cout<<"Impossible"<<"\n";		
	
	}
	return 0;
}
		
				
	
