```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(root==NULL)
    return 0;
    //用变量保存起来减少递归次数
    int leftDepth=maxDepth(root->left);
    int rightDepth=maxDepth(root->right);
    return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
}
```

