#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
double findKth(vector<int> nums1,vector<int> nums2,int k)
{
    int m = nums1.size();
    int n = nums2.size();
    if(m>n)return findKth(nums2,nums1,k);
    if(m==0)return *(nums2.cbegin()+k-1);
    if(k==1) return min(nums1.front(),nums2.front());
    int pa = min(k/2,m),pb = k-pa;
    if(nums1[pa-1] < nums2[pb-1])
    {
        nums1.erase(nums1.begin(),nums1.begin()+pa);
        return findKth(nums1,nums2,k-pa);
    }
    else if(nums1[pa-1] > nums2[pb-1])
    {
        nums2.erase(nums2.begin(),nums2.begin()+pb);
        return findKth(nums1,nums2,k-pb);
    }
    else return nums1[pa-1]; 
}
class Solution3{
public:
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int total = m+n;
        if(total%2)
        {
            return findKth(nums1,nums2,total/2+1);    
        }
        else
        {
                 return (double)(findKth(nums1,nums2,total/2)+findKth(nums1,nums2,total/2+1))/2;
                //return findKth(nums1,nums2,total/2);
        }
    }
};
int main()
{
    vector<int> a{1,3,5,7};
    vector<int> b{2,4,6,8};
    Solution3 s;
    cout<<s.findMedianSortedArrays(a,b)<<endl;
    return 1;
}
