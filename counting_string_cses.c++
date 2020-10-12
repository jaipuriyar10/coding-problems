#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define md 1000000007

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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    static ll dp[1000001];
    dp[0] = 1;
    dp[1] = 1;
    for (ll i = 2; i < 1000001; i++)
    {
        dp[i] = ((i % md) * (dp[i - 1] % md)) % md;
    }
    unordered_map<ll, ll>ma;
    string str;
    cin >> str;
    for (ll i = 0; i < str.length(); i++)
    {
        ma[str[i]]++;
    }
    ll ans = dp[str.length()];
    //cout << ans << "\n";
    for (auto it = ma.begin(); it != ma.end(); it++)
    {
        //cout << it->first << " " << it->second << "\n";
        if (it->second != 1)
            ans = (ans % md * solve(dp[it->second], md - 2, md) % md) % md;
        //cout << ans << "\n";
    }

    cout << ans << "\n";
    return 0;
}
