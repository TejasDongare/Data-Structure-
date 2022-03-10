#include <iostream>
using namespace std;
int main() 
{
    int size;
    cin>>size;
    int dp[size+1]={0};
    dp[1]=1;
    for(int i=2;i<=size;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[size]<<endl;
}
