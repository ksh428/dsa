long maximumSum(vector<long> a, long m) {
    int n=a.size();
    ll ans=0;
    vector<ll>pref(n,0);

  // sort(a.begin(),a.end());
    pref[0]=a[0]%m;
    int i=0,j=0;
    for(int i=1;i<n;i++){
        pref[i]=(pref[i-1]+a[i])%m;
    }
    multiset<long>st;
    for(int i=0;i<n;i++){
        if(!st.empty()){
            auto it=st.upper_bound(pref[i]);
            if(it==st.end()) ans=max(ans,pref[i]);
            else ans=max(ans,(m+pref[i]-*it)%m);
        }
        st.insert(pref[i]);
    }
    ans=max(ans,pref[0]);
    return ans;

}
