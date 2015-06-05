#include <climits>
#include <iostream>
#include <string>
using namespace std;
class Solution{
public:
    int myAtoi(string str)
    {
        if(str.empty())return 0;
        char t;
        int res=0;
        bool sign = true;
        int countsign = 0;
        int countnums = 0;
        for(int i=0;i<str.length();i++)
        {
            t = str[i];
            if(isspace(t)&&countnums!=0)break;
            if(isspace(t))continue;
            if(t=='+'){sign=true;countsign++;countnums++;continue;} 
            if(t=='-'){sign=false;countsign++;countnums++;continue;} 
            if(countsign>1){return 0;}
            if(t>='0'&&t<='9')
            {
                countnums++;
                if(res>INT_MAX/10||(res==INT_MAX/10&&(t-'0')>7))
                {
                    if(sign)return INT_MAX;
                    else return INT_MIN; 
                } 
                res = 10*res+t-'0'; 
            }
            else break;
        }
        if(!sign)return -1*res; 
        return res;
    }
};
int main()
{
    Solution a;
    string s = "  -0012a42"; 
    cout<<a.myAtoi(s)<<endl;
}
