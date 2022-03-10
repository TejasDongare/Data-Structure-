#include <iostream>
using namespace std;
int friendparing(int size)
{
    int dp[size+1]={-1};
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=size;i++)
    {
        dp[i]=dp[i-1]+((i-1)*dp[i-2]);
    }
    return dp[size];
}
int main() 
{
    int people;
    cin>>people;
    cout<<friendparing(people);
}