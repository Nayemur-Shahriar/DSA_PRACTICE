#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int knapsack(int n, int weight[], int value[], int W)
{
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (weight[n - 1] <= W)
    {
        int a = value[n - 1] + knapsack(n - 1, weight, value, W - weight[n - 1]);
        int b = knapsack(n - 1, weight, value, W);
        dp[n][W] = max(a,b);
    }
    else
    {
        dp[n][W] = knapsack(n - 1, weight, value, W);
    }

    return dp[n][W];
}

int main()
{
    int n = 4;
    int value[] = {60, 100, 120, 150};
    int weight[] = {10, 20, 30, 40};
    int W = 50;

    memset(dp, -1, sizeof(dp));

    int maxVal = knapsack(n, weight, value, W);
    cout << maxVal << endl;

    return 0;
}
