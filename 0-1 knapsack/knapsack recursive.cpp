#include <iostream>
using namespace std;

int knapsack(int n, int weight[], int value[], int W)
{
    if (n == 0 || W == 0)
        return 0;

    if (weight[n - 1] <= W)
    {
        int op1 = knapsack(n - 1, weight, value, W - weight[n - 1])+ value[n - 1];
        int op2 = knapsack(n - 1, weight, value, W);
        return max(op1, op2);
    }
    else
    {
        return knapsack(n - 1, weight, value, W);
    }
}

int main()
{
    int n = 4;
    int value[] = {60, 100, 120, 150};
    int weight[] = {10, 20, 30, 40};
    int W = 50;

    int maxVal = knapsack(n, weight, value, W);
    cout << "Maximum value in knapsack = " << maxVal << endl;

    return 0;
}

