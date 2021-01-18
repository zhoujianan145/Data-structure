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
bool isSametree(struct TreeNode* p, struct TreeNode* q)
{
    if(p==NULL&&q==NULL)
        return true;
    if(p==NULL&&q!=NULL)
        return false;
    if(p!=NULL&&q==NULL)
       return false;
    if(q->val!=p->val)
      return  false;

      return isSametree(p->left,q->left)&&isSametree(p->right,q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    if(s==NULL||t==NULL)
       return false;
//就可以判断正确了，没有其他情况
    if(isSametree(s,t)==true)
       return true;
//假如不相等，再让t和他的左右子树在判断
    return isSubtree(s->left,t)||isSubtree(s->right,t);

}
```

