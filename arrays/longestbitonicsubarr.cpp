#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
   int inc[n],dec[n];
   inc[0]=1;
   dec[n-1]=1;
   for(int i=1;i<n;i++) //make increasing subsequence array where every eleent represents length of the possiblesubarray
   {
       if(a[i]>=a[i-1])
        inc[i]=inc[i-1]+1;
       else inc[i]=1;
   }
   for(int i=n-2;i>=0;i--) // make desc aray
   {
       dec[i]=(a[i]>=a[i+1])?dec[i+1]+1:1;
   }
   int res[n];
   for(int i=0;i<n;i++)
   {
       res[i]=inc[i]+dec[i];
   }
   int max1=res[0];
   for(int x:res)
   {
       if(x>max1)
       max1=x;

   }
   cout<<max1-1; // since every element is incl 2 ice once in each array
}
