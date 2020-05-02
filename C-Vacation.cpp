#include<bits/stdc++.h>
using namespace std;

int max_points(int a[][3] , int n )
{
    int dp[n][3];
    //Base Case
    for(int i=0; i<3 ;++i)
        dp[0][i] = a[0][i];

    for(int i=1 ; i<n; ++i)
    {
        for(int j =0 ;j<3 ; ++j)
        {
            dp[i][j] = 0;
            for(int k = 0 ;k<3 ;++k)
                if(j!=k)
                    dp[i][j] = max(dp[i][j] ,
                                dp[i-1][k] + a[i][j]);
        }
    }

    return max ({dp[n-1][0] , dp[n-1][1] , dp[n-1][2] });
} 

int main()
{
    int n;
    cin>>n;
    int a[n][3];
    for(int i = 0 ;i<n ;++i)
        for(int j =0 ; j<3 ; ++j)
            cin>>a[i][j];

    cout << max_points (a,n) <<endl;
    return 0;
}