class Solution {
public:
    //binary search approach fails
    //using 2 pointers
    int maxArea(vector<int>& a) {
        int n=a.size();
        int ans=0;
        int l=0,r=n-1;
        //here I am not sure which typ will give me the right ans
        //so I tried both types
        //typ1
        while(l<r){
            ans=max(ans,(r-l)*min(a[r],a[l]));
            if(a[l]>a[r]){
                l++;//changing the larger
            }else{
                r--;
            }
        }
        //typ2
        l=0,r=n-1;
        while(l<r){
            ans=max(ans,(r-l)*min(a[r],a[l]));
            if(a[l]>a[r]){
                r--;//changing the smaller
            }else{
                l++;
            }
        }
        return ans;
    }
};
