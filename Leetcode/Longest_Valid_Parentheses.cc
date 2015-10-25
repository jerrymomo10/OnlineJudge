#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> data_stack;
        int length = s.size();
        int longestpath = 0;
        for(int i=0;i<length;i++)
        {
			// (
			if(s[i]=='(') data_stack.push(i);
			else if(data_stack.empty()) data_stack.push(i);
			else if(s[data_stack.top()]=='(')data_stack.pop();
			else data_stack.push(i);
		}
		if(data_stack.empty())return length;
		int a = length,b=0;
		while(!data_stack.empty())
		{
			b = data_stack.top();
			data_stack.pop();
			longestpath = max(longestpath,a-b-1);
			a = b;
		}
		return longestpath;
    }
};
int main()
{
	string str = "()(()";
	Solution s;
	cout<<s.longestValidParentheses(str)<<endl;
	return 0;
}
