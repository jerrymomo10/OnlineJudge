#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        combinationSumCore(candidates,target,res,combination,0);
        return res;
    }
    void combinationSumCore(vector<int> &candidates,int target,vector<vector<int>> &res,vector<int> &combination,int begin)
    {
		if(target==0)
		{
			res.push_back(combination);
			return;
		}
		for(unsigned int i = begin;i<candidates.size()&&candidates[i]<=target;i++)
		{
			if(i==begin||candidates[i]!=candidates[i-1])
			{
				combination.push_back(candidates[i]);
				combinationSumCore(candidates,target-candidates[i],res,combination,i+1);
				combination.pop_back();
			}
		}
	}
};
int main()
{
	vector<int> m = {10,1,2,7,6,1,5};
	Solution s;
	vector<vector<int>> result = s.combinationSum2(m,8);
	for(auto i = result.cbegin();i!=result.cend();i++)
	{
		for(auto j = (*i).cbegin();j!=(*i).cend();j++)
		{
			cout<< *j<<'\t';
		}
		cout<<endl;
	}
	return 0;
}
