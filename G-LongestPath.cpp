#include<bits/stdc++.h>
#define int long long
#define MAX 100001
using namespace std;

vector<vector<int>> v;
vector<int> dp;

void dfs(int source)
{    
    int maxx = -1;
    for(auto i:v[source])
    {
        if(dp[i] == -1)
            dfs(i);
        maxx = max(maxx , dp[i]);
    }
    dp[source] = maxx+1;
    return;
}

 
int32_t main()
{
    int n,m;
    cin>>n>>m;
    v.resize(n);
    
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x-1].push_back(y-1);
    }

    dp.resize(n);
    fill(dp.begin() , dp.end() , -1);

    int maxx = 0;
    for(int i=0;i<n;++i)
    {
        if(dp[i] == -1)
            dfs(i);
        maxx = max(maxx, dp[i]);
    }

    cout<<maxx<<endl;

    return 0;
}