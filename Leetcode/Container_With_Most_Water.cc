#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int maxV = INT_MIN;
        while(start<end)
		{
				int contain = min(height[end],height[start])*(end-start);
				maxV = max(maxV,contain);
				if(height[end]>=height[start])
				{
						start++;
				}
				else
				{
					end--;
				}
		}
		return maxV;
    }
};
int main()
{
	Solution s;
	vector<int> a{6,5,7,8,6,3,4};
	cout<<s.maxArea(a)<<endl;
	return 1;
}
