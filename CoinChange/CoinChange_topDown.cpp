#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// top down approach
int minNoOfCoinsForChange(int money, const vector<int>& denoms, vector<int>& dp)
{
    int coins;
    if(dp[money] != INT_MAX)
        return dp[money];
    for(int d : denoms)
    {
        if((d <= money) && (money-d) >= 0)
        {
            coins = minNoOfCoinsForChange(money-d, denoms, dp);
            if(coins == INT_MAX)
                continue;
            if(dp[money] > (coins + 1))
            {
                dp[money] = coins + 1;
            }
        }
    }
    return dp[money];
}

int main()
{
    vector<int> denoms = {1, 2, 5, 8, 10}; // types of coins/ denominations
    int money = 23;
    vector<int> dp(money+1, INT_MAX);
    dp[0] = 0;
    int coins = minNoOfCoinsForChange(money, denoms, dp);

    cout << "Minimum number of coins needed for " << money << ": ";
    (coins == INT_MAX)? (cout << "NOT POSSIBLE") : (cout << coins);
    cout << endl;
    return 0;
}