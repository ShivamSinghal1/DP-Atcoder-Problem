#include<bits/stdc++.h>
#define int long long
#define ld long double
#define MAX 100001
#define MOD 1000000007
#define pii pair<long long , long long >
using namespace std;

vector<int> a,tree;
int type(int temp1, int temp2)
{
    // Change this type according to the question
    // Example - max , min, sum 
    return max(temp1 , temp2);
}
void build(int s =0,int e = a.size()-1, int treeNode = 1)
{
    if(s==e)
    {
        tree[treeNode]=a[s];
        return;
    }
    int mid=(s+e)/2;
    build(s,mid,2*treeNode);
    build(mid+1,e,2*treeNode+1);
    tree[treeNode] = type(tree[2*treeNode] , tree[2*treeNode + 1]);
}
void update(int pos, int val ,int s = 0,int e = a.size()-1,int treeNode = 1)
{
    if(s==e)
    {
        a[pos]=val;
        tree[treeNode]=val;
        return ;
    }
    int mid=(s+e)/2;
    if(pos<=mid)
        update(pos, val, s, mid, 2*treeNode);
    else
        update(pos, val, mid+1, e, 2*treeNode+1);
    tree[treeNode] = type(tree[2*treeNode] , tree[2*treeNode + 1]);
}
int query(int l, int r, int s=0, int e=a.size()-1, int treeNode = 1)
{
    if(s>r||e<l)
        return 0;
    if(s>=l&&e<=r)
        return tree[treeNode];
    int mid=(s+e)/2;
    int left_result = query(l, r, s, mid, 2*treeNode) ;
    int right_result = + query(l, r, mid+1, e, 2*treeNode+1);
    return  type(left_result ,right_result);
}
 
int32_t main()
{
    int n;
    cin>>n;
    int h[n],arr[n];
    for(int i=0;i<n;++i)
        cin>>h[i];
    for(int i=0;i<n;++i)
        cin>>arr[i];

    a.resize(n);
    tree.resize(4*n+5);
    fill(a.begin(),a.end(),0);
    build();

    for(int i=0;i<n;++i)
    {
        if(h[i]==1)
        {
            update(0,arr[i]);
            continue;
        }
        //cout<<query(0,h[i]-2)<<endl;
        update(h[i]-1 , query(0,h[i]-2)+arr[i]);
    }

    cout << *max_element(a.begin(),a.end()) <<endl ;
    
    return 0;
}






