#include<bits/stdc++.h>
#define int long long
#define ld long double
#define MAX 100001
#define MOD 1000000007
using namespace std;

int sum[401][401],cost[401][401];

void min_cost (int s,int e, int*a )
{
    if(cost[s][e] != -1)
        return;
    if(s==e)
    {
        sum[s][e] = a[s];
        cost[s][e] = 0;
        return;
    }
    int minn = LLONG_MAX;
    for (int i = s; i < e ; ++i)
    {
        min_cost (s,i,a);
        min_cost (i+1,e,a);

        sum[s][e] = sum[s][i] + sum[i+1][e];
        minn = min ( minn , cost[s][i] + cost[i+1][e] + sum[s][e]);
    } 
    cost[s][e] = minn;
}

 
int32_t main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
            cin>>a[i];

    memset(cost,-1, sizeof(cost));

    min_cost (0,n-1,a);

    cout<< cost [0][n-1] << endl;


    return 0;
}