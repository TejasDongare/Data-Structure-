#include<iostream>
#include<climits>
using namespace std;
//top down coin change by greedy approach only works for indian currency but for other currency it wont work example {1,7,10} and to make change of 15 
int coin_change(int coins[],int change,int size,int *dp)
{
    if(change==0)
    {
        return 0;
    }
    if(dp[change]!=0)
    {
        return dp[change];
    }
    int ans=INT_MAX;
    for(int i=0;i<size;i++)
    {
        if(coins[i]<=change)
        {
            int temp=coin_change(coins,change-coins[i],size,dp);
            ans=min(ans,temp);
        }
        else
        {
            break;
        }
    }
    return dp[change]=ans+1;
}
int main()
{
    int coins[]={1,7,10};
    int dp[1000]={0};
    cout<<coin_change(coins,15,3,dp);
}