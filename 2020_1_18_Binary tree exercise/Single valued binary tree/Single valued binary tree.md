```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isUnivalTree(struct TreeNode* root){
    //递归出口。当没有节点或者有一个节点返回true
    //当有一个节点时return true&&true
    if(root==NULL)
    return true;
    //当前的树，左子树存在且val不等于root的val
    if(root->left&&root->val!=root->left->val)
    return false;
    //当前的树，右子树存在且val不等于root的val
    //如果条件写成相等，return true的话会报错，因为你只是比较了当前的节点，还有后面的节点没判断
    if(root->right&&root->val!=root->right->val)
    return false;
    //递归判断左右子树
    return isUnivalTree(root->left)&&isUnivalTree(root->right);
    //分而治之思想，先把 isUnivalTree(root->left) 函数的结果递归完成，在递归判断isUnivalTree(root->right)结果
}
```