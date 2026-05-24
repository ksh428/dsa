#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

//backend
class IButton{
      public:
      virtual void press()=0;
};
class MacButton:public IButton{
      public:
      void press(){
            cout<<"Mac button pressed"<<endl;
      }
};
class WinButton:public IButton{
      public:
      void press(){
            cout<<"Windows button pressed"<<endl;
      }
};
class ITextBox{
      public:
      virtual void showText()=0;
};
class MacTextBox:public ITextBox{
      public:
      void showText(){
            cout<<"Mac textbox"<<endl;
      }
};
class WinTextBox:public ITextBox{
      public:
      void showText(){
            cout<<"Windows textbox"<<endl;
      }
};
class IFactory{
      public:
      virtual IButton* CreateButton()=0;
      virtual ITextBox* CreateTextBox()=0;
};
class MacFactory:public IFactory{
      public:
      IButton* CreateButton(){
            return new MacButton();
      }
      ITextBox* CreateTextBox(){
            return new MacTextBox();
      }
};
class WinFactory:public IFactory{
      public:
      IButton* CreateButton(){
            return new WinButton();
      }
      ITextBox* CreateTextBox(){
            return new WinTextBox();
      }
};
class GUIAbstractFactory{
      public:
      static IFactory* CreateFactory(string s){
            if(s=="mac"){
                  return new MacFactory();
            }
            if(s=="windows"){
                  return new WinFactory();
            }
      }
};

//backend end

int main() {
      //client side code

     cout<<"Enter os type";
     cout<<endl;
     string ostype;
     cin>>ostype;
     IFactory* fact=GUIAbstractFactory::CreateFactory(ostype);
     IButton* btn=fact->CreateButton();
     btn->press();
     ITextBox* tb=fact->CreateTextBox();
     tb->showText();
     //end client
}

/*
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Ikit{
    public:
    virtual void show()=0;
};
class bayernkit:public Ikit{
    public:
    void show(){
        cout<<"fc bayern kit"<<endl;
    }
};
class lfckit:public Ikit{
    public:
    void show(){
        cout<<"lfc kit"<<endl;
    }
};

class Iticket{
    public:
    virtual void showticket()=0;
};
class bayernticket:public Iticket{
    public:
    void showticket(){
        cout<<"bayern ticket"<<endl;
    }
};
class lfcticket:public Iticket{
    public:
    void showticket(){
        cout<<"lfc ticket"<<endl;
    }
};

class Ifactory{
    public:
    virtual Ikit* createkit()=0;
    virtual Iticket* createTicket()=0;
};
class bayernfactory:public Ifactory{
    public:
    Ikit* createkit(){
        return new bayernkit();
    }
    Iticket* createTicket(){
        return new bayernticket();
    }
};
class lfcfactory:public Ifactory{
    public:
    Ikit* createkit(){
        return new lfckit();
    }
    Iticket* createTicket(){
        return new lfcticket();
    }
};

class AbstractFactory{
    public:
    static Ifactory* getfactory(string team){
        if(team=="bayern"){
            return new bayernfactory();
        }else if(team=="lfc"){
            return new lfcfactory();
        }
    }
};

int main(){
    Ifactory* myfact=AbstractFactory::getfactory("lfc");
    Ikit* kit=myfact->createkit();
    kit->show();
    Iticket* ticket=myfact->createTicket();
    ticket->showticket();
}
*/
