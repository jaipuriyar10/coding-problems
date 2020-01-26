int minSwaps(int A[], int N){
    /*Your code here */
    typedef long long ll;
    vector<pair<ll,ll>> vp;
    for(ll i=0;i<N;i++)
    {
        vp.push_back({A[i],i});
    }
    sort(vp.begin(),vp.end());
    ll cnt=0;
    for(ll i=0;i<N;i++)
    {
        if(i==vp[i].second)
        continue;
        else
        {
            swap(vp[i].first,vp[vp[i].second].first);
            swap(vp[i].second,vp[vp[i].second].second);
        }
        if(i!=vp[i].second)
        --i;
        cnt++;
    }
    return cnt;
}
