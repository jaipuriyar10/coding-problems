#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>v1[100005];
bool vis[100005];
ll maxx;
ll maxnode;
void dfs(ll node, ll dist)
{
	vis[node] = true;
	if (maxx < dist)
	{
		maxx = dist;
		maxnode = node;
	}
	for (ll i : v1[node])
	{
		if (vis[i] == false)
			dfs(i, dist + 1);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n, x, y;
	cin >> n ;
	memset(vis, false, sizeof(vis));
	for (ll i = 1; i <= n - 1; i++)
	{
		cin >> x >> y;
		v1[x].push_back(y);
		v1[y].push_back(x);
	}
	dfs(1, 0);
	memset(vis, false, sizeof(vis));
	maxx = 0;
	dfs(maxnode, 0);
	cout << maxx << "\n";
	return 0;

}
