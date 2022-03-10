#include <iostream>
#include<list>
using namespace std;
//iterator example
template <class ForwardIterator,class T>
ForwardIterator search(ForwardIterator s,ForwardIterator e,T key)
{
    while(s!=e)
    {
        if(*s==key)
        {
            return s;
        }
        s++;
    }
    return e;
}
int main() {
    int a[]={2,3,10,1,6};
    int size=sizeof(a)/sizeof(int);
    list<int>l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(70);
    l.push_back(23);
    l.push_back(45);
    auto t=search(l.begin(),l.end(),23);
    if(t!=l.end())
    {
        cout<<"Not found"<<endl;
    }
    else
    {
        cout<<*t<<endl;
    }
}
