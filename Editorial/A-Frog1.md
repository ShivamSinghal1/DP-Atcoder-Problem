# Problem Statement

> [Problem Statement Link](https://atcoder.jp/contests/dp/tasks/dp_a)

## Here is the quick explanation

The problem states that there are stones(numbered from 1 to N) and their height h. The **Frog** initially at stone 1. He can move to **i+1** and **i+2** from a particular stone. When **Frog** make that move he incurred a cost **abs(hi-hj)**. Now we have to find the minimum total cost before **Frog** reaches **N**.

Let's take a sample input

**INPUT** 
```
4
10 30 40 20
```
**OUTPUT**
```
30
```
In this sample test case **Frog** moves **1->2->4**. When he makes jump from **1->2** he incurred a cost of **20** and when **2->4** he incurred a cost of **10**, and this sums up a total cost of **30**.

## Approach

```C++
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
```
In *min_cost* function we are taking the array and size of the array as parameter. Then we make a new DP array which gives the total minimum cost. We initialize *dp[0]* with *0* and *dp[1]* with absolute value of *h[1]-h[0]*, as if size of the array is **2** we just simply return *dp[1]*. Now in the for loop we are calculating our answer, we are taking the minimum of *i-1* step and *i-2* step. And finally return the value of *dp[n-1]* as we to calulate the total minimum possible cost just before **Frog** reaches **N**.