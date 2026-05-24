/*
Recursive:
we will start from the last elements of both the arrays and compare them
if they are equal then u know
    else we have 2 options : 1.to call st1 full length and st2 len-1 and vice versa
    since any one of them is possible.
    since we are askked to find max use max.

*/

#include<bits/stdc++.h>
using namespace std;
int lcs(char X[],char Y[],int m,int n)
{
    if(m==0 || n==0)
        return 0;
    if(X[m-1]==Y[n-1])
        return 1+lcs(X,Y,m-1,n-1);
    else {
        return max(lcs(X,Y,m,n-1),lcs(X,Y,m-1,n));
    }

}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;

}

