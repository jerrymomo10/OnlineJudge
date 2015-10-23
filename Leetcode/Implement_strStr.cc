#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//O(n*m)
class Solution{
public:
	int strStr(string& haystack,string& needle)
	{
		int haSize = haystack.size();
		int neSize = needle.size();
		if(neSize==0)return 0;
		int i ,j;
		for(i=0;i<haSize;i++)
		{
			if(haystack[i]==needle[0])
			{
				for(j=1;j<neSize;j++)
				{
					if(haystack[i+j]!=needle[j])break;
				}
				if(j==neSize)return i;
			}
		}
		return -1;
	}
};
//KMP algorithm knuth-morris-pratt O(m+n)
class Solution2{
public:
	vector<int> getprefix(string needle)
	{
		int m = needle.size();
		vector<int> pre(m);
		for(unsigned int i =1;i<needle.size();i++)
		{
			int pos = pre[i-1];
			while(pos>0&&needle[i]!=needle[pos]){pos = pre[pos-1];}
			pre[i] = (needle[i]==needle[pos])?pos+1:pos;
		}
		return pre;
	}
	    // KMP(Knuth-Morris-Pratt) algorithm
    int strStr(string haystack, string needle) {
        int haSize = haystack.size();
        int neSize = needle.size();
        if (neSize == 0) return 0;
        vector<int> PF = getprefix(needle);
        int i = 0, j = 0;
        while (i < haSize) {
            if (haystack[i] == needle[j]) {
                if (j == neSize-1) return i-neSize+1;
                j++; i++;
            }
            else if (j == 0) i++;
            else j = PF[j-1];
        }
        return -1;
    }
	};
int main()
{
	string hay = "iamluoyahui";
	string ned = "luoyahui";
	Solution2 s;
	auto index = s.strStr(hay,ned);
	cout<<index<<'\t'<<endl;
	return 0;
}
