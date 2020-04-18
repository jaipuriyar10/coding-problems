#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n;
  cin>>n;
  ll a,b,c;
  cin>>a>>b>>c;
  for(ll i=1;i<n;i++)
  {
    ll e,f,g;
    cin>>e>>f>>g;
    ll x,y,z;
    x=a;
    y=b;
    z=c;
    a=e+max(y,z);
    b=f+max(x,z);
    c=g+max(x,y);
  }
  cout<<max(max(a,b),c);
  return 0;
  
  
  
}
