
#include <bits/stdc++.h>

using namespace std;

class abstractEmp{//contract
    virtual void asfforpromotion()=0;//obligatory //pure virtual function
};

class employee:abstractEmp
{
    public:

      string Name;
      int age;
      string company;
      static int count;

      employee (string n, string c, int a)
      {
        this->age = a;
        Name = n;
        company = c;
        count++;
      }
      void display ()
      {
        cout << Name << " " << company << " " << age;
      }
      void asfforpromotion(){
          if(age>35){
              cout<<"promoted"<<"\n";
          }else cout<<"no prom"<<"\n";
      }
};
class Developer:public employee{
    public:
        string proglang;
        static int dev;
        Developer(string n, string c, int a,string pl)
            :employee(n,c,a)//base class constructor
        {
            dev++;
            proglang=pl;
        }
};
int employee:: count=0;
int Developer::dev=0;

int main ()
{
  employee e1 ("om", "amazon", 21);
  employee e2("ffg","google",37);
    employee e3("ffg","google",37);

  employee e4("ffg","google",37);

  employee e5("ffg","google",37);

//   e1.asfforpromotion();
//   e2.asfforpromotion();
  //cout << e1.getcompany ();
  //e1.display ();
  Developer d("ksh","abc",23,"c++");
   Developer d1("ksh","abc",23,"c++");
  d.asfforpromotion();
  cout<<employee::count-Developer::dev;

}

