#include <iostream>
using namespace std;
int rodcutting(int *price,int *length,int size)
{
    int dp[100]={0};
    for(int i=1;i<=size;i++)
    {
        dp[i]=0;
        for(int j=0;j<size;j++)
        {
            if(i-length[j]>=0)
            {
                dp[i]=max(price[j]+dp[i-length[j]],dp[i]);
            }
        }
    }
    return dp[size];
}
int main() 
{
    int length[]={1,2,3,4,5,6,7,8};
    int price[]={3,5,8,9,10,17,17,20};
    int size=sizeof(length)/sizeof(int);
    int dp[100]={0};
    cout<<rodcutting(price,length,size)<<endl;
}
