#include"BTree.h"

int main()
{
	BTDataType* arr[] = { "A","B","D","#","#","E","#","H","#","#","C","F","#","#","G","#","#"};
	int n = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	BTNode* root = BinaryTreeCreate(arr, n, &i);
	PrevOrder(root);
	system("pause");
	return 0;
}