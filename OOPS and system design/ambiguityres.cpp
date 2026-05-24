

#include <bits/stdc++.h>

using namespace std;

class B1{
    public:
    void meet(){
        cout<<"Yes";
    }
};
class B2{
    public:
    void meet(){
        cout<<"NO";
    }
};
class D:public B1,public B2{
    public:
    void meet(){
        B2::meet();//ambiguity resolution

    }
};

int main()
{
    D d;
    d.meet();

}

