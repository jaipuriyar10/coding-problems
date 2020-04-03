problem:-https://practice.geeksforgeeks.org/contest-problem/sub-array-of-given-sum-in-2-d-array/1


typedef long long ll;
bool check(ll temp[],ll n,ll x)
{
    ll l=0,r=-1;
    ll sum=0;
    while(r<n)
    {
        if(sum<x)
        {
            r++;
            sum+=temp[r];
        }
        else if(sum>x)
        {
            sum-=temp[l];
            l++;
        }
       else
       return true;
    }
    return false;
}

bool is_rectangle_there(int arr[N][N], int n, int x)
{
    // code here
    for(ll i=0;i<n;i++)
    {
        ll temp[n];
        memset(temp,0,sizeof temp);
        for(ll j=i;j<n;j++)
        {
            
            for(ll k=0;k<n;k++)
            temp[k]+=arr[j][k];
            if(check(temp,n,x))
            return true;
        }
    }
    return false;

    
    
}
