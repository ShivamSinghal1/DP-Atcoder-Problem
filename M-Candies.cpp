#include<bits/stdc++.h>
#define int long long
#define ld long double
#define MAX 100001
#define MOD 1000000007
using namespace std;

int permutation(int n, int k ,int*a )
{
    if(k==0)
        return 1;

    int dp[n+1][k+1];

    for(int i=0 ;i<=n ;++i)
    {
        for(int j=0;j<=k;++j)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 1;
                continue;
            }
            if(j - a[i-1]  > 0 )
                dp[i][j] = dp[i][j-1] + ( dp[i-1][j] - dp[i-1][j-a[i-1]-1] );
            else
                dp[i][j] = dp[i][j-1] + dp[i-1][j];

            dp[i][j]%=MOD;
        }
    }   

    return (dp[n][k] - dp[n][k-1]+MOD)%MOD;
}

 
int32_t main()
{
    int n,k;
    cin>>n>>k;
    int*a = new int[n];
    for(int i=0;i<n;++i)
        cin>>a[i];

    cout << permutation( n, k, a) << endl;

    return 0;
}