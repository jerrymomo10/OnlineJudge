/***************************************************************
反转二叉树，即交换所有结点的左右子树，但不能使用递归方法。
二叉树结构如下：
TreeNode{
     TreeNode left,right;   //左右子树
     DataType data;         //数据
}
*****************************************************************/
#include <iostream>
#include <stack>
using namespace std;
struct TreeNode{
	int data;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode(int x):data(x),left(nullptr),right(nullptr){;}
	};
//使用递归的方法
void Reverse_tree(TreeNode* root)
{
	if(!root) return;
	TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	Reverse_tree(root->left);
	Reverse_tree(root->right);
}
//使用非递归的方法 堆栈,队列都可以 模拟递归
void Reverse_tree_stack(TreeNode* root)
{
	stack<TreeNode*> s;
	if(!root)return;
	s.push(root);
	TreeNode* tmp;
	TreeNode* tn;
	while(!s.empty())
	{
		tmp = s.top();
		s.pop();
		tn = tmp->left;
		tmp->left = tmp->right;
		tmp->right = tn;
		if(tmp->right)s.push(tmp->right);
		if(tmp->left)s.push(tmp->left);
	}
}
//递归前序遍历输出
void output_tree(TreeNode* root)
{
	if(!root)return;
	cout<<root->data<<'\t';
	output_tree(root->left);
	output_tree(root->right);
}
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    stack<TreeNode*> s;
	if(!root)return nullptr;
	s.push(root);
	TreeNode* tmp;
	TreeNode* tn;
	while(!s.empty())
	{
		tmp = s.top();
		s.pop();
		tn = tmp->left;
		tmp->left = tmp->right;
		tmp->right = tn;
		if(tmp->right)s.push(tmp->right);
		if(tmp->left)s.push(tmp->left);
	}
    return root;
    }
};
int main()
{
	TreeNode* a[10];
	for(int i=0;i<10;i++)
	{
		a[i] = new TreeNode(i);
	}
	for(int i=0;i<10;i++)
	{
		if(2*i+1<10)a[i]->left = a[2*i+1];
		if(2*i+2<10)a[i]->right = a[2*i+2];
	}
	output_tree(a[0]);
	cout<<endl;
	Reverse_tree(a[0]);
	output_tree(a[0]);
	cout<<endl;	
	Reverse_tree_stack(a[0]);
	output_tree(a[0]);
	cout<<endl;	
	return 1;
	}
