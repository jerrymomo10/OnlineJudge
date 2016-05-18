#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m==0)return res;
        int n = matrix[0].size();
        if(n==0)return res;
        int m_begin = 0;
        int n_begin = 0;
        int m_end = m-1;
        int n_end = n-1;
        int state = 0;
        int i;
        for(state;state<4;state++)
        {
            switch (state)
            {
                case 0:
                    for(i=n_begin;i<=n_end;i++)
                    {
                        res.push_back(matrix[m_begin][i]);
                    }
                    m_begin++;
                    break;
                case 1:
                    for(i=m_begin;i<=m_end;i++)
                    {
                        res.push_back(matrix[i][n_end]);
                    }
                    n_end--;
                    break;
                case 2:
                    for(i=n_end;i>=n_begin;i--)
                    {
                        res.push_back(matrix[m_end][i]);
                    }
                    m_end--;
                    break;
                case 3:
                    for(i=m_end;i>=m_begin;i--)
                    {
                        res.push_back(matrix[i][n_begin]);
                    }
                    n_begin++;
                    break;
            }
            if(m_begin>m_end||n_begin>n_end)return res;
            if (state==3)
            {
                state=-1;
            }

        }
        return res;
        
    }
};


int main() {
    Solution so;
    vector<int> nums1={1,2,3,4};
    vector<int> nums2={5,6,7,8};
    vector<int> nums3={9,10,11,12};
    vector<int> nums4={13,14,15,16};
    //vector<int> nums4={13,14,1};
    vector<vector<int>> matrix;
    matrix.push_back(nums1);
    matrix.push_back(nums2);
    matrix.push_back(nums3);
    matrix.push_back(nums4);
    auto res = so.spiralOrder(matrix);
    for(auto i:matrix)
    {
        for(auto x:i)
        {
            cout<<x<<' ';
        }
        cout<<endl;
    }
    for(auto x:res)
    {
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}
