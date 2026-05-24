#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[20],str1[20];
    cout<<"enter string"<<endl;
    gets(str);

    int n=strlen(str);
    int i=0;
    for(int j=n-1;j>=0;j--)
    {
        str1[i]=str[j];
        i++;
    }
    if(strcmp(str1,str)!=0)
        cout<<"no";
    else
        cout<<"yes";

}
