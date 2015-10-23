#include <cstdio>
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
	};
class Solution{
public:
	ListNode* reverseKGroup(ListNode* head,int k)
	{
		if(head==nullptr)return nullptr;
		ListNode* temp = head;
		ListNode* vector[k];
		for(int i = 0;i<k;i++)
		{
			//k<length
			if(temp==nullptr)return head;
			vector[i] = temp;
			temp = temp->next;
		}
		vector[0]->next = nullptr;
		head = vector[k-1];
		for(int i =k-1;i>0;i--)
		{
			vector[i]->next = vector[i-1];
		}
		ListNode* tail =  vector[0];
		bool end = false;
		while(!end&&temp!=nullptr)
		{
			for(int i = 0;i<k;i++)
			{
				if(temp==nullptr)
				{
					end = true;
					break;
				}
				vector[i] = temp;
				temp = temp->next;		
			}
			if(!end)
			{
				tail->next = vector[k-1];
				for(int i =k-1;i>0;i--)
				{
					vector[i]->next = vector[i-1];
				}
				vector[0]->next = nullptr;
				tail = vector[0];
			}
			else
			{
				tail->next = vector[0];
			}
		}
		return head;
	}
};
void printlist(ListNode* head)
{
	ListNode* t = head;
	int i=0;
	while(t!=nullptr&&i<20)
	{
		printf("%d ",t->val);
		t = t->next;
		i++;
	}
	printf("\n");
}
int main()
{
	ListNode* head = new ListNode(1);
	ListNode* t=head;
	for(int i=1;i<5;i++)
	{
		t->next = new ListNode(i+1);
		t = t->next;
	}
	printlist(head);
	Solution s;
	auto reversed = s.reverseKGroup(head,3);
	printlist(reversed);
	t = head;
}
