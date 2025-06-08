#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[4] = {2, 1, 11, 5};
    int size = 4;
    int total = 0;
    for(const int& n: arr)
        total += n;
    
    vector<vector<bool>> dp(size+1, vector<bool>(total+1, false));
    for(int i = 0; i <= size; i++)
        dp[i][0] = true;
    // Prepare the table/ matrix with all the possibalities
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= total; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[size][total] << endl;
    
    // calculate mid of the last row (where all the elements are covered)
    int mid = (total/2) + 1;
    // and move towards larger half
    for(int i = mid; i <= total; i++)
    {
        if(dp[size][i] && dp[size][total - i])
        {
            cout << "Min diff : " << (2 * i) - total << endl;
            return 0;
        }
    }
    cout << "NO subset found\n";
    
    return 0;
}