class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND (int a[], int n)
    {
        int ans=0;
        for(int i=31;i>=0;i--){
            int cp=ans|(1<<i);
            int c=0;
            for(int j=0;j<n;j++){
                if((cp&a[j])==cp) c++;
            }
            if(c>=2){
                ans|=(1<<i);
            }
        }
        return ans;
    }
};
