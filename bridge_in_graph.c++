#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>v1[1000];
bool vis[1000];
ll in[1000];
ll low[1000];
vector<pair<ll, ll>>vp;
ll timer;
void dfs(ll node, ll par)
{
	vis[node] = true;
	in[node] = low[node] = timer++;
	for (ll i : v1[node])
	{
		if (i == par)
			continue;
		if (vis[i] == true)
		{
			low[node] = min(low[node], in[i]);
		}
		else
		{
			dfs(i, node);
			if (low[i] > in[node])
			{
				if (i > node)
				{vp.push_back({node, i});} //cout << node << " " << i << "\n";
				else
				{vp.push_back({i, node});} //cout << i << " " << node << "\n";
			}
			low[node] = min(low[node], low[i]);
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t;
	cin >> t;
	ll cnt = 1;
	while (t--)
	{
		ll n, m, x, y;
		cin >> n >> m;
		memset(vis, false, sizeof(vis));
		for (ll i = 1; i <= m; i++)
		{
			cin >> x >> y;
			v1[x].push_back(y);
			v1[y].push_back(x);
		}
		timer = 0;
		memset(in, 0, sizeof(in));
		memset(low, 0, sizeof(low));
		dfs(1, -1);
		for (ll i = 0; i < 1000; i++)
			v1[i].clear();
		cout << "Caso #" << (cnt++) << "\n";
		if (vp.size() == 0)
			cout << "Sin bloqueos" << "\n";
		else
		{
			cout << vp.size() << "\n";
			sort(vp.begin(), vp.end());
			for (auto it = vp.begin(); it != vp.end(); it++)
			{
				cout << it->first << " " << it->second << "\n";
			}
		}
		vp.clear();

	}
	return 0;
}
