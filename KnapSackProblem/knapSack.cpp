#include <iostream>
#include <vector>
using namespace std;

int getMaxProfit(int n, int w, int i, const vector<int>& wts, const vector<int>& prices, vector<int>& profits)
{
    if(n <= 0 || w <= 0 || i == wts.size())
        return 0;
    if(profits[i])
        return profits[i];
    int taken = 0, notTaken = 0;
    if(((w - wts[i]) >= 0) && ((n - 1) >= 0))
    {
        taken = getMaxProfit(n - 1, w - wts[i], i+1, wts, prices, profits) + prices[i];
        // cout << "profit after taking " << i << ", with weight constraint " << w << ": " << taken << endl;
    }
    notTaken = getMaxProfit(n, w, i+1, wts, prices, profits);
    // cout << "profit after NOT taking " << i << ", with weight constraint " << w << ": " << notTaken << endl;
    return (taken > notTaken ? taken : notTaken);
}

// top down
int knapSack(const vector<int>& wts, const vector<int>& prices, int n, int w)
{
    if(n == 0 || w == 0)
        return 0;
    
    int inc = 0, exc = 0;
    if(wts[n-1] <= w)
        inc = prices[n-1] + knapSack(wts, prices, n-1, w-wts[n-1]);
    exc = knapSack(wts, prices, n-1, w);
    return inc > exc ? inc : exc;
}

// bottom-up [loop] [NOT WORKING - bug needs to be fixed]
int knapSackDP(const vector<int>& wts, const vector<int>& prices, int N, int W)
{
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    int inc, exc;
    for(int n = 1; n <= N; n++)
    {
        for(int w = 1; w <= W; w++)
        {
            inc = exc = 0;
            if(wts[n-1] <= W)
                inc = prices[n-1] + dp[n-1][w - wts[n-1]];
            exc = dp[n-1][w];
            dp[n][w] = inc > exc ? inc : exc;
        }
    }
    return dp[N][W];
}


int main()
{
    int n = 4, w = 11;
    vector<int> weights = {2, 7, 5, 4};
    vector<int> prices = {5, 20, 50, 10};
    vector<int> profits = {0};
    int profit = getMaxProfit(n, w, 0, weights, prices, profits);
    cout << "Got max profit of " << profit << endl;
    cout << knapSack(weights, prices, n, w) << endl;
    cout << knapSackDP(weights, prices, n, w) << endl;
    return 0;
}