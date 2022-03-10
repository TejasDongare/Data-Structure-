#include<iostream>
using namespace std;
bool solve(int s,int c,int a[],int mid)
{
	int placed=1,sum=0;
	for(int i=1;i<s;i++)
	{
		if(sum+a[i]-a[i-1]>=mid)
		{
			sum=0;
			placed++;
		}
		else
		{
			sum+=a[i]-a[i-1];
		}
	}
	if(placed>=c)
	{
		return true;
	}
	return false;
}
int main()
{
  int s,c,stalls[100000];
  cin>>s>>c;
  for(int i=0;i<s;i++)
  {
  	cin>>stalls[i];
  }
  sort(stalls,stalls+s);
  int start=0, end=stalls[s-1]-1,ans;
  while(start<=end)
  {
  	int mid=(start+end)/2;
  	if(solve(s,c,stalls,mid))
  	{
  		start = mid+1;
  		ans=mid;
  	}
  	else
  	{
  		end=mid-1;
  	}
  }
  cout<<ans<<endl;
}