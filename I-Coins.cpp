#include<bits/stdc++.h>
#define int long long
#define ld long double
#define MAX 100001
#define MOD 1000000007
using namespace std;

ld probability(int n,ld p[] )
{
    int max_tail = n/2 ;

    ld dp[max_tail+1];

    memset(dp , (ld)0 , sizeof(dp));

    dp[0] = (ld)1;

    for(int i=0;i<n;++i)
    {
        
        for(int j=max_tail ;j > 0; --j)
        {
            dp[j] *= p[i];
            dp[j] += dp[j-1]*(1-p[i]);
        }
        dp[0] = dp[0]*p[i];
    }

    ld sum = 0;

    for(int j=0;j<=max_tail;++j)
    {
        sum += dp[j];
    }

    return sum;
}

 
int32_t main()
{
    int n;
    cin>>n;
    ld p[n];
    for(int i=0;i<n;++i)
        cin>>p[i];

    cout << fixed << setprecision(10) << probability(n,p) <<endl;

    return 0;
}