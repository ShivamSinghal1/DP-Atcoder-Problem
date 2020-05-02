#include<bits/stdc++.h>
#define int long long
#define MAX 100001
#define MOD 1000000007
using namespace std;

 
int32_t main()
{
    int h,w;
    cin>>h>>w;
    char a[h][w];
    for(int i= 0;i<h;++i)
    {
        for(int j=0;j<w;++j)
        {
            cin>>a[i][j];
        }
    }

    int dp[h+1][w+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=h;++i)
    {
        for(int j=1;j<=w;++j)
        {
            if(i==1 and j==1)
                dp[i][j] = 1;
            else if(a[i-1][j-1] == '.')
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            else
                dp[i][j] = 0;
        }
    }

    cout<< dp[h][w] <<endl;

    return 0;
}