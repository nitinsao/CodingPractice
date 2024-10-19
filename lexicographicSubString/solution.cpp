/**
 * Problem: Given a string 'str' using [A-Z, a-z] characters and an integer 'k' denoting legth of substring
 * print the smallest and largest (in lexicographical order) substring from the given string 'str' with length 'k' 
 */

#include <iostream>
#include <cstring>
using namespace std;

bool isSmall(const string& str, string& out, int iStr, int iOut)
{
    if(str[iStr] < out[iOut])
        return true;
    else if(str[iStr] == out[iOut])
        return isSmall(str, out, iStr+1, iOut+1);
    else
        return false;
}
string getSmall(const string& str, int k)
{
    string out = "";
    for(int i = 0; i < k; i++)
        out.append("z");
    for(int i = 0; i <= str.size() - k; i++)
    {
        if(isSmall(str, out, i, 0))
        {
            /*for(int j = 0; j < k; j++)
                out[j] = str[i+j];*/
            memcpy(&out[0], &str[i], k);
        }
    }
    return out;
}

bool isBig(const string& str, string& out, int iStr, int iOut)
{
    if(str[iStr] > out[iOut])
        return true;
    else if(str[iStr] == out[iOut])
        return isBig(str, out, iStr+1, iOut+1);
    else
        return false;
}

string getLarge(const string& str, int k)
{
    string out = "";
    for(int i = 0; i < k; i++)
        out.append("A");
    for(int i = 0; i <= str.size() - k; i++)
    {
        if(isBig(str, out, i, 0))
        {
            /*for(int j = 0; j < k; j++)
                out[j] = str[i+j];*/
            memcpy(&out[0], &str[i], k);
        }
    }
    return out;
}

int main()
{
    string str = "vinitasahuninivinivixvixvaxyzz";
    int k =6;
    string small = getSmall(str, k);
    string large = getLarge(str, k);
    cout << "lexicographic substring with size " << k << endl;
    cout << "lexicographic smallest substring: " << small << endl << "lexicographic largest substring: " << large << endl;
    return 0;
}