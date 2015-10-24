#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        unsigned int length = nums.size();
        if(length<=0)return;
        int pos = length-2;
        while(nums[pos]>=nums[pos+1]&&pos>=0)pos--;
        if(pos==-1)reverse(nums.begin(),nums.end());
        else
        {        
			int j = length-1;
			while(nums[j]<=nums[pos]&&j>pos)j--;
			swap(nums[j],nums[pos]);
			reverse(nums.begin()+pos+1,nums.end());
		}
    }
};
int main()
{
	vector<int> vec = {5,1,1};
	Solution s;
	s.nextPermutation(vec);
	auto p = vec.cbegin();
	while(p!=vec.cend())
	{
		cout<<*p<<'\t';
		p++;
	}
	cout<<endl;
	return 0;
}
