#include<bits/stdc++.h>
using namespace std;
#define OUT 0
#define IN 1
int main()
{
    string s;
    cin>>s;

    int c=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
         int STATE=OUT;
        if(s[i]==" " || s[i]=="\t" || s[i]=="\n")
            STATE =OUT;
        else if(STATE==OUT){
            STATE=IN;c++;
        }

    }
    cout<<c;
}
