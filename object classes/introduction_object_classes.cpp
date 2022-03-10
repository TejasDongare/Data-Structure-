#include<iostream>
using namespace std;
//defining a new datatype
//here it doesnt take any space its just a blueprint of object it will take space only after creating object
class car
{
    int price;
    int mode_no;
    char name[200];
};
int main()
{
    //create object
    //car is datatype c is object
    car c;
    cout<<sizeof(c);
    cout<<sizeof(car);
}