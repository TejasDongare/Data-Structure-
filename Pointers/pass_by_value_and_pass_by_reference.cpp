#include <iostream>
using namespace std;
void pass_value(int ans)
{
    ans=ans+1;
}
void pass_reference(int *ans)
{
    *ans=*ans+1;
}
int main() {
    int ans=10;
    pass_value(ans);
    cout<<"Value after adding but pass by value="<<ans<<endl;
    pass_reference(&ans);
    cout<<"Value after adding but pass by reference="<<ans<<endl;
}
