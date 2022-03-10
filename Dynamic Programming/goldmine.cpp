#include<iostream>
#include<climits>
using namespace std;
int a[1000][1000];
int dp[1000][1000];
int MaxGold(int r,int c)
{
	int maxans=INT_MIN;
	for(int col=c-1;col>=0;col--)
	{
		for(int row=0;row<r;row++)
		{
			int op1=0,op2=0,op3=0;
			if(row-1>=0)
			{
				op1=dp[row-1][col+1];
			}
			if(col+1!=c)
			{
				op2=dp[row][col+1];
			}
			if(row+1<r)
			{
				op3=dp[row+1][col+1];
			}
			dp[row][col]=max(op1,max(op2,op3))+a[row][col];
			maxans=max(maxans,dp[row][col]);
		}
	}
	return maxans;
}
int main()
{
	int r,c;
	cin>>r>>c;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
			dp[i][j]=0;
		}
	}
	cout<<MaxGold(r,c);
}