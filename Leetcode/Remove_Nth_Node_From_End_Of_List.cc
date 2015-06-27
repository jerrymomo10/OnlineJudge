
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
 };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* t1 = head;
		ListNode* t2 = head;
		for(int i=0;i<n;i++)
		{
			t1 = t1->next;
		}
		if(t1==nullptr)
		{
			head = head->next;
			delete t2;
			t2=nullptr;
			return head;
		}
		while(t1->next!=nullptr)
		{
			t1 = t1->next;
			t2 = t2->next;
		}
		t1 = t2->next;
		t2->next = t1->next;
		delete t1;
		t1 = nullptr;
		t2 = nullptr;
		return head;	
    }
};
int main()
{
	return 0;
	}
