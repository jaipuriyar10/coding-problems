#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
vector<ll>v1[100005];
bool vis[100005];

ll col[100005];
bool dfs(ll x, ll par)
{
    vis[x] = true;
    // col[x] = c;
    for (ll child : v1[x])
    {
        if (vis[child] == false)
        {
            if (dfs(child, x) == false)
                return false;

        }
        else if (child != par)
            return false;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output12.txt", "w", stdout);
#endif
    ll n, m, x, y;
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    for (ll i = 1; i <= m; i++)
    {
        cin >> x >> y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    if (dfs(1, 1))
        cout << "NO" << "\n";
    else
        cout << "YES" << "\n";
    return 0;
}
