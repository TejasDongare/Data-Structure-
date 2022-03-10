#include<iostream>
using namespace std;
bool check(string a,string b)
{
	return a>b;
}
int main()
{
	string s[1000];
	int size;
	cin>>size;
	for(int i=0;i<size;i++)
	{
		cin>>s[i];
	}
	int min_index;
	for(int i=0;i<size;i++)
	{
		min_index=i;
		for(int j=i+1;j<size;j++)
		{
			if(check(s[min_index],s[j]))
			{
				min_index=j;
			}
		}
		swap(s[min_index],s[i]);
	}
	for(int i=0;i<size;i++)
	{
		cout<<s[i]<<endl;
	}
}