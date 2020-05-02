#include<bits/stdc++.h>
#define int long long
#define MAX 100001
using namespace std;
// KnapSack
int max_value(int N, int W, int*w , int* v)
{
    int dp[N+1][MAX];
    for(int i= 0 ;i<=N ; ++i)
    {
        for(int j = 0 ;j<MAX ; ++j)
        {
            if(j==0){
                dp[i][j] = 0;
                continue;
            }
            if(i==0){
                dp[i][j] = INT_MAX;
                continue;
            }
            dp[i][j] = dp[i-1][j];
            if(j >= v[i-1])
                dp[i][j]  = min(dp[i][j] ,
                                dp[i-1][j-v[i-1]] + w[i-1]);
        }
    }
    for(int j=MAX-1; j>=0 ; --j)
    {
        if(dp[N][j] <=W)
            return j;
    }
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