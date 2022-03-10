#include<iostream>
using namespace std;
int main()
{
    int x=10;
    int y=15;
    int *xptr=&x;
    cout<<"xptr="<<xptr<<endl;
    cout<<"*xptr="<<*xptr<<endl;
    cout<<"(*xptr)+1="<<(*xptr)+1<<endl;
    cout<<"*(xptr+1)="<<*(xptr+1)<<endl;
}