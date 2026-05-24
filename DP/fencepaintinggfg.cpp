


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int same=k;
    int diff=k*(k-1);
    int tot=same+diff;
    for(int i=3;i<=n;i++){
        same=diff*1;
        diff=tot*(k-1);
        tot=same+diff;
    }
    cout<<tot;


}
