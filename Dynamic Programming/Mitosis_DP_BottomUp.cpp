#include <iostream>
using namespace std;
int mitosis(int size,int x,int y,int z)
{
    int dp[size+1]={0};
    for(int i=2;i<=size;i++)
    {
        if(i%2==0)
        {
            dp[i]=min(dp[i/2]+x,dp[i-1]+y);//as we dont know i+1 and i+1 is odd so i+1/2 !=integer so there is not way we can reach there
        }
        else
        {
            dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
        }
    }
    return dp[size];
}
int main() {
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<mitosis(n,x,y,z)<<endl;
}
