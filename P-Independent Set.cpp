#include<bits/stdc++.h>
#define int long long
#define ld long double
#define MAX 100001
#define MOD 1000000007
#define pii pair<long long , long long >
using namespace std;

vector<vector<int>> adj_list;

pii ways (int source , int parent = -1)
{
    int d=1,w=1;
    for(auto i:adj_list[source])
    {
        if(i != parent)
        {
            pii temp = ways(i,source);
            d = (d * temp.second)%MOD;
            w = (w * ((temp.first + temp.second)%MOD) )%MOD; 
        }
    }

    return {d,w};
}

 
int32_t main()
{
    int n;
    cin>>n;
    adj_list.resize(n);

    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        adj_list[x-1].push_back(y-1);
        adj_list[y-1].push_back(x-1);
    }

    pii ans = ways(0, -1);

    cout<< ((ans.first + ans.second)%MOD) <<endl;


    return 0;
}