


#include <bits/stdc++.h>
#define maxn 1000000
using namespace std;


int main()
{
   int a[]={3,4,7,2,-3,1,4,2};
   int n=sizeof(a)/sizeof(a[0]);
   int k=7;
   map<int,int>m;
   int sum=0,ans=0;
   int i=0;
   while(i<n){
       sum+=a[i];
       if(sum==k) ans++;
       if(m.find(sum-k)!=m.end()){
           ans+=m[sum-k];
       }
       m[sum]++;
       i++;
   }
   cout<<ans;

}

