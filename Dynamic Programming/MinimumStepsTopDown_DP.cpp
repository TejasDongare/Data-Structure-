#include <iostream>
#include<climits>
using namespace std;
//top down approach
int min_steps(int n,int *dp)
{
    if(n==1)
    {
        return 0;
    }
    int a,b,c,final_ans;
    a=b=c=INT_MAX;
    if(n%2==0)
    {
        a=min_steps(n/2,dp)+1;
    }
    if(n%3==0)
    {
        b=min_steps(n/3,dp)+1;
    }
    c=min_steps(n-1,dp)+1;
    return dp[n]=min(a,min(b,c));
}
int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    cout<<min_steps(n,dp);
}