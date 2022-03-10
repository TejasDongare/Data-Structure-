#include <iostream>
using namespace std;
template <typename t>
class Vector
{
public:
    int cs=0;
    int maxsize;
    t *a;
public:
    Vector(int defaultsize=4)
    {
         maxsize=defaultsize;
         a=new t[maxsize];
    }
    t get_element(const int i)
    {
        return a[i];
    }
    void push_back(int i)
    {
        if(cs==maxsize)
        {
            t *old=a;
            a=new int[maxsize*2];
            for(int temp=0;temp<maxsize;temp++)
            {
                a[temp]=old[temp];
            }
            maxsize=2*maxsize;
            delete [] old;//we cannot directly delete array a as it is data member
        }
        a[cs]=i;
        cs++;
    }
    //return by reference
    t& operator[](int i)
    {
        return a[i];
    }
    void print()const{
        for(int temp=0;temp<cs;temp++)
        {
            cout<<a[temp]<<" ";
        }
    }
    void pop()
    {
        if(cs!=0)
        {
            cs--;
        }
    }
    int get_size() const
    {
        return cs;
    }
};
ostream& operator<<(ostream &os,Vector<int> &v)
{
    for(int i=0;i<v.get_size();i++)
    {
        os<<v.get_element(i)<<" ";
    }
    return os;
}
int main() {
    Vector<int> v;
    for(int i=0;i<6;i++)
    {
        v.push_back(i);
    }
    v.print();
    cout<<endl;
    v.push_back(30);
    cout<<v[2]<<endl;;
    cout<<v<<endl;
    //returning by reference
    v[2]=10;
    v[2]+=15;
    cout<<v[2]<<endl;
}
