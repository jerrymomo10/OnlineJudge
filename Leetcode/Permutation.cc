#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutation(nums, 0, result);
        return result;
    }
    void permutation(vector<int>& nums,int begin,vector<vector<int>>& result)
    {
        if(begin>=nums.size())
        {
            result.push_back(nums);
            return;
        }
        else {
            for (int i = begin; i < nums.size(); i++)
            {
                swap(nums[i],nums[begin]);
                permutation(nums,begin+1,result);
                swap(nums[begin],nums[i]);
            }
        }
    }
};

class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        do{
            result.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return result;
    }
};

int main() {
    Solution so;
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> res = so.permute(nums);
    for(auto i=res.cbegin();i<res.cend();i++)
    {
        for(auto j=(*i).begin();j<(*i).end();j++)
        {
            cout<<*j<<' ';
        }
        cout<<endl;
    }
    //cout << "Hello, World!" << endl;
    return 0;
}
