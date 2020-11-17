#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(vector<vector<bool>>&v1, ll r, ll n, vector<bool> &col, vector<bool> &ndiag, vector<bool> &rdiag, string str)
{
    if (r == n)
    {
        cout << str;
        cout << ".";
        cout << "\n";
        return ;
    }
    for (ll i = 0; i < n; i++)
    {
        if (col[i] == false and ndiag[r + i] == false and rdiag[r - i + (n - 1)] == false)
        {
            col[i] = true;
            ndiag[r + i] = true;
            rdiag[r - i + (n - 1)] = true;
            solve(v1, r + 1, n, col, ndiag, rdiag, str + to_string(r) + "-" + to_string(i) + ", ");
            col[i] = false;
            ndiag[r + i] = false;
            rdiag[r - i + (n - 1)] = false;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    vector<vector<bool>>v1(n, vector<bool>(n, false));
    vector<bool>col(n, false);
    vector<bool>ndiag(n, false);
    vector<bool>rdiag(n, false);
    solve(v1, 0, n, col, ndiag, rdiag, "");
    return 0;

}
