#include<bits/stdc++.h>
#define NA -1
using namespace std;
int main()
{
    int m,n;
    cout<"enter values of m&n"<<endl;
    cin>>m>>n;
    int a1[m+n],a2[n];
    for(int i=0;i<m;i++)
    {
        cin>>a1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a2[i];
    }
    int k=a1[(m+n)-1];
    for(int j=m+n-1;j>=0;j--) //move elements to last
    {
        if(a1[j]!=NA)
        {
            a1[k]=a1[j];
            k--;
        }
    }
    int i=n;
    int j=0;
    int k=0;
    while(k<m+n)
    {
        if((a1[i]<=a2[j])&& i<(m+n))
        {
            a1[k]=a1[i];
            i++;k++;
        }
        else{
            a1[k]=a2[j];
            k++;
            j++;
        }
    }
    // now print the array // rus inO(m+n)

}
