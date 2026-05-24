#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int fun1(int a[],int n,int k){
      int ans=0;
      for(int i=0;i<n;i++){
            if(a[i]==1){
                  int o=0;
                  while(i+1<n and a[i+1]==1) {
                        i++;
                        o++;
                  }
                  ans+=o*(o+1)/2;
            }
      }
      return ans;
}

int fun2(int a[],int n,int k){
      int i=0,j=0;
      int p=1;
      int ans=0;
      while(j<n){
            p*=a[j];
            if(p>k){
                  while(i<=j and p>k){
                        p/=a[i];
                        i++;
                  }
            }if(p==k){
                  int o=0;
                  while(j+1<n and a[j+1]==1){
                        o++;
                        j++;
                  }
                  ans+=(o+1);
                  while(i<=j and a[i]==1){
                        ans+=(o+1);
                        i++;
                  }
                  p/=a[i];
                  i++;
            }
            j++;
      }
      return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
     // int n;
     // cin>>n;
      int a[]={1,2,3,4,1};
    //  for(int i=0;i<n;i++) cin>>a[i];
      int k=24;
      if(k==1){
            cout<<fun1(a,5,k);
      }else{
            cout<<fun2(a,5,k);
      }
}
