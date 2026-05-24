#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int smj=0;
        for(int j=0;j<n;j++){
            if(a[i][j]<a[i][smj]) smj=j;
        }
        bool flag=1;
        for(int k=0;k<n;k++){
            if(a[k][smj]>a[i][smj]){
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<a[i][smj];
            return 0;
        }
    }
    cout<<"Invalid input";

}
