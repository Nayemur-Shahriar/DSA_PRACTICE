
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int weight[] = {10, 20, 30, 40};
    int value[]  = {60, 100, 120, 150};
    int n = sizeof(weight) / sizeof(weight[0]);

    int W;
    cin >> W;

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weight[i - 1] <= j)
            {
                int op1 = dp[i - 1][j - weight[i - 1]] + value[i - 1];
                int op2 = dp[i - 1][j];
                dp[i][j] = max(op1, op2);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][W] << endl;
    return 0;
}
