#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       vector<int>::iterator iter;
       while((iter = find(nums.begin(),nums.end(),val))!=nums.end())
       {
		   nums.erase(iter);
		   }
		return nums.size();
    }
};
int main()
{
	return 1;
	}
