#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

void multiply(int A[2][2],int M[2][2]){
      int v1=A[0][0]*M[0][0]+A[0][1]*M[1][0];
      int v2=A[0][0]*M[0][1]+A[0][1]*M[1][1];
      int v3=A[1][0]*M[0][0]+A[1][1]*M[1][0];
      int v4=A[1][0]*M[0][1]+A[1][1]*M[1][1];
      A[0][0]=v1;
      A[0][1]=v2;
      A[1][0]=v3;
      A[1][1]=v4;
}
void power(int A[2][2],int n){
      if(n==0 or n==1) return;
      power(A,n/2);
      multiply(A,A);//A^n/2*A^n/2
      if(n&1){
            int M[2][2]={{1,1},{1,0}};
            multiply(A,M);
      }
}

int fib(int n){
      int A[2][2]={{1,1},{1,0}};
      if(n==0) return 0;
      power(A,n-1);
      return A[0][0];
}

int32_t main(){
    cout<<fib(8);
}
