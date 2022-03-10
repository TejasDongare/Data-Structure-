#include <iostream>
using namespace std;
int elephantinchess(int row,int column)
{
    int dp[row+1][column+1];
    int rowsum[row+1][column+1];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(i==0 and j==0)
            {
                dp[i][j]=1;
            }
            else if(i==0)
            {
                int sum=0;
                for(int temp=0;temp<=j-1;temp++)
                {
                    sum+=dp[i][temp];
                }
                dp[i][j]=sum;
            }
            else if(j==0)
            {
                int sum=0;
                for(int temp=0;temp<=i-1;temp++)
                {
                    sum+=dp[temp][j];
                }
                dp[i][j]=sum;
            }
            else
            {
                int r=0,c=0;
                for(int temp=0;temp<=j-1;temp++)
                {
                    r+=dp[i][temp];
                }
                for(int temp=0;temp<=i-1;temp++)
                {
                    c+=dp[temp][j];
                }
                
                dp[i][j]=r+c;
            }
        }
    }
    return dp[row-1][column-1];
}
int main() 
{
    cout<<elephantinchess(3,5)<<endl;
}