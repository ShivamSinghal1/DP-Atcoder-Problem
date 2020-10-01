# Problem Statement

> [Problem Statement Link](https://atcoder.jp/contests/dp/tasks/dp_b)

## Here is the quick explanation

The problem states that there are stones(numbered from 1 to N) and their height h. The **Frog** initially at stone 1. He can move either to **i+1** ,**i+2** upto **i+k** stone from a particular stone. When **Frog** make that move he incurred a cost **abs(hi-hj)**. Now we have to find the minimum total cost before **Frog** reaches **N**.

Let's take a sample input

**INPUT** 
```
5 3
10 30 40 50 20
```
**OUTPUT**
```
30
```
In this sample test case **Frog** moves **1->2->5**. When he makes jump from **1->2** he incurred a cost of **20** and when **2->5** he incurred a cost of **10**, and this sums up a total cost of **30**.

## Approach

```C++
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
```
In *min_cost* function we are taking the array, size of the array and atMax steps as parameter. Then we make a new DP array which gives the total minimum cost. We initialize *dp[0]* with *0*. Now in the for loop we are calculating our answer, we are initialzing the **dp[i]** with maximum value possible. Then we are starting a for loop that starts with maximum of 0 and **i-k**, and then we are setting **dp[i]** taking the minimum of *dp[i]* and *dp[j] + abs(h[i] - h[j])* step. The second for loop we used is to check at which stone frog should move to minimise the cost. And finally return the value of *dp[n-1]* as we to calulate the total minimum possible cost just before **Frog** reaches **N**.