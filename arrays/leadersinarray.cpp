//Write a program to print all the LEADERS in the array. An element is leader if it is greater than
//all the elements to its right side. And the rightmost element is always a leader.
// For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.
// optimized in O(n)
/*
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    int a[n];
    int max=a[n-1];
    cout<<max;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>max)
        {
            max=a[i];
            cout<<max;
        }
    }
}
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];e
    }
    int rightmost=a[n-1];
    cout<<rightmost<<endl;
    //start from the right
    for(int i=n-2;i>=0;i--){
        if(a[i]>rightmost){
            cout<<a[i]<<endl;
            rightmost=a[i];
        }
    }

}

