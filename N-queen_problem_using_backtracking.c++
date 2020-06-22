PROBLEM:https://practice.geeksforgeeks.org/problems/n-queen-problem/0


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool flag;
bool issafe(ll r, ll c, ll n, vector<vector<ll>>&v1)
{
    for (ll i = 0; i < r; i++)
    {
        if (v1[i][c])
            return false;
    }
    for (ll i = r, j = c; i >= 0 and j >= 0 ; i--, j--)
    {
        if (v1[i][j])
            return false;
    }
    for (ll i = r, j = c; i >= 0 and j < n ; i--, j++)
    {
        if (v1[i][j])
            return false;
    }
    return true;
}
void queen(vector<vector<ll>>&v1, ll r, ll n)
{
    if (r == n)
    {
        flag = true;
        cout << "[";
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if (v1[i][j])
                    cout << (j + 1);
            }
        }
        cout << "]";
        return ;
    }
    for (ll i = 0; i < n; i++)
    {
        if (issafe(r, i, n, v1))
        {
            v1[r][i] = 1;
            queen(v1, r + 1, n);
            v1[r][i] = 0;
        }
    }

}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output3.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>>v1(n, vector<ll>(n, 0));
        flag = false;
        queen(v1, 0, n);
        if (flag == false)
            cout << -1 << "\n";
        else
            cout << "\n";
    }
    return 0;
}
