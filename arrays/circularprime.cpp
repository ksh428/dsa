// TBD
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,c=0;
    for(int i=N;i>=0;i/=10)
        c++;
    // find permutations

    int num=N;
    while(isprime(num))
    {
        int r=num%10;
        int div=num/10;
        int num=pow(10,c-1)*r+div;
        if(num==N)
            return 1;
    }
    else
        return 0;



}
