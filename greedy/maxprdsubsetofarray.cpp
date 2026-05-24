//BASE CASE IS IMPORTANT
#include <bits/stdc++.h>
using namespace std;

int maxProductSubset(int a[], int n)
{
    if(n==1) return a[0];
    int c0=0;
    int cn=0;
    int prd=1;
    int maxneg=INT_MIN;
    for(int x:a){
        if(x==0) {
            c0++;
            continue;
        }
        if(x<0) {
            cn++;
            maxneg=max(maxneg,x);
        }
        prd*=x;
    }
    if(c0==n) return 0;
    if(cn%2==1){
        if(c0==n-1 and cn==1) return 0;
        return prd/maxneg;
    }else return prd;

}


// Driver Code
int main()
{
	int a[] = { -1, -1, -2, 4, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << maxProductSubset(a, n);
	return 0;
}

