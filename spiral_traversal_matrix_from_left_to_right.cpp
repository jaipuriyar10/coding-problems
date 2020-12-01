#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inuput.txt", "r", stdin);
    freopen("outputt_file.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int mat[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    int minr = 0;
    int maxr = n - 1;
    int minc = 0;
    int maxc = m - 1;
    int cnt = 0;
    int t = (n * m);
    while (cnt <= t)
    {
        // cout << "YES" << "\n";
        for (int i = minr, j = minc; j <= maxc and cnt < t; j++)
        {
            cout << mat[i][j] << " ";
            cnt++;
        }
        minr++;
        for (int i = minr, j = maxc; i <= maxr and cnt < t; i++)
        {
            cout << mat[i][j] << " ";
            cnt++;
        }
        maxc--;
        for (int j = maxc, i = maxr; j >= minc and cnt < t; j--)
        {
            cout << mat[i][j] << " ";
            cnt++;
        }
        maxr--;
        for (int i = maxr, j = minc; i >= minr and cnt < t; i--)
        {
            cout << mat[i][j] << " ";
            cnt++;
        }
        cout << "\n";
        minc++;
    }

    return 0;
}
