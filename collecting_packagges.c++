    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    int main()
    {
    	ll t;
    	cin>>t;
    	while(t--)
    	{
    		ll p;
    		cin>>p;
    		vector<pair<ll,ll>> vp;
    		for(ll i=0;i<p;i++)
    		{
    			ll x,y;
    			cin>>x>>y;
    			vp.push_back({x,y});
    		}
    		sort(vp.begin(),vp.end());
    		string str="";
    		ll a,b;
    		a=0;
    		b=0;
    		for(auto it=vp.begin();it!=vp.end();it++)
    		{
    			ll diff1=it->first-a;
    			ll diff2=it->second-b;
    			if(diff1<0 or diff2<0)
    			{cout<<"NO"<<"\n";goto end;}
    			for(ll i=0;i<diff1;i++)
    			str+="R";
    			for(ll j=0;j<diff2;j++)
    			str+="U";
    			a=it->first;
    			b=it->second;
    		}
    		cout<<"YES"<<"\n";
    		cout<<str<<"\n";
    		end:
    		continue;
    	}
    	return 0;
    }
