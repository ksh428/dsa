

#include <bits/stdc++.h>

using namespace std;
void printUnion(int a1[],int a2[],int m,int n){
    // int i=0,j=0;
    // while(i<m && j<n){
    //     if(a1[i]<a2[j]) {
    //         cout<<a1[i];
    //         i++;
    //     }else if(a1[i]==a2[j]){
    //         cout<<a1[i];
    //         i++;j++;
    //     }else {
    //         cout<<a2[j];
    //         j++;
    //     }
    // }
    // while(i<n) cout<<a1[i++];
    // while(j<n) cout<<a2[j++];
    map<int,int>mp;
    for(int i=0;i<m;i++){
        mp[a1[i]]++;
    }
    for(int j=0;j<n;j++){
        mp[a2[j]]++;
    }
    for(auto f:mp) cout<<f.first;
}
void intersection(int a[],int m,int b[],int n){ //1,2,3,4    //2,2,4,6,7,8

    vector<int> res;
        int i=0,j=0;

		//Merge function
        while(i<m && j<n)
        {
				if(i>0 && a[i] == a[i-1])//Checking duplicates
                i++;
            else if(a[i] == b[j])    //Duplicate Found
            {
                res.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i]< b[j])
                i++;
            else
                j++;
        }

        for(int x:res) cout<<x;
}

int main()
{
     int arr1[] = { 1, 2, 2, 2, 3 };
    int arr2[] = { 2, 3, 4, 5 };

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    // Function calling
    //printUnion(arr1, arr2, m, n);
    intersection(arr1,m,arr2,n);
}
