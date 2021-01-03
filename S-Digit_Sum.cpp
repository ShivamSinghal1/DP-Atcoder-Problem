#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;
const int N = (int)1e4;

// Concept used: Digit DP

int dp[N][2][100];


int f(int ind, int is_tight, int sum_of_dig, string &k, int &d)
{

    sum_of_dig %= d;

    if(ind >= k.size())
        return ((sum_of_dig % d == 0) ? 1 : 0);

    if(dp[ind][is_tight][sum_of_dig] != -1)
        return dp[ind][is_tight][sum_of_dig];

    int ans = 0;
    int curr_dig = k[ind] - '0';
    
    if(is_tight)
    {
        for(int i = 0; i <= curr_dig; i++)
        {
            if(i == curr_dig)
                ans += f(ind + 1, 1, i + sum_of_dig, k, d);
            else
                ans += f(ind + 1, 0, i + sum_of_dig, k, d);
            ans %= M;
        }
    }
    else
    {
        for(int i = 0; i <= 9; i++)
        {
            ans += f(ind + 1, 0, i + sum_of_dig, k, d);
            ans %= M;
        }
    }
    return dp[ind][is_tight][sum_of_dig] = ans % M;
}


int32_t main()
{
    string k;
    int d;
    cin >> k >> d;
    memset(dp, -1, sizeof(dp));
    
    cout << (f(0, 1, 0, k, d) - 1 + M) % M;
    // subtracting 1 because '0' would have been counted as an answer too
}
