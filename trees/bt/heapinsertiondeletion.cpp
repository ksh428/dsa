#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int i)
{
    int k=a[i];
    int par=(i-1)/2;
    while(par>=0 && a[par]<k){
        a[i]=a[par];
        i=par;
        par=(i-1)/2;
    }
    a[i]=k;
}

void insertheap(int a[],int num,int &hsize)
{
    hsize++;
    a[hsize-1]=num;
    heapify(a,hsize);
}


int main()
{
    int a[]={20,11,15,10,8,12};
    //int asize=a.size();
    insertheap(a,21,6);

}
