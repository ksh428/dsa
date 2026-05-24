
class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
        vector<int>ans;
        unordered_map<int,int>m;
        int c=0;
        int r=0;
        while(r<k){
            if(m[a[r]]==0){
                c++;
                m[a[r]]++;
            }else m[a[r]]++;
            r++;
        }
        ans.push_back(c);
        while(r<n){
            if(m[a[r-k]]==1){
                c--;
                m[a[r-k]]--;
            }else m[a[r-k]]--;
            if(m[a[r]]==0){
                c++;
                m[a[r]]++;
            }else m[a[r]]++;
            ans.push_back(c);
            r++;
        }
        return ans;
    }
};
