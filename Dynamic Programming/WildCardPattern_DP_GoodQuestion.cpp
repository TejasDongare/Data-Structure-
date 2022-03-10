#include <iostream>
using namespace std;
bool WildCardPattern(string pattern,string str)
{
    bool dp[pattern.length()+1][str.length()+1];
    for(int i=0;i<=pattern.length();i++)
    {
        for(int j=0;j<=str.length();j++)
        {
            dp[i][j]=0;
        }
    }
    dp[pattern.length()][str.length()]=1;
    for(int i=pattern.length()-1;i>=0;i--)
    {
        for(int j=str.length()-1;j>=0;j--)
        {
            if(pattern[i]==str[j])
            {
                dp[i][j]=dp[i+1][j+1];
            }
            else if(pattern[i]=='?')
            {
                dp[i][j]=dp[i+1][j+1];
            }
            else if(pattern[i]=='*')
            {
                int flag=0;
                for(int temp=j;temp<=str.length();temp++)
                {
                    if(dp[i+1][temp]==1)
                    {
                        flag=1;
                        break;
                    }
                }
                dp[i][j]=flag;
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    return dp[0][0];
}
int main()
{
    string str,wildpattern;
    cin>>str>>wildpattern;
    cout<<WildCardPattern(wildpattern,str)<<endl;
}