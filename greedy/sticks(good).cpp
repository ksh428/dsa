
//https://practice.geeksforgeeks.org/contest/microsoft-online-coding-assesment-4/problems#
class Solution{
public:
    #define ll long long
    long long minimumCost(int n,vector<int> l,vector<int> c){
        ll ans=1e18;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({l[i],c[i]});
        }
        //u can sort in any order
        sort(v.begin(),v.end());//sort acc to length so that we only need to care about
        //either inc or dec
        vector<ll>front(n);//convert all stciks from 0 to i-1 to ith length
        front[0]=0;
        ll costupto=0;
        ll cost=v[0].second;
        for(int i=1;i<n;i++){
            costupto+=(v[i].first-v[i-1].first)*cost;
            front[i]=costupto;
            cost+=v[i].second;
        }
        vector<ll>back(n);//convert all sticks from i+1 to n-1 to ith length
        back[n-1]=0;
        costupto=0;
        cost=v[n-1].second;
        for(int i=n-2;i>=0;i--){
            costupto+=(v[i+1].first-v[i].first)*cost;
            back[i]=costupto;
            cost+=v[i].second;
        }
        for(int i=0;i<n;i++){
           if(ans>front[i]+back[i]) ans=front[i]+back[i];
        }

        return ans;
    }
};

