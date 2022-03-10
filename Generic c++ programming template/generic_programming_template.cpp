#include <iostream>
using namespace std;
template <typename t>
//Generic programming using template
//algorithm-generic example shown below
t linear_search(t *a,int size,t key)
{
    for(int i=0;i<size;i++)
    {
        if(a[i]==key)
        {
            return i;
        }
    }
    return size;
}
int main() {
    int a[]={10,5,6,3,4};
    int size=sizeof(a)/sizeof(int);
    int key=99;
    int index=linear_search(a,size,key);
    if(index==-1)
    {
        cout<<"Element not found "<<endl;
    }
    else
    {
        cout<<"Element found at index="<<index<<endl;
    }
    char ch[]={'A','B','C'};
    size=sizeof(ch)/sizeof(char);
    index=linear_search(ch,size,'D');
    if(index==size)
    {
        cout<<"Element not found "<<endl;
    }
    else
    {
        cout<<"Element found at index="<<index<<endl;
    }
}
