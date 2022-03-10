#include<iostream>
using namespace std;
bool solve(int s,int c,int x,int y,int m)
{
	int coupens=((s-m)*y)+(c);
	if(coupens>=(s*x))
	{
		return true;
	}
	return false;
}
int main()
{
	int s,c,x,y,ans;
	cin>>s>>c>>x>>y;
	int start=0,end=s*x;
	while(start<=end)
	{
		int m=(start+end)/2;
		if(solve(s,c,x,y,m))
		{
			start=m+1;
			ans=m;
		}
		else
		{
			end=m-1;
		}
	}
	cout<<ans<<endl;
}