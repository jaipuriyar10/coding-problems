#include<bits/stdc++.h>
using namespace std;
#define md 1009
typedef unsigned long long ll;
ll dp[1015];
ll dp2[1015];


ll solve(ll n, ll m, ll mod)
{
    ll x = 1;
    ll y = n;
    while (m > 0)
    {
        if (m % 2)
        {
            x = (x % mod * y % mod) % mod;
        }
        y = (y % mod * y % mod) % mod;
        m /= 2;
    }
    return (x % mod);
}
ll solve3(ll n, ll m)
{
    if (m > n)
        return 0;
    else
    {
        return ((dp[n] * dp2[m]) % md * dp2[n - m] % md) % md;
    }
}

ll solve2(ll n, ll m)
{
    if (m > n)
        return 0;
    else if (n == 0)
        return 1;
    else
    {   //  cout << n << " " << m << "\n";
        //     cout << n % md << " " << m % md << "\n";
        return (solve3(n % md, m % md) % md * solve2(n / md, m / md) % md) % md;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    dp[0] = 1;
    dp[1] = 1;
    for (ll i = 2; i < 1015; i++)
    {
        dp[i] = (dp[i - 1] % md * i % md) % md;
    }

    for (int i = 0; i < 1015; i++)
    {
        dp2[i] = solve(dp[i], md - 2, md);
    }
    // cout << dp2[0] << "\n";
    ll q;
    cin >> q;
    while (q--)
    {
        ll n, m;
        cin >> n >> m;
        //cout << dp[n] << " " << dp[m] << "\n";
        //cout << n << " " << m << "\n";
        cout << solve2(n , m) << "\n";
        //cout << solve2(n, m) << "\n";
    }
    return 0;

}
