#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {3, 3, 3, 3, 4, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count=0;
    int b[10]={0};
    for(int i=0;i<7;i++)
    {
        b[arr[i]]++;
    }
    sort(b,b+n);
    int maj=b[9];
    if(maj>(n/2))
        cout<<"yes"<<maj;
    else
        cout<<"no";

}
