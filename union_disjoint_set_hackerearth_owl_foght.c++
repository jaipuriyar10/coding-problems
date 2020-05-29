#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//for storing large values.
ll par[100005];	//parent array which will store strength initially.

//path compression find function.
ll find(ll x)
{
	//check if parent of x if -ve it means 
	//it is itself a parent.
    if(par[x]<0)
    return x;
    else
    return par[x]=find(par[x]);//find parent of x and store it 
							   //and then return the parent.
}



//union funtion to make connection between fighter.
void union1(ll x,ll y)
{
    x=find(x);//find parent of x.
    y=find(y);//find parent of y.
    
     //if both have same parent then 
     //their strength are equal.
    if(x==y)
    return ;
    else
    {
		//assign min of strength of x and y to parent.
        par[x]=min(par[x],par[y]);
        par[y]=x;//make parent of y as x.

    }
}

//main function explaination.
int main()
{
	//take input of number of fighter
	// and number of connection.
	cout<<"N and M: ";
    
    
    ll n,m;
    cin>>n>>m;
    
    
    //make each fighter strength as -ve(index)
    // because of the logic explained earlier.
    for(ll i=1;i<=n;i++)
    par[i]=-i;
    
     //form connection.
    cout<<"Enter connections:\n";
    while(m--)
    {
        ll x,y;
        cin>>x>>y;
        union1(x,y);
    }
    
    cout<<"Enter number of Queries:\n";
    
    //take number of queries.
    ll q;
    cin>>q;
    while(q--)
    {
		//take two fighter as input.
        ll x,y;
        cin>>x>>y;
        ll px=find(x);//find parent of fighter x.
        ll py=find(y);//find parent of fighter y.
        
        //if both have same parent then they 
        //have same strength so TIE.
        cout<<"Final result: ";
        if(px==py)
        cout<<"TIE"<<"\n";
        else if(abs(par[px])>abs(par[py]))//-ve value of parent of x is greater than the -ve 
		cout<<x<<"\n";       			   //value of strengh of parent of y then x wins. 
        else//vice versa of above case.
        cout<<y<<"\n";
    }
    return 0;
}
