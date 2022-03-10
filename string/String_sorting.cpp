#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
bool compare(string a,string b)
{
    if(a.length()==b.length())
    {
        return a<b;
    }
    return a.length()>b.length();
}
int main() {
    string s[100];
    int n;
    cout<<"Enter the Number of strings to be enetered"<<endl;
    cin>>n;
    cin.get();//in input buffer after pressing enter \n a=also should be consumed
    for(int i=0;i<n;i++)
    {
        getline(cin,s[i]);
    }
    sort(s,s+n,compare);
    cout<<"Sorted array is "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }

}
