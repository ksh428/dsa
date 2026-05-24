

#include <bits/stdc++.h>

using namespace std;

void ncr(int n,int r,int cb,int nis,string asf){
    if(cb>n){
        if(nis==r){
            cout<<asf<<endl;
        }
        return;
    }
    ncr(n,r,cb+1,nis+1,asf+'o');
    ncr(n,r,cb+1,nis,asf+'x');
}

int main()
{
   int n,r;
    cin>>n>>r;
    ncr(n,r,1,0,"");

}

