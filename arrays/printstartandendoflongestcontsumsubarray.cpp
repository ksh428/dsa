//print the start and end index of hgighest sum subarray

#include <bits/stdc++.h>

using namespace std;

void maxSubArraySum(int a[],int n){
   int msf=INT_MIN,meh=0;
   int start=0,end=0,s=0;
   for(int i=0;i<n;i++){
       meh+=a[i];
       if(meh>msf){
           msf=meh;
           start=s;
           end=i;
       }
       if(meh<0){
           meh=0;
           s=i+1;
       }
   }
   cout<<msf<<" "<<start<<" "<<end;
}

int main()
{
    int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   maxSubArraySum(a, n);


}
