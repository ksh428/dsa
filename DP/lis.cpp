
/* Dynamic Programming C++ implementation of LIS problem */
#include<bits/stdc++.h>
using namespace std;

//This problem can also be solved usig LCS

//o(nlogn)

int lis(int a[],int n){
        vector<int>v;
        v.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]>v.back()) v.push_back(a[i]);
            else{
                int idx=lower_bound(v.begin(),v.end(),a[i])-v.begin();
                v[idx]=a[i];
            }
        }
        return v.size();
}


//o(n^2)
int lis( int a[], int n )
{
    int lis[n];
    lis[0]=1;

    for(int i=1;i<n;i++){ //NB
        lis[i]=1;
        for(int j=0;j<i;j++){ //NB
            if(a[j]<a[i] && (lis[i]<lis[j]+1)){ //SB
                lis[i]=lis[j]+1; //SB
            }
        }
    }
   int maxval=0;
   for(int x:lis){
    if(x>maxval) maxval=x;
   }
   return maxval;


}

/* Driver program to test above function */
int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Length of lis is %d\n", lis( arr, n ) );
	return 0;
}
