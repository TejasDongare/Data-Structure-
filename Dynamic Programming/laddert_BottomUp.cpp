#include <iostream>
using namespace std;
int ladder_BottomUp(int n,int k)
{
    int dp[100]={0};
    dp[0]=1;
    for(int t=1;t<=n;t++)
    {
        int sum=0;
        for(int j=1;j<=k;j++)
        {
            if(t-j>=0)
            {
                sum+=dp[t-j];
            }
        }
        dp[t]=sum;
    }
    return dp[n];
}
int main() 
{
    int n,k;
    cin>>n>>k;
    cout<<ladder_BottomUp(n,k)<<endl;
}
