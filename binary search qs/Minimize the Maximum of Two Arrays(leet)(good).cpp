
class Solution {
public:
    #define ll long long
    bool ok(ll m,ll d1,ll d2,ll c1,ll c2){
        ll x=m-(m/d1);
        ll y=m-(m/d2);
        ll lcm=(d1*d2)/(__gcd(d1,d2));
        ll z=m-(m/lcm);
        if(x<c1 or y<c2 or z<c1+c2){
            return 0;
        }
        return 1;
    }
    int minimizeSet(int d1, int d2, int c1, int c2) {
        ll ans=-1;
        ll l=1,r=2000000000;
        while(l<=r){
            ll m=(l+(r-l)/2);
            if(ok(m,d1,d2,c1,c2)){//optimal ans will always be reached as range is always decreased
                //so this is a possible ans not necessarily the best and we will always reach better ans as r decreases so x,y,z decreases and reaches towards c1,c2 and c1+c2
                ans=m;
                r=m-1;
            }else l=m+1;
        }
        return ans;
    }
};
