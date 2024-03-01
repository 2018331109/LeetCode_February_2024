  GNU nano 6.2                                            Day-29_BFS.cpp *                                                    
/*
1609. Even Odd Tree
A binary tree is named Even-Odd if it meets the following conditions:

    The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, >
    For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to r>
    For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to r>

Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.
*/

class Solution
{
public:
    int f = 0;
    bool call(TreeNode* head)
    {
        queue<TreeNode*> q;
        q.push(head);
        while (!q.empty())
        {
            TreeNode* temp = q.front();
            int pre = temp->val;
            q.pop();
            if ((f == 0 and pre % 2 == 0) || (f == 1 and pre % 2))
            {
                return false;
            }
            int sz = q.size();
            if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            while (sz--)
            {
                temp = q.front();
                if (f == 0 and (temp->val % 2 == 0 || temp->val <= pre))
                {
                    return false;
                }
                if (f == 1 and (temp->val % 2 || temp->val >= pre))
                {
                    return false;
                }
                pre = temp->val;
                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
                q.pop();
            }
            f ^= 1;
        }
        return true;
    }

    bool isEvenOddTree(TreeNode* root)
    {
        return call(root);
    }
};
