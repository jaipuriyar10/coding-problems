#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output_file.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int mat[n][m];
    queue<pair<int, int>>qp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 2)
            {
                qp.push({i, j});
            }
        }
    if (qp.size())
        qp.push({ -1, -1});

    int cnt = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!qp.empty())
    {
        cout << qp.size() << "\n";
        while (qp.front() != make_pair(-1, -1))
        {
            pair<int, int>p = qp.front();
            qp.pop();
            if (mat[p.first][p.second] == 2)
                for (int i = 0; i < 4; i++)
                {
                    int u = p.first + dx[i];
                    int v = p.second + dy[i];
                    if (u >= 0 and u<n and v >= 0 and v < m)
                    {
                        if (mat[u][v] == 1)
                        {
                            mat[u][v] = 2;
                            qp.push({u, v});
                        }
                    }
                }

        }
        if (qp.front() == make_pair(-1, -1))
        {
            qp.pop();
            if (qp.size() != 0)
            {   cnt++;
                qp.push({ -1, -1});
            }
            else
            {
                break;
            }

        }
    }
    cout << cnt << "\n";
    return 0;
}
