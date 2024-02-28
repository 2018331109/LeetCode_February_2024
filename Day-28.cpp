/*513. Find Bottom Left Tree Value
Given the root of a binary tree, return the leftmost value in the last row of the tree.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int val=0, cnt=0, mx=0;

    void call(TreeNode* head, int cnt)
    {
        if(head==NULL)
        {
            return;
        }
        if(cnt>mx)
        {
            mx=cnt;
            val=head->val;
        }
        call(head->left, cnt+1);
        call(head->right, cnt+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        val=root->val;
        call(root, 0);
        return val;
 
    }
};
