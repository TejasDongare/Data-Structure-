#include<iostream>
using namespace std; 
bool  solve(long long int mid,long long int n ,long long int k)
{
    long long int prod=1;
	for(int i=1;i<=k;i++)
	{
		//cout<<"prod="<<prod<<" mid="<<mid<<endl;
		if(prod*mid<=n and prod>=0)
		{
			prod*=mid;
		}
		else
		{
			return false;
		}
	}
	return true;
}
int main()
{
	long long  int start,end,ans,n;
	int k,test_cases;
	cin>>test_cases;
	while(test_cases>0)
	{
	cin>>n>>k;
    start=0;
    end=n;
    while(start<=end)
    {
    	long long int mid= (start+end)/2;
    	if(solve(mid,n,k))
    	{
    		//cout<<" True"<<endl;
    		ans=mid;
    		start=mid+1;
    	}
    	else
    	{
    		//cout<<" FALSE"<<endl;
    		end=mid-1;
    	}
      }
      cout<<ans<<endl;
      test_cases--;
	}
}