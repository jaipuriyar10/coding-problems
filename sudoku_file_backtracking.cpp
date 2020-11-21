#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mat[9][9];
bool valid(ll x, ll y, ll val)
{
    for (ll i = 0; i < 9; i++)
    {
        if (mat[i][y] == val)
            return false;
    }
    for (ll i = 0; i < 9; i++)
    {
        if (mat[x][i] == val)
            return false;
    }
    ll nx = (x / 3) * 3;
    ll ny = (y / 3) * 3;
    for (ll i = 0; i < 3; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            if (mat[i + nx][j + ny] == val)
                return false;
        }
    }
    return true;
}
void solve(ll x, ll y)
{
    if (x == 9)
    {
        for (ll i = 0; i < 9; i++)
        {
            for (ll j = 0; j < 9; j++)
                cout << mat[i][j] << " ";
            cout << "\n";
        }
        return ;
    }
    ll nx, ny;
    if (y == 8)
    {
        nx = x + 1;
        ny = 0;
    }
    else
    {
        nx = x;
        ny = y + 1;
    }
    if (mat[x][y] != 0)
    {
        solve(nx, ny);
    }
    else
    {
        for (ll i = 1; i <= 9; i++)
        {
            if (valid(x, y, i) == true)
            {
                mat[x][y] = i;
                solve(nx, ny);
                mat[x][y] = 0;
            }
        }
    }
}
int main()
{
// #ifdef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output_file.txt", "w", stdout);
// #endif
    for (ll i = 0; i < 9; i++)
        for (ll j = 0; j < 9; j++)
            cin >> mat[i][j];
    solve(0, 0);
    return 0;

}
