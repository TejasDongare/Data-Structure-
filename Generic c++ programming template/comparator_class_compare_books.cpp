#include <iostream>
#include<list>
using namespace std;
class books
{
    public:
    int price;
    string name;
    books()
    {

    }
    books(int p,string n)
    {
        price=p;
        name=n;
    }
};

class bookcompare
{
    public:
    bool operator()(books a,books b){
        if(a.name==b.name)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
template<class forwarditerator,class b,class c>
forwarditerator search(forwarditerator start,forwarditerator end,b key,c cmp)
{
    while(start!=end)
    {
        if(cmp(*start,key))
        {
            return start;
        }
        start++;
    }
    return end;
}

int main()
{
    books b(100,"C++");
    books p(200,"Python");
    books j(300,"Java");
    list<books> bk;
    bk.push_back(b);
    bk.push_back(p);
    bk.push_back(j);
    bookcompare cmp;
    books key(120,"C");
    auto it=search(bk.begin(),bk.end(),key,cmp);
    if(it==bk.end())
    {
        cout<<"Not found"<<endl;
    }
    else
    {
        cout<<"found"<<endl;
    }
}