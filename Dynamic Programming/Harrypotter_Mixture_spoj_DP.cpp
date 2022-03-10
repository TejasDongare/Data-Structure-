#include <iostream>
#include<climits>
using namespace std;
long long int a[1000];
long long int dp[1000][1000];
long long cumsum(int s,int e)
{
    long long ans=0;
    for(int i=s;i<=e;i++)
    {
        ans+=a[i];
        ans%=100;
    }
    return ans;
}
long long int solveMixtures(int i,int j)
{
    //if only one element
    if(i>=j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<=j;k++)
    {
        dp[i][j]=min(dp[i][j],solveMixtures(i,k)+solveMixtures(k+1,j)+(cumsum(i,k)*cumsum(k+1,j)));
    }
    return dp[i][j];
}
int main() {
    int size;
    cin>>size;
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    cout<<solveMixtures(0,size-1)<<endl;
}
