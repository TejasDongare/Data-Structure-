#include <iostream>
#include<climits>
using namespace std;
//O(N*N)
int LongestIncreasingSubsequence(int *a,int size)
{
    int dp[size+1];
    for(int i=0;i<=size;i++)
    {
        dp[i]=INT_MAX;
    }
    dp[0]=INT_MIN;
    for(int i=0;i<size;i++)
    {
        for(int length=0;length<=size;length++)
        {
            if(dp[length]<a[i] and dp[length+1]>a[i]) dp[length+1]=a[i];
        }
    }
    int i;
    for(i=1;i<=size;i++)
    {
        if(dp[i]==INT_MAX)
        {
            return i-1;
        }
    }
    return i-1;
}
int main()
{
    int a[]={1,5,2,3,4,9,6,10};
    int size=sizeof(a)/sizeof(int);
    cout<<LongestIncreasingSubsequence(a,size);
}
