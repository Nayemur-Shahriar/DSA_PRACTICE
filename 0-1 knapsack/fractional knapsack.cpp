#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int value, weight;

    Item(int v, int w)
    {
        value=v, weight=w;
    }
};


bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& v)
{
    sort(v.begin(), v.end(), cmp);

    double totalValue = 0.0;

    for (auto item : v)
    {
        if (W >= item.weight)
        {
            W -= item.weight;
            totalValue += item.value;
        }
        else
        {
            totalValue += (double)item.value * W / item.weight;
            break;
        }
    }

    return totalValue;
}

int main()
{
    int n = 3;
    int capacity = 50;

    vector<Item> v;
    v.push_back(Item(60, 10));
    v.push_back(Item(100, 20));
    v.push_back(Item(120, 30));

    double maxValue = fractionalKnapsack(capacity, v);

    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
