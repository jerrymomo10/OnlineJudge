#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
		int length = nums.size();
		int mid;
		int start = 0,end = length-1;
		while(start<end)
		{
			mid = (start+end)/2;
			if(nums[mid]>nums[end])start = mid+1;
			if(nums[mid]<=nums[end])end = mid;
		}
		int rot = start;
		start = 0;
		end = length-1;
		while(start<=end)
		{
			mid = (start+end)/2;
			int remaind = (mid+rot)%length;
			if(nums[remaind]==target)return remaind;
			if(nums[remaind]>target)end = mid-1;
			else
			{
				start = mid+1;
			}
		}
		return -1;
    }
};
