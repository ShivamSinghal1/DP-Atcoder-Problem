#include<bits/stdc++.h>
using namespace std;

int min_cost(int* h , int n)
{
    int*dp = new int[n];
    //Base Case
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i=2 ; i<n; ++i)
        dp[i] = min( dp[i-1] + abs(h[i] - h[i-1]) ,
                    dp[i-2] + abs(h[i] - h[i-2]));
    return dp[n-1];
} 

int main()
{
    int n;
    cin>>n;
    int* h = new int[n];
    for(int i = 0 ;i<n ;++i)
        cin>>h[i];
    cout << min_cost (h,n) <<endl;
    return 0;
}