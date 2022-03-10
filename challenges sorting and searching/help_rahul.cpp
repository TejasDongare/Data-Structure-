#include<iostream>
using namespace std;
int binary_search(int a[],int key,int size)
{	
int start=0,end=size-1;
while(start<=end)
	{
		int m=(start+end)/2;
		if(a[m]==key)
		{
			return m;
		}
		if(a[m]>=a[start])
		{
			if(key>=a[start] and key<=a[m])
			{
				end=m-1;
			}
			else
			{
				start=m+1;
			}
		}
		else if(a[m]<=a[end])
		{
			if(a[m]<=a[end])
			{
				start=m+1;
			}
			else
			{
				end=m-1;
			}
		}
	}
	return -1;
}
int main()
{
	int size,a[100000];
	cin>>size;
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
	int key;
	cin>>key;
	cout<<binary_search(a,key,size);
}