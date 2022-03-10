#include<iostream>
#include<climits>
using namespace std;
int knapsack(int *profit,int *weight,int size,int capacity)
{
	int dp[size+1][capacity+1];
	for(int i=0;i<=size;i++)
	{
		for(int j=0;j<=capacity;j++)
		{
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }
			else if(j>=weight[i-1])
			{
				dp[i][j]=max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
			}
            else
            {
			    dp[i][j]=dp[i-1][j];
            }
		}
	}
	return dp[size][capacity];
}
int main() 
{
    int size,capacity;
    cin>>size>>capacity;
    int profit[size];
    int weight[size];
    for(int i=0;i<size;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<size;i++)
    {
        cin>>profit[i];
    }
    int dp[1000+1][1000+1];
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<knapsack(profit,weight,size,capacity);
}