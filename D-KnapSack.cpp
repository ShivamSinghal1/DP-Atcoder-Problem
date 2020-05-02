#include<bits/stdc++.h>
#define int long long
using namespace std;
// KnapSack
int max_value(int N, int W, int*w , int* v)
{
    int dp[N+1][W+1];
    memset(dp,0,sizeof(dp));
    for(int i= 0 ;i<N ; ++i)
    {
        for(int j = 0 ;j<=W ; ++j)
        {
            dp[i+1][j] = max(dp[i+1][j] , dp[i][j]);
            if(j >= w[i])
                dp[i+1][j]  = max(dp[i+1][j] ,
                                dp[i][j-w[i]] + v[i]);
        }
    }
    return dp[N][W];
} 

int32_t main()
{
    int N,W;
    cin>>N>>W;
    int w[N],v[N];
    for(int i = 0 ;i<N ;++i)
        cin>>w[i]>>v[i];

    cout << max_value(N,W,w,v) <<endl;
    return 0;
}