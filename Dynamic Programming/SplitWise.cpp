#include <iostream>
#include<set>
#include<unordered_map>
using namespace std;
class compartor
{
public:
    bool operator()(pair<string,int> a,pair<string,int > b)
    {
        return a.second<b.second;
    }
};
void splitwise()
{
    int transactions;
    cin>>transactions;
    unordered_map<string,int> m;
    while(transactions--)
    {
        string x,y;
        int amount;
        cin>>x>>y>>amount;
        if(m.count(x)==0)
        {
            m[x]=0;
        }
        if(m.count(y)==0)
        {
            m[y]=0;
        }
        m[x]-=amount;
        m[y]+=amount;
    }
    multiset<pair<string,int>,compartor> p;
    for(auto x:m)
    {
        if(x.second!=0)
        {
            //cout<<x.first<<" "<<x.second<<endl;
            p.insert(x);
        }
    } 
    //settlements
    while(!p.empty())
    {
        auto b=p.begin();
        auto e=prev(p.end());
        int settled=min(-b->second,e->second);
        int debited=b->second;
        int credited=e->second;
        cout<<b->first<<" pays "<<(settled)<<" To "<<e->first<<endl;
        debited=debited+settled;//debited will be negative so after adding it will be right
        credited=credited-settled;//settled contains negative value so - - will make +
        string debited_name=b->first;
        string credited_name=e->first;
         p.erase(b);
         p.erase(e);
         if(debited!=0)
         {
             p.insert({debited_name,debited});
         }
         if(credited!=0)
         {
             p.insert({credited_name,credited});
         }
    }
}
int main() 
{  
    splitwise();
}
