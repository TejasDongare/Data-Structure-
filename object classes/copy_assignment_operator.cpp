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
  
car () 
  {
    
//cout << "Constructor in car" << endl;
  
} 
car (float p, int m_n, char *n) 
  {
    
price = p;
    
model_no = m_n;
    
strcpy (name, n);
  
} 
    //setters
  void set_price (float x) 
  {
    
if (x < 0)
      
      {
	
	  //if price is negative set price as 100
	  price = 100;
      
}
    
    else
      
      {
	
price = x;
      
}
  
}
  
    //getters
  float get_price () 
  {
    
return price;
  
}
  
void print () 
  {
    
cout << "Car Name:-" << name << endl;
    
cout << "Car Model No:-" << model_no << endl;
    
cout << "Price:-" << price << endl;
  
} 
car (car & x)		//here we have to call by reference always
  {
    
      //cout<<"copy constructor is called"<<endl;
      price = x.price;
    
model_no = x.model_no;
    
strcpy (name, x.name);
  
} 
    //copy assignment operator here we can can call by reference or call by value
  void operator= (car x) 
  {
    
cout << "Copy assignment constructor called" << endl;
    
price = x.price;
    
model_no = x.model_no;
    
strcpy (name, x.name);

} 
 
};


int
main () 
{
  
    //create object
    //car is datatype c is object
    car c (120, 110, "BMW");
  
car d;
  
    //copy assignment operator
    d = c;
    cout<<"car c:-"<<endl;
    c.print();
    cout<<endl<<"Car d:-"<<endl;
    d.print();
 
 
}
