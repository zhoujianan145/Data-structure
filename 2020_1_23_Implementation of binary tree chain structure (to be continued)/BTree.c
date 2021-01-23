#include"BTree.h"

BTNode* BinaryTreeCreate(BTDataType *a[] , int n, int *pi)
{
	if (*a[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;
	}
	BTNode* node = (BTNode*)malloc(sizeof(BTNode)*n);
	node->_data = *a[*pi];
	(*pi)++;
	node->_left = BinaryTreeCreate(a, n, pi);
	node->_right = BinaryTreeCreate(a, n, pi);

	return node;

}
//树的节点个数
int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	//自己加上左子树节点个数，加上右子树节点个数
	return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}
//前序遍历，根，左子树，右子树
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//用打印代表先遍历根节点
	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}
//中序遍历，左子树，根，右子树
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL");
		return ;
	}
	InOrder(root->_left);
	printf("%c", root->_data);
	InOrder(root->_right);
}
//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL");
		return ;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c", root->_data);
}
//求叶子节点
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}
//求树的深度
int TreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = TreeDepth(root->_left);
	int rightDepth = TreeDepth(root->_right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
//第K层节点的个数
int BinaryTreeLevelKsize(BTNode* root,int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
    
	return BinaryTreeLevelKsize(root->_left, k - 1) + BinaryTreeLevelKsize(root->_right, k - 1);

}
//寻找节点
BTNode* BinaryFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
	{
		return root;
	}
	//创建一次节点
	BTNode* node = BinaryFind(root->_left, x);
	//有可能为空
	if (node)
	{
		return node;
	}
	node = BinaryFind(root->_right, x);
	if (node)
	{
		return node;
	}
	return NULL;
	
}
void  DestoryTree(BTNode* root)
{
	if (root == NULL)
		return;
	DestoryTree(root->_left);
	DestoryTree(root->_right);
	free(root);

}