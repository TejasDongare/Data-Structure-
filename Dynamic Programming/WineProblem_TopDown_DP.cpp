#include <iostream>
using namespace std;
int winproblem(int prices[],int s,int e,int year,int dp[][100])
{
    if(s>e)
    {
        return 0;
    }
    
    //lookup
    if(!dp[s][e]==0)
    {
        return dp[s][e];
    }
    int op1=winproblem(prices,s+1,e,year+1,dp)+(year*prices[s]);
    int op2=winproblem(prices,s,e-1,year+1,dp)+(year*prices[e]);
    return dp[s][e]=max(op1,op2);
}
int main() 
{
    int Wines[]={2,3,5,1,4};
    int n=sizeof(Wines)/sizeof(int);
    int dp[100][100]={0};
    cout<<winproblem(Wines,0,n-1,1,dp)<<endl;
}