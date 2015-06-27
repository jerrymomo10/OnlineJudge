#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
      };
//leetcode 8ms
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1==nullptr)return l2;
		if(l2==nullptr)return l1;
        ListNode* res = new ListNode(0);
        ListNode* tmp = res;
        while(l1!=nullptr&&l2!=nullptr)
        {
			if(l1->val<l2->val)
			{
					tmp->next  = l1;
					tmp = tmp->next;
					l1 = l1->next;
				}
			else
			{
				    tmp->next  = l2;
					tmp = tmp->next;
					l2 = l2->next;
				}

		}
		if(l1==nullptr) tmp->next=l2;
		if(l2==nullptr) tmp->next=l1;
		tmp = res;
		res = res->next;
		delete tmp;
		return res;
    }
    
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		int len = lists.size();
		if(len<1)return nullptr;
		while(len>1)
		{
			for(int i=0;i<len/2;i++)
			{
				lists[i] =  mergeTwoLists(lists[0],lists[len-1-i]);
				}
			len = len/2;
		}

		return lists.front();
	}
};
//递归的方法 8ms
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len<1)return nullptr;
		while(len>1)
		{
			for(int i=0;i<len/2;i++)
			{
				lists[i] =  mergeTwoLists(lists[i],lists[len-1-i]);
				}
			len = (len+1)/2;
		}

		return lists.front();
    }
};
int main()
{
	ListNode* a[10];
	ListNode* b[10];
	vector<ListNode*> l;
	for(int i=0;i<10;i++)
	{
		a[i] = new ListNode(i);
		b[i] = new ListNode(i*2);
		}
	for(int i=0;i<9;i++)
	{
		a[i]->next = a[i+1];
		b[i]->next = b[i+1];
		}
	int i=0;
	while(a[i]!=nullptr)
	{
		cout<<a[i]->val<<endl;
		i++;
		}
	
	cout<<endl;
	l.push_back(a[0]);
	l.push_back(b[0]);
	Solution s;
	ListNode* re = s.mergeKLists(l);
	while(re)
	{
		cout<<re->val<<'\t';
		re = re->next;
		}
}

	
