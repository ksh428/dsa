//https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-for-amazon-alexa/problems/#
class Solution {
public:
#define ll long long
    long long colosseum(int n,vector<int> a) {
        ll s1=0,s2=0;
        ll ans=LONG_MIN;
        vector<ll>l(3*n+1,LONG_MIN);//largest sum of n numbers endig here
        vector<ll>r(3*n+1,LONG_MAX);//smallest sum of n numbers starting from here to end
        ll s=0;
        priority_queue<int>maxheap;
        priority_queue<int,vector<int>,greater<int>>minheap;

        for(int i=0;i<3*n;i++){//calculate fully u did just upto i<2n else we will bet wa
            s+=a[i];
            minheap.push(a[i]);
            if(minheap.size()>n){
                ll v=minheap.top();
                s-=v;
                minheap.pop();
            }
            if(minheap.size()==n) l[i]=s;
        }
        s=0;
        for(int i=3*n-1;i>=0;i--){//calculate fully u did just upto i>=2n else we will bet wa
            s+=a[i];
            maxheap.push(a[i]);
            if(maxheap.size()>n){
                ll v=maxheap.top();
                s-=v;
                maxheap.pop();
            }
            if(maxheap.size()==n) r[i]=s;
        }
        for(int i=n-1;i<2*n;i++){
            ans=max(ans,l[i]-r[i+1]);
        }
        return ans;
   }
};
