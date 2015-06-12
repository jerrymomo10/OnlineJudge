/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
