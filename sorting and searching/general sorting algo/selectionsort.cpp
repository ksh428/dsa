#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
       int minval=i;
       for(int j=i+1;j<n;j++){
        if(a[j]<a[minval]){
            minval=j;
        }
       }
       int temp=a[i];
       a[i]=a[minval];
       a[minval]=temp;
    }
    for(int x:a)
        cout<<x<<" ";
}
