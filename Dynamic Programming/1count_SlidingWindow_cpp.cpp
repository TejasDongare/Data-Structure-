#include<iostream>
#include<climits>
using namespace std;
//flip the number of zero at most k to find max consecutive 1 
int MaxSubarrayByFlipping0(int *a,int size,int flips)
{
    int l=0,r=0;
    int zero_count=0;
    int max_size=INT_MIN;
    for(r=0;r<size;r++)
    {
        if(a[r]==0)
        {
            zero_count++;
        }
        while(zero_count>flips)
        {
            if(a[l]==0)
            {
                zero_count--;
            }
            l++;
        }
        max_size=max(max_size,r-l+1);
    }
    return max_size;
}
int main()
{
    int size,flips;
    cin>>size>>flips;
    int a[size];
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    cout<<MaxSubarrayByFlipping0(a,size,flips)<<endl;
}