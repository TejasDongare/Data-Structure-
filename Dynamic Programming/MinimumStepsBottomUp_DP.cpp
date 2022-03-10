#include <iostream>
#include<climits>
using namespace std;
//Bottom Up Approach
int min_steps(int n)
{
    int dp[100];
    dp[0]=dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        if(i%2==0)
        {
            op1=dp[i/2];
        }
        if(i%3==0 )
        {
            op2=dp[i/3];
        }
        op3=dp[i-1];
        dp[i]=min(op1,min(op2,op3))+1;
    }
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    cout<<min_steps(n);
}
