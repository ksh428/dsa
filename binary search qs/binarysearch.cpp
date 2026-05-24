#include<bits/stdc++.h>
using namespace std;

/*
int binarysearch(int a[],int l,int r,int x){
    if(r>=l){}
    int mid=l+(r-l)/2;
    if(a[mid]==x) return mid;
    if(a[mid]<x) binarysearch(a,mid+1,r,x);
    if(a[mid]>x) binarysearch(a,l,mid-1,x);
    }
    return -1;
}
} */
int bs(int a[],int l,int r,int x){
    int ans=-1;
    while(1<=r){
        int mid=l+(r-l)/2;
        if(a[mid]==x) {
                ans= mid;
                r=mid-1;
        }
        if(a[mid]<x) l=mid+1;
        if(a[mid]>x) r=mid-1;

    }
    return ans;
}
int main()
{
    int arr[] = { 2, 4, 10, 10, 10,8,20 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = bs(arr, 0, n - 1, x);
    cout<<result;
}
