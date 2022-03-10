#include<iostream>
#include<climits>
using namespace std;
int knapsack(int *value,int *capacity,int i,int size,int bag_capacity,int dp[1001][1001])
{
	if(bag_capacity==0 or i==size)
	{
		return 0;
	}
	if(dp[i][bag_capacity]!=-1)
	{
		return dp[i][bag_capacity];
	}
	int option1=knapsack(value,capacity,i+1,size,bag_capacity,dp);//without taking it
	int option2=INT_MIN;
	if(bag_capacity>=capacity[i])
	{
		option2=value[i]+knapsack(value,capacity,i+1,size,bag_capacity-capacity[i],dp);
	}
	return dp[i][bag_capacity]=max(option1,option2);
}
int mainbb() 
{
    int size,bag_capacity;
    cin>>size>>bag_capacity;
    int value[size];
    int capacity[size];
    for(int i=0;i<size;i++)
    {
        cin>>capacity[i];
    }
    for(int i=0;i<size;i++)
    {
        cin>>value[i];
    }
    int dp[1000+1][1000+1];
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<knapsack(value,capacity,0,size,bag_capacity,dp);
}