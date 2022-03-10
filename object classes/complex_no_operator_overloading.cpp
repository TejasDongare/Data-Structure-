#include <iostream>
using namespace std;
class complex
{
private:
    int real;
    int img;
public:
    complex()
    {
        real=0;
        img=0;
    }
    complex(const int r,const int i)
    {
        real=r;
        img=i;
    }
    void set_real_img(int a,int b)
    {
        real=a;
        img=b;
    }
    void set_real(const int r)
    {
        real=r;
    }
    void set_img(const int i)
    {
        img=i;
    }
    int get_real() const
    {
        return real;
    }
    int get_img() const
    {
        return img;
    }
    void print() const
    {
        if(img>0)
        {
            cout<<real<<" + "<<img<<"i"<<endl;
        }
        else
        {
            cout<<real<<img<<"i"<<endl;
        }
    }
    void add(complex &x)
    {
        real=(x.real+real);
        img=(x.img+img);
    }
    //operator overloading
    void operator+(const complex &x)
    {
        real=(x.real+real);
        img=(x.img+img);
    }
    complex operator-(complex &x)
    {
        complex temp('f');
        temp.real=real-x.real;
        temp.img=img-x.img;
        return temp;
    }
    void operator=(const complex &x)
    {
        real=x.real;
        img=x.img;
    }
    void operator!()
    {
        img*=-1;
    }
    int operator[](string s)
    {
        if(s=="real")
        {
            return real;
        }
        else{
            return img;
        }
    }
    void operator=(complex &x)
    {
        real=x.real;
        img=x.img;
    }
};
istream& operator>>(istream &is,complex &x)
{
    int r1,i1;
    is>>r1>>i1;
    x.set_real(r1);
    x.set_img(i1);
    return is;
}
ostream& operator<<(ostream &ot,complex &x)
{
    if(x.get_img()>0)
    {
        ot<<x.get_real()<<" + "<<x.get_img()<<"i"<<endl;
    }
    else
    {
        ot<<x.get_real()<<x.get_img()<<"i"<<endl;
    }
    return ot;
}
int main() {
    complex c;
    c.set_real_img(10,20);
    cout<<"Complex No:-C"<<endl;
    c.print();
    complex d(13,12);
    cout<<endl<<"Complex No:-D"<<endl;
    d.print();
    cout<<endl<<"Adding C to D"<<endl;
   // c.add(d);
    c+d;
    c.print();
    !c;
    cout<<endl<<"After Negating the imaginary part"<<endl;
    c.print();
    cout<<"Real No="<<c["real"]<<" Img="<<c["img"]<<endl;
    complex y;
    cin>>y;
    cout<<endl<<"Complex Y:-"<<endl;
    cout<<y<<endl;
    //cout<<c-y<<endl;
    //cout<<t<<endl;
}
