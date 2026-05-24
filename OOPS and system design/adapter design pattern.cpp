// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class XMLdata{
    string data;
    public:
    XMLdata(string s){
        data=s;
    }
    string getdata(){
        return data;
    }
};
class DataAnalyticstool{
    
    string jsonData;
    public:
    DataAnalyticstool(){}
    DataAnalyticstool(string s){
        jsonData=s;
    }
    virtual void analyzeData(){
        cout<<"ANlaysed data "<<jsonData<<endl;
    }
};

class Client{
    public:
    void processdata(DataAnalyticstool* tool){
        tool->analyzeData();
        
    }
};

class Adapter:public DataAnalyticstool{
    XMLdata* xmldata;
    public:
    Adapter(XMLdata* xdata){
        xmldata=xdata;
    }
    void analyzeData() override{
        cout<<"convertingxml data "<<xmldata->getdata()<<" to json data"<<endl;
    }
};

int main()
{
    XMLdata* xdata=new XMLdata("sample xml data");
    // DataAnalyticstool* tool=new DataAnalyticstool();
    DataAnalyticstool* tool=new Adapter(xdata);
    Client *c=new Client;
    c->processdata(tool);
    
}