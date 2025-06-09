#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(const int st[], const int& size, const int& sum, vector<vector<bool>>& dp, int i, int currSum)
{
    if(sum == currSum)
        return true;
    if(i >= size)
        return false;
    if(dp[i][currSum])
        return dp[i][currSum];
    return dp[i][currSum] = (subsetSum(st, size, sum, dp, i+1, currSum) || subsetSum(st, size, sum, dp, i+1, currSum + st[i]));
}

int main()
{
    int st[5] = {2, 7, 1, 5, 93}; //, 9, 10, 4, 20, 6};
    int size = 5;
    int sum = 0;
    cin >> sum;
    // Memoization
    vector<vector<bool>> dp(size+1, vector<bool>(sum+1, false));
    if(subsetSum(st, size, sum, dp, 0, 0))
        cout << "Sum possible!!\n";
    else
        cout << "Sum NOT possible.\n";

    // bottom-up approach
    vector<vector<bool>> dp2(size+1, vector<bool>(sum+1, false));
    int i;
    for(i = 0; i <= size; i++)
        dp2[i][0] = true;
    for(i = 1; i <= size; i++)
    {
        for(int j = 1; j <= sum; j++)
        {
            if(st[i-1] <= j) // current value can be considered
                dp2[i][j] = dp2[i-1][j-st[i-1]] || dp2[i-1][j];
            else    // current value need to be skipped as its larger than sum
                dp2[i][j] = dp2[i-1][j];
            // cout << dp2[i][j] << "\t";
        }
        // cout << endl;
    }
    if(dp2[size][sum])
        cout << "Sum possible!!\n";
    else
        cout << "Sum NOT possible.\n";

    return 0;
}