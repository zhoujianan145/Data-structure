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
//���Ľڵ����
int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	//�Լ������������ڵ�����������������ڵ����
	return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}
//ǰ�������������������������
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//�ô�ӡ�����ȱ������ڵ�
	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}
//���������������������������
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
//�������
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
//�������
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
		//���ֳ���֮ǰtypedef�ĺô�
		//����ͷ����ֵ�����һ���ڵ�
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
int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode * cur;
	int tag = 0;

	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);

		putchar(cur->_data);

		if (cur->_right && !cur->_left)
		{
			return 0;
		}

		if (tag && (cur->_right || cur->_left))
		{
			return 0;
		}

		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}

		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		else
		{
			tag = 1;
		}

		QueuePop(&qu);
	}

	QueueDestory(&qu);
	return 1;
}

//��Ҷ�ӽڵ�
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}
//���������
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
//��K��ڵ�ĸ���
int BinaryTreeLevelKsize(BTNode* root,int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
    
	return BinaryTreeLevelKsize(root->_left, k - 1) + BinaryTreeLevelKsize(root->_right, k - 1);

}
//Ѱ�ҽڵ�
BTNode* BinaryFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
	{
		return root;
	}
	//����һ�νڵ�
	BTNode* node = BinaryFind(root->_left, x);
	//�п���Ϊ��
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