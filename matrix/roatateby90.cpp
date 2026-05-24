class Solution
{
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& a, int n)
    {
        // code here //transpose

         for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(a[i][j],a[j][i]);
        }
    }
    for(int j=0;j<n;j++){
       int l=0,r=n-1;
       while(l<=r){
           swap(a[l][j],a[r][j]);
           l++;
           r--;
       }
    }
    }
};
