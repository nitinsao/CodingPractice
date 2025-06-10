#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s1 = "xacbcf";
    string s2 = "abcdaf";
    cout << "Inputs are: " << s1 << "\t " << s2 << endl;
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    // finding length of shortest common supersequence
    // finding length of longest common subsequence
    for(int i = 1; i <= s1.size(); i++)
    {
        for(int j = 0; j <= s2.size(); j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int lenOfSCS = s1.size() + s2.size() - dp[s1.size()][s2.size()];
    cout << "lenOfSCS: " << lenOfSCS << endl;
    // Print the SCS
    // Take a walk into the dp matrix
    string str = "";
    int i = s1.size(), j = s2.size();
    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            str.push_back(s1[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i][j] == dp[i][j-1])
            {
                str.push_back(s2[j-1]);
                j--;
            }
            else
            {
                str.push_back(s1[i-1]);
                i--;
            }
        }
    }
    if(i == 0)
        while(j > 0){
            str.push_back(s2[j-1]);
            j--;
        }
    else if(j == 0)
        while(i > 0){
            str.push_back(s1[i-1]);
            i--;
        }
    reverse(str.begin(), str.end());
    cout << "Shortest common supersequence : " << str << endl;
}