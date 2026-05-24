//minimum  swaps req to sort an array of n elements
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int c=0;
    for(int i=0;i<n-1;i++){
        if(a[i]!=i+1){
            int temp;
            temp=a[a[i]-1];
            a[a[i]-1]=a[i];
            a[i]=temp;
            c++;
        }
    }
    cout<<c;
}

