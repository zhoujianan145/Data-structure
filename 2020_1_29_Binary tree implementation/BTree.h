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


//����һ����
BTNode* BinaryTreeCreate(BTDataType *a,int n,int *pi);
//��ڵ�ĸ���
int TreeSize(BTNode* root);
//���������
int TreeDepth(BTNode* root);
//��Ҷ�ӽڵ�
int TreeLeafSize(BTNode* root);
//ǰ�����
void PrevOrder(BTNode* root);
//�������
void PostOrder(BTNode* root);
//���������������������������
void InOrder(BTNode* root);

//�ж���ȫ������
int BinaryTreeComplete(BTNode* root);
//�������
void LevelOrder(BTNode* root);
//���K��ڵ�ĸ���
int BinaryTreeLevelKsize(BTNode* root,int k);
//���ҽڵ�
BTNode* BinaryFind(BTNode* root,BTDataType x);
//����,��������
void  DestoryTree(BTNode* root);