#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>v1[100005];
bool vis[100005];
unordered_map<ll, ll>ma;
bool dfs(ll node, ll par)
{
    ma[node] = par;
    vis[node] = true;
    for (ll child : v1[node])
    {
        if (vis[child] == false)
        {
            if (dfs(child, node) == true)
                return true;
        }
        else if (child != par)
        {
            ll sv = child;
            ll ev = node;
            vector<ll>v2;
            v2.push_back(sv);
            while (ev != sv)
            {
                v2.push_back(ev);
                ev = ma[ev];
            }
            v2.push_back(sv);
            cout << v2.size() << "\n";
            for (ll i : v2)
                cout << i << " ";
            return true;
        }
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll n, m, x, y;
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    for (ll i = 0; i < m; i++)
    {
        cin >> x >> y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
 
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            if (dfs(i, -1) == true)
            {
                return 0;
            }
        }
    }
 
    cout << "IMPOSSIBLE" << "\n";
    return 0;
}
