//given text T and pattern P ,find whether P exsists in T or not and print the start occurences of each
#include<bits/stdc++.h>
using namespace std;
string T,P;
int LP,LT;
bool ismatch(int L,int R)
{
    for(int i=0;i<LP;i++){
        if(P[i]!=T[l+i]) return false;
    }
    return true;
}

int main()
{
    getline(cin,T);
    getline(cin,P);
    LT=T.size();
    LP=P.size();
    for(int L=0,R=LP-1;R<LT;L++,R++){
        if(ismatch(L,R)) cout<<L<<" ";
    }


}
