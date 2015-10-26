#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
     if(n<1)return nullptr;
     string ret = "1";
     for(int i = 1;i<n;i++)
     {
			ret = countAndSayCore(ret);
	 }   
	 return ret;
    }
    string countAndSayCore(string inputstr)
    {
		char t = inputstr[0];
		string result;
		int count = 1;
		for(unsigned int i = 1;i<inputstr.length();i++)
		{
			if(t==inputstr[i])
			{
				count++;
			} 
			else
			{
				char temp = '0'+count;
				result = result+temp+t;
				t = inputstr[i];
				count = 1;
			}
		 }
		char temp = '0'+count;
		result = result+temp+t;
	 	return result;
	}
};
int main()
{
	Solution s;
	cout<<s.countAndSay(10)<<endl;
	return 0;
}
