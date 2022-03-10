#include <iostream>
using namespace std;
int dp[1005][100020];
bool SubsetSum(int i,int size,int *arr,int target)
{
    if(target==0)
    {
        return 1;
    }
    if(target>0 and i>=size)
    {
        return 0;
    }
    if(dp[i][target]!=-1)
    {
        return dp[i][target];
    }
    //Two option to take or not to take
    if(arr[i]>target)
    {
        return dp[i][target]=SubsetSum(i+1,size,arr,target);
    }
    return dp[i][target]=SubsetSum(i+1,size,arr,target) || SubsetSum(i+1,size,arr,target-arr[i]);
}
bool SubsetSum_BottomUp(int size,int *arr,int sum)
{
    //int dp[size+1][sum+1];
    for(int i=0;i<=size;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0 and j==0)
            {
                dp[i][j]=1;
            }
            else if(i==0)
            {
                dp[i][j]=0;
            }
            else if(j==0)
            {
                dp[i][j]=1;
            }
            else if(j>=arr[i-1])
            {
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            }
            else if(j<arr[i-1])
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[size][sum];
}
int main() 
{
    int size,target;
    cin>>size>>target;
    int a[target];
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=size;i++)
    {
        for(int j=0;j<=target;j++)
        {
            dp[i][j]=-1;
        }
    }
   // cout<<SubsetSum(0,size,a,target)<<endl;
   if(SubsetSum_BottomUp(size,a,target))
   {
       cout<<"Yes"<<endl;
   }
   else{
       cout<<"No"<<endl;
   }
}
