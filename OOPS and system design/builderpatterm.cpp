//COMPLEX object with lots of configurations 
#include <iostream>
#include<string>
using namespace std;

//product
class Desktop
{
    string keyboard;
    string monitor;
    public:
    void setkeyboard(string s){
        keyboard=s;
    }
    void setmonitor(string s){
        monitor=s;
    }
    void display(){
        cout<<keyboard<<" "<<monitor<<endl;
    }
};

//productbuilder (will always have the product)
class DesktopBuilder //has product
{
      protected:
            Desktop * desktop;
      public:
      DesktopBuilder(){
            desktop=new Desktop();
      }
      virtual void buildMonitor()=0;
      virtual void buildKeyBoard()=0;
      virtual Desktop* getDesktop(){
            return desktop;
      }
};

//concrete builder
class DellDesktopBuilder:public DesktopBuilder{
      void buildMonitor(){
            desktop->setmonitor("Dell monitor");
      }
      void buildKeyBoard(){
            desktop->setkeyboard("Dell keyboard");
      }
};

class HPDesktopBuilder:public DesktopBuilder{
      void buildMonitor(){
            desktop->setmonitor("HP monitor");
      }
      void buildKeyBoard(){
            desktop->setkeyboard("HP keyboard");
      }
};

//Director will use builder obj to create a product
class DesktopDirector{//has builder and uses it to build product
      DesktopBuilder* desktopBuilder;
      public:
      DesktopDirector(DesktopBuilder* pdb){
            desktopBuilder=pdb;
      }
      Desktop* getDesktop(){
            return desktopBuilder->getDesktop();
      }
      Desktop* BuildDesktop(){
            desktopBuilder->buildMonitor();
            desktopBuilder->buildKeyBoard();
             return desktopBuilder->getDesktop();
      }
};

int main(){
      //client
      HPDesktopBuilder *hppc=new HPDesktopBuilder();
      DellDesktopBuilder *delpc=new DellDesktopBuilder();

      DesktopDirector* d1=new DesktopDirector(hppc);
      DesktopDirector* d2=new DesktopDirector(delpc);

      Desktop* hp=d1->BuildDesktop();
      Desktop* dell=d2->BuildDesktop();

      hp->display();
      dell->display();
}
