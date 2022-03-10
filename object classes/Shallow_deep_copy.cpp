#include <iostream>
#include<cstring>
using namespace std;
class car
{
private:
    float price;
public:
    int model_no;
    char *name;
    float get_price()
    {
        return price;
    }
    car(int p,int m,char *ch)
    {
        price=p;
        model_no=m;
        name=new char[strlen(ch)+1];
        strcpy(name,ch);
    }
    void print()
    {
        cout<<"Name of car:-"<<name<<endl;
        cout<<"Model No of car:-"<<model_no<<endl;
        cout<<"Price of car:-"<<price<<endl;
    }
    void deep_copy(car &x)
    {
        price=x.price;
        model_no=x.model_no;
        name=new char[strlen(x.name)+1];
        strcpy(name,x.name);
    }
};
int main() {
   car c(100,202,"BMW");
   //by default shallow copy
   cout<<"Shallow Copy"<<endl;
   car d(c);
   cout<<endl<<"Car c:-"<<endl;
   c.print();
   cout<<endl<<"Car d:-"<<endl;
   d.print();
   cout<<"After updating the Name of car c"<<endl;
   c.name[0]='A';
   cout<<endl<<"Car c:-"<<endl;
   c.print();
   cout<<endl<<"Car d:-"<<endl;
   d.print();
  // Deep shallow
   cout<<endl<<"Deep Copy"<<endl;
   car e(180,303,"AUDI");
   car f(e);
   cout<<endl<<"Car e"<<endl;
   e.print();
   cout<<endl<<"Car f "<<endl;
   f.print();
   cout<<endl<<"After updating the name of car e"<<endl;
   f.deep_copy(e);//here we are doing deep copy we can do it in constructor
   e.name[0]='B';
    cout<<endl<<"Car e"<<endl;
   e.print();
   cout<<endl<<"Car f "<<endl;
   f.print();
}
