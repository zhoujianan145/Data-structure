```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;
struct TreeNode* invertTree(struct TreeNode* root){
      if(root==NULL)
      {
      return NULL;
      }
    //   else
    //   {
    //       //交换思想
    //       TreeNode* tmp=root->left;
    //       root->left=root->right;
    //       root->right=tmp;
    //   } 
    //   invertTree(root->left);
    //   invertTree(root->right);
    //   return root;
    else
    {
        TreeNode* right=root->right;
        //利用返回值，把子树连接在后面
        root->right=invertTree(root->left);
        root->left=invertTree(right);
        return root;
    }
}
```

