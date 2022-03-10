#include<iostream>
#include<cstring>
using namespace std;
//defining a new datatype
//here it doesnt take any space its just a blueprint of object it will take space only after creating object
class car
{
//access specifier are public or private or protected

private:
    float price;
public:
    int model_no;
    char name[200];
    car()
    {
        cout<<"Constructor in car"<<endl;
    }
    car(float p,int m_n,char *n)
    {
        price=p;
        model_no=m_n;
        strcpy(name,n);
    }
    //setters
    void set_price(float x)
    {
        if(x<0)
        {
            //if price is negative set price as 100
            price=100;
        }
        else
        {
            price=x;
        }
    }
    //getters
    float get_price()
    {
        return price;
    }
    void print()
    {
        cout<<"Car Name:-"<<name<<endl;
        cout<<"Car Model No:-"<<model_no<<endl;
        cout<<"Price:-"<<price<<endl;
    }
    car(car &x)
    {
        cout<<"copy constructor is called"<<endl;
        price=x.price;
        model_no=x.model_no;
        strcpy(name,x.name);
    }
};
int main()
{
    //create object
    //car is datatype c is object
    car c;
    c.name[0]='B';
    c.name[1]='M';
    c.name[2]='W';
    c.model_no=101;
    float price;
    c.set_price(150);
    cout<<endl<<" Car C:-"<<endl;
    c.print();
    cout<<endl<<" Car D:-"<<endl;
    car d(130,202,"AUDI");
    d.print();
    cout<<endl<<" Car E:-"<<endl;
    //First way of calling Copy construcor
    car e(d);
    //Second way of calling copy Constructor
    car f=d;
    e.print();
}