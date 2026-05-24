#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // assuming atleast 1 element >0
    int mineh,maxeh,msf;
    mineh=maxeh=msf=1;
    int flag=0;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            flag=1;
            maxeh*=a[i];
            mineh=min(mineh*a[i],1);
        }
        else if(a[i]==0){
            maxeh=mineh=1;
        }else{
            int temp=maxeh;
            maxeh=max(1,mineh*a[i]);
            mineh=temp*a[i];
        }
         if(maxeh>msf)
            msf=maxeh;
}
    if(flag){
    cout<<msf;
    }
}
