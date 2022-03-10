#include <iostream>
using namespace std;
int OptimalGameStrategy(int dp[][100],int i,int j,int *a)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int op1=OptimalGameStrategy(dp,i+2,j,a);
    int op2=OptimalGameStrategy(dp,i+1,j-1,a);
    int ans1=a[i]+min(op1,op2);
    op1=OptimalGameStrategy(dp,i,j-2,a);
    op2=OptimalGameStrategy(dp,i+1,j-1,a);
    int ans2=a[j]+min(op1,op2);
    return max(ans1,ans2);
    
}
int main() {
    int arr1[] = {20, 30, 2, 2, 2, 10}; 
    int n = sizeof(arr1) / sizeof(arr1[0]); 
    int dp[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<OptimalGameStrategy(dp,0,n-1,arr1)<<endl;
}