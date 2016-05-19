#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        while(i>=0&&s[i]==' ')i--;
        if(i==-1)return 0;
        int count=0;
        while(i>=0&&s[i]!=' ')
        {
            count++;
            i--;
        }
        return count;

    }
};


int main() {
    Solution so;
    string s = "Hello world";
    cout<<so.lengthOfLastWord(s)<<endl;
    return 0;
}
