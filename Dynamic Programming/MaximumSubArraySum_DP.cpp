#include <iostream>
using namespace std;
//bottom up
int maxsum(int a[],int size)
{
    int dp[100]={0};
    dp[0]=(a[0]<0)?0:a[0];
    int MaxSoFar=dp[0];
    for(int i=1;i<size;i++)
    {
        dp[i]=dp[i-1]+a[i];
        if(dp[i]<0)
        {
            dp[i]=dp[i];
        }
        MaxSoFar=max(dp[i],MaxSoFar);
    }
    return MaxSoFar;
}
//space efficient max sum
int optimisedmaxsum(int *a,int size)
{
    int sum,maxsum;
    sum=maxsum=0;
    for(int i=0;i<size;i++)
    {
        sum+=a[i];
        if(sum<0)
        {
            sum=0;
        }
        maxsum=max(maxsum,sum);
    }
    return maxsum;
}
int main() {
    int arr[]={-3,2,5,-1,6,3,-2,7,-5,2};
    int size=sizeof(arr)/sizeof(int);
    cout<<optimisedmaxsum(arr,size)<<endl;
}