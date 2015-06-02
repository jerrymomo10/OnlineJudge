#include <string>
using namespace std;
class Solution{
public:
    string convert(string s,int numRows)
    {
        if (numRows <= 1) return s;
        string t;
        int size = 2*numRows-2;
        for(int i=0;i<numRows;i++)
        {
            for(int j=i;j<s.size();j+=size)
            {
                t.append(1,s[j]);
                if(i!=0&&i!=numRows-1&&j+size-2*i<s.size())
                {
                    t.append(1,s[j+size-2*i]); 
                } 
            }
        } 
        return t;
    }
};

