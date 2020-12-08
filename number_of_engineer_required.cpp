#include<bits/stdc++.h>
using namespace std;
vector<int>sol;
void solve(int arr[],int n,int cp,vector<int>&v1,int skill)
{
    if(cp==n)
    {
        if(skill==((1<<n)-1))
        {
            if(sol.size()==0||sol.size()>v1.size())
            {
                sol=v1;
            }
            
        }
        return ;
    }
    solve(arr,n,cp+1,v1,skill);
    v1.push_back(cp);
    solve(arr,n,cp+1,v1,skill|(arr[cp]));
    v1.pop_back();
    
}
int main()
{
    int n;
    cin>>n;
    map<string,int>ma;
    string str;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        ma[str]=i;
    }
    int t;
    cin>>t;
    int arr[t];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<t;i++)
    {
        int z;
        cin>>z;
        for(int j=0;j<z;j++)
        {
            cin>>str;
            arr[i]=arr[i]|(1<<ma[str]);
        }
    }
    vector<int>v1;
    solve(arr,n,0,v1,0);
    for(int i=0;i<sol.size();i++)
    {if(i==0)
    {
        cout<<"["<<sol[i]<<", ";
    }
    if(i!=0 and i!=(sol.size()-1))
    {
         cout<<sol[i]<<", ";
    }
    if(i==sol.size()-1)
    {
        cout<<sol[i]<<"]";

    }
    }
    return 0;
}
