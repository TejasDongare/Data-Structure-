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
        cout<<"Car created="<<name<<endl;
    }
    car(float p,int m_n,char *n)
    {
        cout<<"Car created succesfully"<<endl;
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
    //destructor automatically deletes element after function call is over untill it is not dynamically allocted dyanmically allocated varibales have to be deleted manually
    ~car()
    {
        cout<<"Entered in destructor for="<<name<<endl;
    }

};
int main()
{
    //create object
    //car is datatype c is object
    car c(200,101,"AUDI");
    cout<<endl<<"car c:-"<<endl;
    c.print();
    //we can delete object of class using delete keyword only if it is dynamically allocated
    car *d=new car(120,202,"BMW");
    cout<<endl<<"Car d:-"<<endl;
    d->print();
    cout<<endl;
    delete d;//we can only delete object d but not object c as it is not dynamically allocated
}