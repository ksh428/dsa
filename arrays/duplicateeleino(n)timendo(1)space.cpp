/*Given an array of n elements which contains elements from 0 to n-1,
 with any of these numbers appearing any number of times. Find
 these repeating numbers in O(n) and using only constant memory space.
 */

 // modified hash table
 // i/p array
 //1 1 0 3 4 4 4 5 (n=8)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    // modified hash in same array
    for(int i=0;i<n;i++)
    {
        a[a[i]%n]+=n; // does similar as hash
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>=2*n)
            cout<<i<<" ";
    }
}
