

#include <bits/stdc++.h>

using namespace std;

void heapify(int a[],int i){
    int l=2*i+1;
    int r=2*i+2;
    int lar=i;
    if(l<n and a[l]>a[lar]) lar=l;
    if(r<n and a[r]>a[lar]) lar=r;
    if(lar!=i){
        swap(a[lar],a[i]);
        heapify(a,lar);
    }
}
void buildheap(int a[],int n){
    int k=n/2;
    for(int i=k-1;i>=0;i--){
        heapify(a,i);
    }
}
int main()
{

}

