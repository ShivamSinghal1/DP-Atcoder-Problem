#include<bits/stdc++.h>
#define int long long
#define MAX 100001
using namespace std;
string LCS(string a,string b)
{
    int dp[a.size()+1][b.size()+1];
    memset(dp,0,sizeof(dp));
    char dp2[a.size()+1][b.size()+1];
    for(int i=1;i<=a.size();++i)
    {
        for(int j=1;j<=b.size();++j)
        {
            if(a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                dp2[i][j] = 'D';
            }
            else if(dp[i-1][j] > dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
                dp2[i][j] = 'U';
            }
            else
            {
                dp[i][j] = dp[i][j-1];
                dp2[i][j] = 'L';
            }
        }
    }
    int i=a.size(),j=b.size();
    string str= "";
    while(i!=0 && j!=0)
    {
        if(dp2[i][j] == 'D')
        {
            i--;
            j--;
            str += a[i];
        }
        else if(dp2[i][j] == 'U')
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(str.begin(),str.end());
    return str;
}
 
int32_t main()
{
    string a,b;
    cin>>a>>b;
 
    cout << LCS (a,b) <<endl;
    return 0;
}