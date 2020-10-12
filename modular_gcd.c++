#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define md 1000000007
ll power(ll n, ll m, ll mod)
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
    return x % mod;

}
ll solve(ll a, ll b, ll n)
{
    if (a == b)
    {
        return (power(a, n, md) + power(b, n, md)) % md;
    }
    ll diff = abs(a - b);
    ll ans = 1;
    for (ll i = 1; i * i <= diff; i++)
    {
        if (diff % i == 0)
        {
            ll sum = (power(a, n, i) + power(b, n, i)) % i;
            if (sum == 0)
                ans = max(ans, i);
            if (diff % (diff / i) == 0)
            {
                sum = (power(a, n, diff / i) + power(b, n, diff / i)) % (diff / i);
                if (sum == 0)
                    ans = max(ans, diff / i);
            }
        }
    }
    return ans % md;


}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << "\n";
    }
    return 0;
}
