/********************************************
牛客网C++第一题多路归并排序O（r*c*r）
*********************************************/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
void Sort(vector< vector<int> > x) 
{
    unsigned r = x.size();
    unsigned int c = (*(x.cbegin())).size();
    unsigned int* re = new unsigned int[r];
	for(unsigned int i=0;i<r*c;i++)
    {
        int min = INT_MAX;
        int index = -1;
        for(unsigned int j=0;j<r;j++)
        {
			auto t = *(x.begin()+j);
			auto tmin = *(t.begin()+re[j]);
			//注意re[j]<c的限制，到达一列的结尾时不要再用这一列排序，跳过
            if((tmin<min)&&(re[j]<c)) {min = tmin;index=j;}  
        }
        re[index]++;
        cout<<min<<'\t';
    }
    cout<<endl;
}
int main()
{
    vector<int> a1{1,2,8,9};
    vector<int> a2{2,4,9,12};
    vector<int> a3{4,7,10,13};
    vector<int> a4{6,8,11,15};
    vector< vector<int> > a{a1,a2,a3,a4};
    Sort(a);
    return 1;
 }
