#include<bits/stdc++.h>
#define int long long
#define ld long double
#define MAX 100001
#define MOD 1000000007
using namespace std;

bool play(int n,int k, int a[])
{
    bool dp[n][k+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=k;++i)
    {
        bool flag = 0;
        for(int j=0 ;j<n;++j)
        {
            if(a[j] > i)
                continue;

            dp[j][i] = dp[j][i-a[j]]^1;
            flag += dp[j][i];

            if(flag)
                break;
        }
        if(flag)
            for(int j=0;j<n;++j)
                dp[j][i] = 1;
    }

    return dp[0][k];
}

 
int32_t main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];

    int player = play(n,k,a);

    if(player)
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;

    return 0;
}