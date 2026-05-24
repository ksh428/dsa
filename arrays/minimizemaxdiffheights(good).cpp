class Solution {
  public:
    int getMinDiff(int a[], int n, int k) {
        sort(a,a+n);
        int minv,maxv;
        int ans=a[n-1]-a[0];
        for(int i=1;i<n;i++){
            //select all possible x,y pairs
            if(a[i]>=k){
                maxv=max(a[i-1]+k,a[n-1]-k);
                minv=min(a[i]-k,a[0]+k);
                ans=min(ans,maxv-minv);
            }
        }
        return ans;

    }
};
//more intuitive
class Solution {
  public:
    int getMinDiff(int a[], int n, int k) {
        vector<pair<int,int>>v;
        vector<int>vis(n);
        for(int i=0;i<n;i++){//store all possible combinations for each element
            if(a[i]-k>=0) v.push_back({a[i]-k,i});
            v.push_back({a[i]+k,i});
        }
        sort(v.begin(),v.end());
        int ele=0,left=0,right=0;
        while(ele<n and right<v.size()){
            if(vis[v[right].second]==0) ele++;
            vis[v[right].second]++;
            right++;
        }
        int ans=v[right-1].first-v[left].first;
        while(right<v.size()){
            if(vis[v[left].second]==1) ele--;
            vis[v[left].second]--;
            left++;
            while(ele<n and right<v.size()){
                if(vis[v[right].second]==0) ele++;
                vis[v[right].second]++;
                right++;
            }
            if(ele==n){
                ans=min(ans,v[right-1].first-v[left].first);

            }else break;

        }
        return ans;
    }
};
