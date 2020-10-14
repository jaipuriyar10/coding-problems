#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v1[100005];
bool vis[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m, x, y;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    memset(vis, false, sizeof(vis));
    map<int, int>ma;
    queue<int>q;
    q.push(1);
    //int y;
    vis[1] = true;
    while (!q.empty())
    {
        y = q.front();
        // cout << y << "\n";
        q.pop();
        if (y == n)
        {
            vector<int>v2;
            while (1)
            {
                v2.push_back(y);
                y = ma[y];
                if (y == 1)
                {
                    v2.push_back(1);
                    reverse(v2.begin(), v2.end());
                    cout << v2.size() << "\n";
                    for (int i : v2)
                        cout << i << " ";
                    return 0;
                }

            }
        }
        for (int i = 0; i < v1[y].size(); i++)
        {
            if (vis[v1[y][i]] == false)
            {
                ma[v1[y][i]] = y;
                q.push(v1[y][i]);
                vis[v1[y][i]] = true;
            }
        }

    }
    cout << "IMPOSSIBLE" << "\n";
    return 0;


}
