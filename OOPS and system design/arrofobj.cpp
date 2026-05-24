

#include <bits/stdc++.h>

using namespace std;

class om{
    string t1,t2;
    public:
    void setdata(string a,string b){
        t1=a;
        t2=b;
    }
    void getdata(){
        cout<<t1<<" "<<t2<<endl;
    }
};

int main(){
    om *o=new om[2];
    om* t=o;
    for(int i=0;i<2;i++){
        string a,b;
        cin>>a>>b;
        t->setdata(a,b);
        t++;
    }
     for(int i=0;i<2;i++){
       o->getdata();
       o++;
    }


}
