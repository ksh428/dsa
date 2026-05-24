

#include <bits/stdc++.h>

using namespace std;

class Complex{
    int a,b;
    public:
    void set(int x,int y){
        a=x;
        b=y;
    }
    void show(){
        cout<<a<<" "<<b;
    }
    Complex operator+(Complex c){
        Complex t;
        t.a=a+c.a;
        t.b=b+c.b;
        return t;
    }
};

int main()
{
   Complex c1,c2,c3;
   c1.set(2,3);
   c2.set(3,4);
   c3=c1+c2;
   c3.show();
}

