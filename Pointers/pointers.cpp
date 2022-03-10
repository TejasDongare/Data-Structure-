#include<iostream>
using namespace std;
int main()
{
    int x=10;
    float y=10.14;
    cout<<"Adderss of x="<<&x<<endl;
    cout<<"Address of y="<<&y<<endl;
    char c='A';
    cout<<"If we try to print adddress of char="<<&c<<endl;
    //as the data type for char is char cout doesnt prints address of char instead it prints the value in that addresss
    //But if we do explicit conversion that is void * it means now the data type is not char its unknown
    cout<<"Address after explicit conversion="<<(void *)&c<<endl;
}