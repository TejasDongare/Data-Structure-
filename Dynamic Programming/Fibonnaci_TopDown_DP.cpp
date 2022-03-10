#include <iostream>
using namespace std;
//top down approach
int fibonnacci(int n,int dp[])
{
    if(n==0 or n==1)
    {
        return n;
    }
    return dp[n]=fibonnacci(n-1,dp)+fibonnacci(n-2,dp);
}
int main() 
{
    int *dp;
    int n;
    cin>>n;
    dp=new int[n+1];
    cout<<fibonnacci(n,dp);
}
