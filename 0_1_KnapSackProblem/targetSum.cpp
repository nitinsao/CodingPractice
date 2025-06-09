#include <iostream>
#include <vector>
using namespace std;


int findTargetSumWays(vector<int>& nums, int target) {
    // SOLUTION WORKING in LEETCODE (covering all the edge cases)
    int total = 0;
    int size = nums.size();
    int zeros = 0;
    // Find number of zeros as well, which can be placed in any of the subset/ partition
    for(const int& n : nums)
    {
        if(!n)
            zeros++;
        total += n;
    }
    if((target + total)%2)
        return 0;
    int s1 = (target + total)/2;
    if(s1 < 0)
        return 0;
    vector<vector<int>> dp(size+1, vector<int>(s1+1, 0));
    for(int i = 0; i <= size; i++)
        dp[i][0] = 1;
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= s1; j++)
        {
            if((nums[i-1] == 0) || (nums[i-1] > j))
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j - nums[i-1]] + dp[i-1][j];
        }
    }
    // Each zero can be put in either of the partitions, so 2^zeros ways to do this
    // if(zeros > 1)
    return (1 << zeros) * dp[size][s1];
    // return dp[size][s1];
}

int main()
{
    // Question says, need to pul `+` or `-` symbol infront of the array values to make sum equals to given `sum`
    // int arr[4] = {1,1,2,3};
    // int size = 4;
    // int sum = 1;
    int arr[1] = {1};
    int size = 1;
    int sum = 2;
    // The question is similar to "Count no. of subsets with given difference of subsetSum"
    // Here we can say that, we need to find count of 2 subsets having difference of given `sum` value
    // s1 - s2 = sum
    // We can write +1-1-2+3 ==> +1+3-1-2 ==> sum{1,3} - sum{1,2}
    // We can find s1 using these 2 equations
    // s1 - s2 = givenSum (or diff)
    // s1 + s2 = total
    // s1 = (givenSum + total)/2
    // And so, we just need to find number of subsets having sum = s1
    int total = 0;
    for(const int& n : arr)
        total += n;
    int s1 = (sum + total)/2;
    vector<vector<int>> dp(size+1, vector<int>(s1+1, 0));
    for(int i = 0; i <= size; i++)
        dp[i][0] = 1;
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= s1; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << "Possible ways to get the target sum: " << dp[size][s1] << endl;
    return 0;
}