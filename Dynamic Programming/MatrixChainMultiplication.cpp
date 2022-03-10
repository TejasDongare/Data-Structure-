#include <iostream>
#include<climits>
using namespace std;
int MatrixChainMuliplication(int *arr,int size)
{
    int s=size-1;//this is beacuse for N matrix there are N+1 dimensions sp total maatrix will be total Number of Dimension given - 1   
    int dp[size][size];
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            dp[i][j]=0;
        }
    }
    int row,column;
    for(int gap=1;gap<s;gap++)
    {
        for(row=0,column=gap;column<s;row++,column++)
        {
            int ans=INT_MAX;
            for(int k=row;k<column;k++)
            {
                ans=min((dp[row][k]+dp[k+1][column])+(arr[row]*arr[k+1]*arr[column+1]),ans);
            }
            dp[row][column]=ans;
        }
    }
    return dp[0][s-1];
}
int main() 
{
    int a[]={4,2,3,1,3};
    int size=sizeof(a)/sizeof(int);
    cout<<MatrixChainMuliplication(a,size)<<endl;
}