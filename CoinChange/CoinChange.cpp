#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minNoOfCoinsForChange(int money, const vector<int>& denoms)
{
    vector<int> dp(money+1, INT_MAX);
    int di = 0;
    int min;
    int tmoney, coinsYet;
    // If the denomination is present, only 1 coin will suffice.
    for(const int& dnom : denoms)
        if(dnom <= money)
            dp[dnom] = 1;
    // If single denomination is not present for required money
    dp[0] = 0;
    if(dp[money] == INT_MAX)
    {
        // Bottom-up approach
        for(int i = 1; i <= money; i++)
        {
            if(dp[i] != INT_MAX)
                continue;
            for(di = 0; denoms[di] < i; di++)
            {
                if(((i - denoms[di]) >= 0) && (dp[i - denoms[di]] != INT_MAX))
                dp[i] = dp[i] < (dp[i - denoms[di]]+1)? dp[i] : (dp[i - denoms[di]]+1);
            }
        }
    }
    return dp[money];
}

int main()
{
    vector<int> denoms = {2, 5, 8, 10}; // types of coins/ denominations
    int money = 12;
    int coins = minNoOfCoinsForChange(money, denoms);

    cout << "Minimum number of coins needed for " << money << ": ";
    (coins == INT_MAX)? (cout << "NOT POSSIBLE") : (cout << coins);
    cout << endl;
    return 0;
}