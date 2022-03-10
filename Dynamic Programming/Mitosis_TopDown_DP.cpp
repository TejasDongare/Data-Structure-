#include <bits/stdc++.h>
using namespace std;
#define Fast_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
int n,x,y,z;
const int N = 1e5+3;
int dp[N];
int cost(int n){
    //Base Cases
    if(n==0 or n==1)
        return 0;
    if(n==2)
        return min(x,y);
    
    //If already precomputed
    if(~dp[n])
        return dp[n];
    
    //Main calculation part
    int ans = cost(n-1)+y;
    if(n%2==0)  
        ans = min(cost(n/2)+x,ans);
    else
        ans=min(ans,cost((n+1)/2)+z+x);

    //return the ans and save it for future
    return dp[n] = ans;
}

int32_t main(){    
    Fast_IO
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w",stdout);
    #endif
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cin>>x>>y>>z;
    cout<<cost(n);
}