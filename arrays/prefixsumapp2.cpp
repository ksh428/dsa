// 0 subarray sum
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(sum==0||s.find(sum)!=s.end())
            continue;
        s.insert(sum);
    }
}
