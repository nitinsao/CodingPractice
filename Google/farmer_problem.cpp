// Google coding interview question: https://www.youtube.com/watch?v=Ti5vfu9arXQ
// NEED TO LEARN THESE TYPE OF DP SOLUTIONS
#include <iostream>

using namespace std;

int main()
{
    int bin_arr[6][5] = {{0,1,1,0,1},
                        {1,1,0,1,0},
                        {0,1,1,1,0},
                        {1,1,1,1,0},
                        {1,1,1,1,1},
                        {0,0,0,0,0}};
    int n = 6;
    int m = 5;
    int dp[6][5] = {{0}};
    int max_num = -1;
    int left, right, diag;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(bin_arr[i][j] == 0)
                continue;
            left = (i > 0) ? dp[i-1][j] : 0;
            right = (j > 0) ? dp[i][j-1] : 0;
            diag = ((i > 0) && (j > 0)) ? dp[i-1][j-1] : 0;
            dp[i][j] = min(left, min(right, diag)) + 1;
            max_num = max(max_num, dp[i][j]);
        }
    }
    cout << "Returning : " << max_num << endl;
    return 0;
}