#include<iostream>
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
    //setters
    void set_price(float x)
    {
        if(x<-0)
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
    cout<<"enter the price of the car to set"<<endl;
    cin>>price;
    c.set_price(price);
    c.print();
}