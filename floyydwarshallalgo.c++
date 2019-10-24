#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll dist[n][n];
        for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
        cin>>dist[i][j];
        for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );}}}
        for(ll i=0;i<n;i++)
        {for(ll j=0;j<n;j++)
        {	if(dist[i][j]!=1e7)
			cout<<dist[i][j]<<" ";
			else
			cout<<"INF"<<" ";}
        cout<<"\n";}
    }
    return 0;
        
    
}
