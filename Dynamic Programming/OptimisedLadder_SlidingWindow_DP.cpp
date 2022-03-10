#include <iostream>
using namespace std;
int optimisedladder(int n,int k)
{
    int dp[100]={0};
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=2*dp[i-1];
        if(i-k-1>=0)
        {
            dp[i]=dp[i]-dp[i-k-1];
        }
    }
    return dp[n];
}
int main() 
{
    int n,k;
    cin>>n>>k;
    cout<<optimisedladder(n,k)<<endl;
}
