#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>A={11,2,3,14};
    cout<<A[1]<<endl;
    sort(A.begin(),A.end()); //o(nlogn)
    bool present=binary_search(A.begin(),A.end(),3);
    A.push_back(100);
     A.push_back(100);
      A.push_back(100);
       A.push_back(100);
        A.push_back(123); //{2,3,11,14,100,100,100,100,123}
    vector<int>::iterator it=lower_bound(A.begin().A.end(),100); // returns the oerator to thr 1st element >= 10=
    vector<int>::iterator it2=upper_bound(A.begin().A.end(),100); // returns the oerator to hte ist element strictly greater than 100
vector<int>::iterator i=upper_bound(A.begin().A.end(),100);
i=A.begin();
for(;i!=A.begin();i++)
{
    cout<<*i<<endl;
}

}
