class Solution {
public:
    int countSubarrays(vector<int>& a, int k) {
        int n=a.size();
        map<int,int>m;
        int ind;
        for(int i=0;i<n;i++){
            if(a[i]<k){
                a[i]=-1;
            }else if(a[i]>k){
                a[i]=1;
            }else a[i]=0,ind=i;
        }
        int ans=0;
        int s=0;
        for(int i=ind;i<n;i++){
            s+=a[i];
            m[s]++;
        }
        s=0;
        //0 : odd length
        for(int i=ind;i>=0;i--){
            s+=a[i];
            ans+=m[-s];
        }
        //1 even length
        s=0;
        for(int i=ind;i>=0;i--){
            s+=a[i];
            ans+=m[1-s];
        }
        return ans;
    }
};
