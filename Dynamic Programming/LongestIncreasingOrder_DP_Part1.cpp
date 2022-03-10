#include <iostream>
using namespace std;
int LongestIncreasingSubsequence(int *a,int size)
{
    int j;
    int dp[size+1]={0};
    for(int i=0;i<size;i++)
    {
        int m=0;
        j=i-1;
        while(j>=0)
        {
            if(a[j]<a[i])
            {
                m=max(dp[j],m);
            }
            j--;
        }
        dp[i]=m+1;
    }
    return dp[size-1];
}
int main()