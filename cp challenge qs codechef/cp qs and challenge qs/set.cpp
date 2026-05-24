#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int>s;
    // by default ste is asc order
    s.insert(1);
    s.insert(345);
    s.insert(4);       //all elements should be unique
    s.insert(100);   // values cannot be modified when element is added to a set
    s.insert(25);
    s.insert(3);
    set<int>::iterator i =s.begin();
    for(;i!=s.end();i++)
    {
        cout<<*i<<endl;
    }
  //s.size() for size
  s.erase(100);// 1way to delete
  s.erase(s.begin(),s.find(4)); // 2nd way to delet sp elements
  s.clear(); //  delets the entire set

   // for storing or making set in descending order
   set<int greater><int>>s1;

}
