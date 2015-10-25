#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        vector<int> ret(2,-1);
        while(start<end)
        {
			int mid = (start+end)/2;//bias to the left
			if(nums[mid]>target) end = mid-1;
			else if(nums[mid]<target)start = mid+1;
			else if(nums[mid]==target)end = mid;
		}
		if(nums[start]!=target)return ret;
		ret[0] = start;
		end = nums.size()-1;
		while(start<end)
		{
			int mid = (start+end)/2+1;//bias to the right
			if(nums[mid]>target) end = mid-1;
			else if(nums[mid]<target) start = mid+1;
			else if(nums[mid]==target) start = mid;
		}
		ret[1] = end;
		return ret;
    }
};
int main()
{
	Solution s;
	vector<int> v = {0,0,0,1,2,3};
	auto m = s.searchRange(v,0);
	auto b = m.cbegin();
	while(b!=m.cend())
	{
		cout<<*b<<'\t';
		b++;
	}
}
