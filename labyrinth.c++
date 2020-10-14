#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};
// #define ff first
// #define ss second
bool valid(ll x, ll y, ll n, ll m)
{
    if (x >= 0 and x<n and y >= 0 and y < m)
        return true;
    else
        return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    char x;
    int mat[n][m];
    bool vis[n][m];
    memset(vis, false, sizeof(vis));
    pair<int, int>p1, p2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            if (x == 'A')
                p1 = {i, j};
            if (x == '#')
                mat[i][j] = 0;
            else
                mat[i][j] = 1;
            if (x == 'B')
                p2 = {i, j};
        }
    queue<pair<int, int>>q;
    map<pair<int, int>, pair<pair<int, int>, char> > ma;
    q.push(p1);
    pair<int, int>p3;
    vis[p1.first][p1.second] = true;
    while (!q.empty())
    {
        p3 = q.front();
        q.pop();
 
        int u = p3.first;
        int v = p3.second;
 
 
        for (int i = 0; i < 4; i++)
        {
            int a = u + dx[i];
            int b = v + dy[i];
            if (valid(a, b, n, m))
            {
                if (vis[a][b] == false and mat[a][b] == 1 || make_pair(a, b) == p2)
                {
                    char c;
                    if (dx[i] == 1 and dy[i] == 0)
                        c = 'D';
                    if (dx[i] == 0 and dy[i] == 1)
                        c = 'R';
                    if (dx[i] == 0 and dy[i] == -1)
                        c = 'L';
                    if (dx[i] == -1 and dy[i] == 0)
                        c = 'U';
                    ma[ {a, b}] = {{u, v}, c};
                    if (make_pair(a, b) == p2)
                    {
                        auto end = make_pair(a, b);
                        string res = "";
                        while (1)
                        {
                            res += ma[end].second;
                            end = ma[end].first;
                            if (end.first == p1.first and end.second == p1.second)
                                break;
                        }
                        reverse(res.begin(), res.end());
                        cout << "YES" << "\n";
                        cout << res.length() << "\n";
                        cout << res << "\n";
                        return 0;
                    }
                    vis[a][b] = true;
                    q.push({a, b});
 
                }
            }
        }
 
    }
    cout << "NO" << "\n";
 
    return 0;
}
