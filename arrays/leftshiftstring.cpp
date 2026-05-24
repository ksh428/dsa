#include<bits/stdc++.h>
using namespace std;
int rightshift(char s[],int k)
{
    char rs[100];
    int n=strlen(s);
    int index;
    for(int i=0;s[i]!='\0';i++)
    {
        index=(i+k)%n;
        rs[index]=s[i];
    }
    rs[n]='\0';// imp!!
    puts(rs);


}
int leftshift(char s[],int k)
{
    char ls[100];
    int n=strlen(s);
    int index;
    for(int i=0;s[i]!='\0';i++)
    {
        index=(i+(n-k))%n;
        ls[index]=s[i];
    }
    ls[n]='\0';
    puts(ls);

}
int main()
{
    char s[100];
    int k;
    gets(s);
    cin>>k;
   // rightshift(s,k);
    leftshift(s,k);
}
