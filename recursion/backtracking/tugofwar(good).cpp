#include <bits/stdc++.h>
using namespace std;

// function that tries every possible solution by calling itself recursively
int n;
int mndiff=INT_MAX;

void display(vector<int>s1,vector<int>s2){
    for(int x:s1) cout<<x<<" ";
    cout<<"2nd"<<" ";
    for(int x:s2) cout<<x<<" ";
    cout<<endl;
}
vector<int>finals1,finals2;
void solve(int a[],int i,vector<int>s1,vector<int>s2,int sum1,int sum2){
    if(i==n){
        int diff=abs(sum1-sum2);
        if(diff<mndiff){
            mndiff=diff;
            finals1=s1;
            finals2=s2;
        }
        return;
    }

    if(s1.size()<(n+1)/2){
        s1.push_back(a[i]);
        solve(a,i+1,s1,s2,sum1+a[i],sum2);
        s1.pop_back();
    }
    if(s2.size()<(n+1)/2){
         s2.push_back(a[i]);
        solve(a,i+1,s1,s2,sum1,sum2+a[i]);
        s2.pop_back();
    }

}

void tugOfWar(int a[], int n)
{
    vector<int>s1,s2;
    solve(a,0,s1,s2,0,0);
    display(finals1,finals2);
}

// Driver program to test above functions
int main()
{
	int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	n = sizeof(arr)/sizeof(arr[0]);
	tugOfWar(arr, n);
	return 0;
}

