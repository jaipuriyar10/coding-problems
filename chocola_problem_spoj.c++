

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/* SPOJ: CHOCOLA
Idea: Greedy Algorithm Stays Ahead
The number of breaks needed is always the same.
#Proof:
C(n,m) = n + m + n*m
C(0,0) = 0 (a single box choclate needs 0 cut)
Cut horizontally:
C(n,m) = 1 + C(a,m) + C(b,m) such that a+b+1 = n
C(n,m) = 1 + a+m+a*m + b+m+b*m
       = 1 + (n-1) + 2*m + (n-1)*m
       = n + m + n*m   :)
equally for vertical cut
#
Observation: the problem is similar to weight distribution problem
Observation: each cut will happen sooner or later
Observation: the "weight" of a cut is non decreasing
Observation: if a vertical and horizontal cost are equal, cutting 
order does not matter. Proof?
So we greedily choose the largest cut-cost each time
*/

int x[1003], y[1003];

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int m,n;
        cin >> m >> n;
        for(int i=1;i<m;++i){
            cin >> x[i];
        }
        for(int i=1;i<n;++i){
            cin >> y[i];
        }
        int h = 1,v=1;
        sort(x+1,x+m);
        reverse(x+1,x+m);
        sort(y+1,y+n);
        reverse(y+1,y+n);
        int i=1,j=1;
        int ans = 0;
        while(i<m && j<n){
            if(x[i] > y[j]){
                ans += x[i]*v;
                ++h;
                ++i;
            } else {
                ans += y[j]*h;
                ++v;
                ++j;
            }
        }
        if(i<m){
            int sum = 0;
            while(i<m){
                sum += x[i];
                ++i;
            }
            ans += sum*v;
        } else {
            int sum = 0;
            while(j<n){
                sum += y[j];
                ++j;
            }
            ans += sum*h;
        }
        cout << ans << endl;
    }
    return 0;
}

