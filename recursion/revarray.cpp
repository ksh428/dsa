//reverse array
#include<bits/stdc++.h>
using namespace std;

void rev(int a[],int i,int j){
    if(i>=j)
        return;
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    rev(a,i+1,j-1);
}

int main()
{
    int a[]={1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    int i=0;
    int j=n-1;
    rev(a,i,j);
    for(int x:a){
        cout<<x<<endl;
    }
}
