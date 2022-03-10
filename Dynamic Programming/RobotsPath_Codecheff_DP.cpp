#include <iostream>
using namespace std;
int solve(int dp[][100],int row,int column)
{
    if(dp[0][0]==-1)
    {
        return 0;
    }
    for(int i=0;i<column;i++)
    {
        if(dp[0][i]==-1)
        {
            break;
        }
        dp[0][i]=1;
    }
    for(int i=0;i<row;i++)
    {
        if(dp[i][0]==-1)
        {
            break;
        }
        dp[i][0]=1;
    }
    //bottom up apporach
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<column;j++)
        {
            if(dp[i][j]==-1)
            {
                continue;
            }
            dp[i][j]=0;
            if(dp[i][j-1]!=-1)
            {
                dp[i][j]=(dp[i][j-1])%1000007;
            }
            if(dp[i-1][j]!=-1)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j])%1000007;
            }
        }
    }
    if(dp[row-1][column-1]==-1)
    {
        return 0;
    }
    return dp[row-1][column-1];
}
int main() 
{
    int dp[100][100];
    int row,column,p;
    cin>>row>>column>>p;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            dp[i][j]=0;
        }
    }
    for(int i=0;i<p;i++)
    {
        int x,y;
        cin>>x>>y;
        dp[x-1][y-1]=-1;
    }
    cout<<solve(dp,row,column)<<endl;
}