#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[6] = {2, 3, 5, 6, 8, 10};
    int size = 6;
    int sum = 10;
    cin >> sum;
    vector<vector<int>> dp(size+1, vector<int>(sum+1, 0));
    for(int i = 0; i <= size; i++)
        dp[i][0] = 1;   // only one subset (null set) we can have with starting `i` number of elements
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= sum; j++)
        {
            if(arr[i-1] <= j)   // add both types of subsets, including and excluding the current value
                dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << "Possible subsets: " << dp[size][sum] << endl;
    return 0;
}