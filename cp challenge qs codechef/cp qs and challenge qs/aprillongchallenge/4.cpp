// logic
/* in first day we take 3 pages if n>=3
and on the rest days we take 2 pages n & n+1 since n& n+1 are always coprime.
the no. of even between 1 & n is n/2
so it will take min of n/2 days to complete the book and if we can completet it in n/2 days
it will give the optimal solution which consists of the combination above*/

/*if no. of days is even then for each day we can print 2 pages n &n-1
if n is odd for 1 st day we print 3 page 1 2 3 and for the rest days we print 2 days each (since
                                                                                            now it becomes even no. of days as odd -odd =even)
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    long long int N,i,D;
    cin>>T;
    while(T--)
    {
        cin>>N;
        D=N/2;

        if(N==1)
        {
            cout<<1<<endl;
            cout<<1<<" "<<1<<endl;
        }
       else
       {

            cout<<D<<endl;
            if(N%2==0)
            {
                for(int i=1;i<=D;i++)
                {
                    cout<<2<<" "<<2*i-1<<" "<<2*i<<"\n";
                }
            }
            else
            {
                cout<<3<<" "<<1<<" "<<2<<" "<<3<<"\n";
                for(int i=2;i<=D;i++)
                {
                    cout<<2<<" "<<2*i<<" "<<2*i+1<<"\n";
                }
            }

       }
    }
	return 0;
}
