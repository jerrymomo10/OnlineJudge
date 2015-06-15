#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//3重查找在LEETCODE LTE
class Solution2{
public:
	vector<vector<int> > threeSum(vector<int>& num)
	{
		vector<vector<int> >result;
		result.clear();
		if(num.size()<3)return result;
		
		sort(num.begin(),num.end());
		vector<int> res;
		int j;
		int k;
		int target = 0; 
		for(unsigned int i=0;i<num.size();i++)
		{
			target = 0-num[i];
			j=i+1;
			k=num.size()-1;
			while(j<k)
			{
				if(num[j]+num[k]==target)
				{
					res.push_back(num[i]);
					res.push_back(num[j]);
					res.push_back(num[k]);
					if(find(result.begin(),result.end(),res)==result.end())result.push_back(res);
					res.clear();
					j++;
				}
				else if(num[j]+num[k]<target) j++;
				else k--;
			}
		}
		return result;
	}
	};
//递归的DFS
class Solution{
public:
	vector<vector<int> > threeSum(vector<int>&num)
	{
		result.clear();
		sort(num.begin(),num.end());
		vector<int> res;
		dfs(num,0,0,0,res);
		return result;
	}
	void dfs(vector<int>& num,unsigned int startindex,int depth,int target,vector<int>& res)
	{
		if(depth==2)
		{
			for(unsigned int i=startindex;i<num.size();i++)
			{
				if(num[i]==target)
				{
					res.push_back(num[i]);
					result.push_back(res);
					res.pop_back();
					return;
				}
			}
			return;
		}
		//剪枝
		int avg = target/(3-depth);
		for(unsigned int i=startindex;i<num.size()&&num[i]<=avg;i++)
		{
			//剪枝
			if(i>startindex&&num[i]==num[i-1])continue;
			res.push_back(num[i]);
			dfs(num,i+1,depth+1,target-num[i],res);
			res.pop_back();
		}
	}
private:
	vector<vector<int> > result;
	};
