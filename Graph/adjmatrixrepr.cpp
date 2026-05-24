#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter no of vertices"<<endl;
    cin>>n;
    int a[n][n];
    memset(a, 0, sizeof(a));
    int graphtype;
    cout<<"enter graphtype"<<endl;
    cin>>graphtype;
    int maxedges;
    if(graphtype==1)//undirected{
        {
            maxedges=n*(n-1)/2;
        }
        else{
            maxedges=n*(n-1);
        }
    int ori,dest;
    for(int i=0;i<maxedges;i++){
        cout<<"enter origin and destn"<<endl;
        cin>>ori>>dest;
        if(ori>=n || dest>=n || ori<0 || dest<0){
            cout<<"invalid";
            i--;
        }
        else{
            a[ori][dest]=1;
            if(graphtype==1) a[dest][ori]=1;
        }

    }
    //display
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
