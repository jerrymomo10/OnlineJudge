#include <iostream>
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
};
//递归的方法 8ms
class Solution2 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};
int main()
{
	ListNode* a[10];
	ListNode* b[10];
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
	Solution s2;
	ListNode* re = s2.mergeTwoLists(a[0],b[0]);
	while(re!=nullptr)
	{
		cout<<re->val<<endl;
		re = re->next;
	}
}

	
