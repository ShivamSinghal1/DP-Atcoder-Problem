#include<bits/stdc++.h>
using namespace std;

int min_cost(int* h , int n , int k)
{
    int*dp = new int[n];
    //Base Case
    dp[0] = 0;

    for(int i=1 ; i<n; ++i)
    {
        dp[i] = INT_MAX;
        for(int j = max(0 , i-k) ; j<i ; ++j)

            dp[i] = min( dp[i], 
                    dp[j] + abs(h[i] - h[j]));
    }
    return dp[n-1];
} 

int main()
{
    int n,k;
    cin>>n>>k;
    int* h = new int[n];
    for(int i = 0 ;i<n ;++i)
        cin>>h[i];
    cout << min_cost (h,n,k) <<endl;
    return 0;
}