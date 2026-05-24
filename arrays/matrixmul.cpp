#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r;
    cout<<"enter no.of rows of 1st matrix"<<endl;
    cin>>r;
    int a[r][r],b[r][r],c[r][r];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
            c[i][j]=0;
            for(int k=0;k<r;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}
