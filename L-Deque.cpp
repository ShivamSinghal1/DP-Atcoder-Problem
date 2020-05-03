#include<bits/stdc++.h>
#define int long long
#define ld long double
#define MAX 100001
#define MOD 1000000007
using namespace std;

int dp[3001][3001][2];

void play(int s,int e,int turn,int* a)
{
    if(dp[s][e][turn] != -1)
        return;
    if(s==e)
    {
        dp[s][e][turn] = a[s];
        dp[s][e][turn^1] = 0;
        return;
    }
    play(s+1,e,turn^1 , a);
    play(s,e-1,turn^1 , a);

    if(dp[s+1][e][turn] + a[s] > dp[s][e-1][turn] + a[e])
    {
        dp[s][e][turn] = dp[s+1][e][turn] + a[s];
        dp[s][e][turn^1] = dp[s+1][e][turn^1];
    }
    else
    {
        dp[s][e][turn] = dp[s][e-1][turn] + a[e];
        dp[s][e][turn^1] = dp[s][e-1][turn^1];
    }
    return;
}

 
int32_t main()
{
    int n;
    cin>>n;
    int*a = new int[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));

    play(0,n-1,0,a);

    cout<< dp[0][n-1][0] - dp[0][n-1][1] <<endl;


    return 0;
}