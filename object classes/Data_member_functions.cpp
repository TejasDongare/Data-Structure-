#include<iostream>
using namespace std;
//defining a new datatype
//here it doesnt take any space its just a blueprint of object it will take space only after creating object
class car
{
public:
    float price;
    int model_no;
    char name[200];
    float get_discount(float x)
    {
        return price*(1.0-x);
    }
    float apply_discount(float x)
    {
        price=price*(1.0-x);
        return price;
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
    c.price=100;
    c.model_no=101;
    float discount;
    cout<<"Enter the discount="<<endl;
    cin>>discount;
    //cout<<c.get_discount(discount/100);
    cout<<c.apply_discount(discount/100);
}