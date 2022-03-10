#include <iostream>
#include<algorithm>
#include<climits>
using namespace std;
//O(Nlogn)
int LongestIncreasingSubsequence(int *a,int size)
{
    int dp[size];
    for(int i=0;i<size;i++)
    {
        dp[i]=INT_MAX;
    }
    for(int i=0;i<size;i++)
    {
        //upper bound takes logn complexity
        int length=upper_bound(dp,dp+size+1,a[i])-dp;//this will give the index
        //this condition is to check if no duplicates as we want stricly greater elemens
        if(length==0 or dp[length-1]!=a[i])
        {
            dp[length]=a[i];
        }
    }
    int i;
    for(i=0;i<size;i++)
    {  
        if(dp[i]==INT_MAX)
        {
            return i;
        }
    }
    return i;
}
int main()
{
    int a[]={1,5,2,3,9,9,6,9,10,10};
    int size=sizeof(a)/sizeof(int);
    cout<<LongestIncreasingSubsequence(a,size);
}
