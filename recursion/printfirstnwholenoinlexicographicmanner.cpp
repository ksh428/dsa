

#include <bits/stdc++.h>
#define m 10000007
using namespace std;
//think in a bottom up way
int n;

void lexico(int n,int i){
    if(i>n) return;
    cout<<i<<" ";
    for(int j=(i==0)?1:0;j<=9;j++){
        lexico(n,i*10+j);
    }
}

int main()
{
    cin>>n;
    lexico(n,0);

}
