#include<bits/stdc++.h>
using namespace std;


int method2(int a[],int n,int d){
    int index;
    int ansarray[n];
    for(int i=0;i<n;i++){
        index=(i+d)%n;
        ansarray[i]=a[index];

    }
    for(int x:ansarray)
    {
        cout<<x;

    }

}


int main()
{
    int n,d;
    cin>>n>>d;
    int a[n];
    cout<<"enter array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int temp[d];
    for(int i=0;i<d;i++)
    {
        temp[i]=a[i];

    }
    int k=0;
    for(int i=d;i<n;i++)
    {
        a[k]=a[i];
        k++;
    }

    int j=0;
    for(int i=k;i<n;i++){
        a[i]=temp[j];
        j++;
    }
    for(int x:a){
        cout<<x<<" ";
    }
    cout<<endl;
    method2(a,n,d);


}
