#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Interval{
    int start;
    int end;
    Interval():start(0),end(0){};
    Interval(int s, int e):start(s),end(e){};
};
bool mysort(Interval a,Interval b)
{
    return a.start<b.start;
}
struct mysort2{
    bool operator()(Interval a, Interval b){ return a.start<b.start;}
}myobj;
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.empty())
            return res;
        sort(intervals.begin(),intervals.end(),myobj);
        res.push_back(intervals[0]);
        for(auto be = intervals.begin()+1;be!=intervals.end();be++)
        {
            if(res.back().end<(*be).start)res.push_back(*be);
            else
            {
                res.back().end = max((*be).end,res.back().end);
            }
        }
        return res;
    }
};
int main()
{
    Solution so;
    vector<Interval> t;
    t.push_back(Interval(1,3));
    t.push_back(Interval(2,6));
    t.push_back(Interval(8,10));
    t.push_back(Interval(15,18));
    auto r = so.merge(t);
    for(auto i:r)
    {
        cout<<i.start<<i.end<<endl;
    }
    return 1;
}
