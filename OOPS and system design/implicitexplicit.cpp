
#include<iostream>
using namespace std;

class Om{
    string name;
    int age;
    public:
    Om(string n){
        name=n;
        age=-1;
    }
    Om(int x){
        age=x;
        name="om";
    }
    void show(){
        cout<<name<<" "<<age;
    }
};
void printom(Om a){

}
int main(){
   // printom(23);
    Om o=20;//implicit conv : compiler sees that there is a constructor with an int and implicitly converts it into Om clASS
    Om o1=string("Koi");
    o.show();
   o1.show();

}

