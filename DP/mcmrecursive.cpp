#include<bits/stdc++.h>
using namespace std;
int solve(int a[],int i,int j)
{
    if(i>=j) return 0;
    //now move k
    // i=1 and j=n-1
    //find loop  for k
    /* find range for k and the 2 divisions to make */
    /* run manulayy and check
    k=i to j-1
    and divide i to k and k+1 to j.
    there may be other possibilites
    */
    for(int k=i;k<j;k++){
        /*solve(a,i,k);
        solve(a,k+1,j); */
        int temp=solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[j]*a[k];
        int ans=INT_MAX;
        ans=min(temp,ans);
    }
    return ans;


}
int main()
{
    nt arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, 1, n - 1);

}
