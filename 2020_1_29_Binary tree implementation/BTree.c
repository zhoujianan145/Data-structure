#include"BTree.h"

BTNode* BinaryTreeCreate(BTDataType *a , int n, int *pi)
{
	if (a[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;
	}
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = a[*pi];
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
		printf("NULL ");
		return ;
	}
	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}
//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return ;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);
}
//层序遍历
void LevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q,root);
	while (!QueueEmpty(&q))
	{
		//体现出来之前typedef的好处
		//队列头结点的值变成了一个节点
		QDataType front = QueueFront(&q);
		QueuePop(&q);
		
		printf("%c ", front->_data);
		if (front->_left)
		{
			QueuePush(&q,front->_left);
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}
}
//判断是否完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	//空树也是完全二叉树
	if (root == NULL)
	{
      return 1;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		QueuePop(&q);
		//A B C D E NULL NULL NULL NULL NULL
		////出最后一个e时，二叉树的NULL全部入了队列然后判断对列里的数据有没有不是空的，有就不是完全二叉树
		//然后继续走遇到空就退出
		if (front == NULL)
			break;
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
		

	}
	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestory(&q);
			return 0;
		}
	}
	QueueDestory(&q);
	return 1;
		
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
