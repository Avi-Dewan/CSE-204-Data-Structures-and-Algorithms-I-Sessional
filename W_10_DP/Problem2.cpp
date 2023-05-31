#include<iostream>
#include<cstring>

using namespace std;

int cost[11][11];
int dp[11][(1<<11)];


int cost_cities(int j, int mask, int n) {
    int total = cost[j][j];

    for(int i = 0; i < n; i++) {
        if(i != j && (mask & (1<<i))) {
            total += cost[j][i];
        }
    }

    return total;
}


int minCost(int i, int mask, int& n)
{
    if(i == n)
        return 0;

    if(dp[i][mask] != -1)
        return dp[i][mask];

    int ans = INT_MAX;
    for(int j = 0; j < n; j++)
    {
        if(mask&(1<<j))
            ans = min(ans, cost_cities(j, mask, n) + minCost(i+1, (mask^(1<<j)), n));
    }

    dp[i][mask] = ans;

    return ans;
}

int main()
{

    int n;

    cin >> n;

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];
    }
        cout << minCost(0, (1<<n) - 1, n) << '\n';

    return 0;
}


/*
2
100 100
5000 100

3
25 100 0
0 25 0
150 100 25

3
30 75 95
120 45 20
105 30 90
*/
