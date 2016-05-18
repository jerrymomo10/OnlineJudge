#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxcount = 0;
        int i = 0;
        for(i;i<=maxcount;i++)
        {
            maxcount = max(maxcount,nums[i]+i);
            if(maxcount>=n-1)return true;
        }
        return false;
    }
};


int main() {
    Solution so;
    vector<int> nums={3,2,1,0,4};
    auto res = so.canJump(nums);
    res? cout<<"TRUE":cout<<"FALSE";
    cout<<endl;
    return 0;
}
