#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int jump(int A[],int n)
{
	if(n<2)return 0;
	int level = 0;
	int currentMax=0;
	int i = 0;
	int nextMax=0;
	while(currentMax-i+1>0)
	{
		level++;
		for(;i<=currentMax;i++)
		{
			nextMax=max(nextMax,A[i]+i);
			if(nextMax>=n-1)return level;
		}
		currentMax = nextMax;
	}
	return 0;
}
class Solution{
public:
	int jump(vector<int>&nums)
	{
		int n = nums.size();
		if(n<2)return 0;
		auto i=nums.cbegin(),currentMax=nums.cbegin(),nextMax=nums.cbegin();		int level=0;
		while(currentMax-i+1>0)
		{
			level++;
			for(;i<=currentMax;i++)
			{
				nextMax = max(nextMax,i+*i);
				if(nextMax-nums.cbegin()>=n-1)return level;
			}
			currentMax = nextMax;
		}
		return 0;
	}
};
int main()
{
	vector<int> A;
	A.push_back(2);
	A.push_back(3);
	A.push_back(1);
	A.push_back(4);
	A.push_back(4);
	Solution s;
	int x = s.jump(A);
	cout<<x<<endl;
	return 1;
}
