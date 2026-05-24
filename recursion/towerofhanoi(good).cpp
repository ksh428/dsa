

class Solution{
public:
    vector<pair<int,int>>store;
    void toh(int n,int s,int d,int h){
        if(n==0) return ;
        toh(n-1,s,h,d);
        store.push_back({s,d});
        toh(n-1,h,d,s);

    }
    vector<int> shiftPile(int N, int n){
        toh(N,1,3,2);// transfer n plates from 1 to 3 using box 2 following the rules
        int a,b;
        a=store[n-1].first;
        b=store[n-1].second;
        return {a,b};
    }
};
