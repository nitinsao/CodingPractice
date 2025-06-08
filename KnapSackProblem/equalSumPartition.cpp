#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[4] = {1, 5, 11, 7};
    int size = 4;
    int total = 0;
    for(const int& val : arr)
        total += val;
    if(total % 2)
    {
        cout << "NOT possible\n";
        return 0;
    }
    total /= 2;
    vector<vector<bool>> dp(size+1, vector<bool>(total+1, false));
    // We need to find if there is any subset having sum equal to `total`
    for(int i = 0; i <= size; i++)
        dp[i][0] = true;
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= total; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    if(dp[size][total])
        cout << "Its POSSIBLE\n";
    else
    cout << "NOT Possible\n";
    return 0;
}