#include <iostream>
using namespace std;
int rodcutting(int *price,int *length,int remnaning,int size,int dp[])
{
    if(remnaning==0)
    {
        return 0;
    }
    if(dp[remnaning]!=0)
    {
        return dp[remnaning];
    }
    int max_price=0;
    int sum=0;
    for(int i=0;i<size;i++)
    {
        if(remnaning>=length[i])
        {
            sum=price[i]+rodcutting(price,length,remnaning-length[i],size,dp);
            max_price=max(max_price,sum);
        }
    }
    return dp[remnaning]=max_price;
}
int main() 
{
    int length[]={1,2,3,4,5,6,7,8};
    int price[]={3,5,8,9,10,17,17,20};
    int size=sizeof(length)/sizeof(int);
    int dp[100]={0};
    cout<<rodcutting(price,length,size,size,dp)<<endl;
}
