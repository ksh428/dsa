#define ll long long
long long getSubstringWithEqual012(string s)
{
    ll ans=0;
    int n=s.size();
    ll c0=0,c1=0,c2=0;
    unordered_map<string,ll>m;
    ll d10=c1-c0;
    ll d21=c2-c1;
    string key=to_string(d10)+"#"+to_string(d21);
    m[key]=1;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            c0++;
        }else if(s[i]=='1'){
            c1++;
        }else{
            c2++;
        }
        d10=c1-c0;
        d21=c2-c1;
        string key=to_string(d10)+"#"+to_string(d21);
        if(m.find(key)!=m.end()){
            ans+=m[key];
            m[key]++;
        }else{
            m[key]++;
        }
    }
    return ans;
}
