#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
class Solution{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int longestBegin = 0;
        int maxlen = 1;
        bool table[1000][1000] = {false};
        for (int i=0;i<n;i++)
        {
            table[i][i] = true;
        }
        for (int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                table[i][i+1] = true;
                longestBegin = i;
                maxlen = 2;
            }
        }         
        for(int len=3;len<=n;len++)
        {
            for(int i=0;i<n-len+1;i++)
            {
                int j = i+len-1;
                if(s[i]==s[j]&&table[i+1][j-1])
                {
                    table[i][j] = true;
                    longestBegin = i;
                    maxlen = len; 
                } 
            } 
        }
       return s.substr(longestBegin,maxlen); 
    }
};
int main()
{
    Solution s;
    string s1{"dddddddd"};
    cout<<s.longestPalindrome(s1);
    return 1;
}
