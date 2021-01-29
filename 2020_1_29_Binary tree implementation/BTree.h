#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<assert.h>
#include"Queue.h"


typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;


//创建一个树
BTNode* BinaryTreeCreate(BTDataType *a,int n,int *pi);
//求节点的个数
int TreeSize(BTNode* root);
//求树的深度
int TreeDepth(BTNode* root);
//求叶子节点
int TreeLeafSize(BTNode* root);
//前序遍历
void PrevOrder(BTNode* root);
//后序遍历
void PostOrder(BTNode* root);
//中序遍历，左子树，根，右子树
void InOrder(BTNode* root);

//判断完全二叉树
int BinaryTreeComplete(BTNode* root);
//层序遍历
void LevelOrder(BTNode* root);
//求第K层节点的个数
int BinaryTreeLevelKsize(BTNode* root,int k);
//查找节点
BTNode* BinaryFind(BTNode* root,BTDataType x);
//销毁,后序销毁
void  DestoryTree(BTNode* root);