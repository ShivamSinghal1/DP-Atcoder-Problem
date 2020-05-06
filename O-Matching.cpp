#include<bits/stdc++.h>
#define int long long
#define ld long double
#define MAX 100001
#define MOD 1000000007
using namespace std;

 
int32_t main()
{
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>a[i][j];

    int dp [(1<<n)] = {0};

    dp[0] = 1;



    // Base Case

    for (int i = 1; i < (1<<n); i++) 
    {
        int cnt = __builtin_popcount(i);
        for(int j=0;j<n;++j) 
        {
            if (i&(1<<j)) {

                dp[i] =  ( dp[i]  + ( dp[i^(1<<j)]*a[cnt-1][j]) ) %MOD;

            }
        }
    }

    cout << dp[(1<<n)-1];


    return 0;
}