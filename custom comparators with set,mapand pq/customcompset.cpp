// for using custom comparator with sets/maps/priority_queue we need to overload a operator in our clas/structure


#include <bits/stdc++.h>

using namespace std;

class com{
    public:
        bool operator ()(const int &a,const int &b){
            return a>b;//desc order
        }
};

int main()
{
    set<int,com>s;
    s.insert(2);
    s.insert(1);
    s.insert(3);
    for(auto it:s){
        cout<<it<<" ";
    }
}

