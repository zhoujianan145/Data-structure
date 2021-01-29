#include"BTree.h"

void test(BTNode* root)
{
	PrevOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	LevelOrder(root);
}
void test1(BTNode* root)
{
	int size = TreeSize(root);
	printf("%d\n", size);
	int depth = TreeDepth(root);
	printf("%d\n", depth);
	int Lsize = TreeLeafSize(root);
	printf("%d\n", Lsize);
	int Ksize = BinaryTreeLevelKsize(root,2);
	printf("%d\n", Ksize);
	BTNode* node = BinaryFind(root, 'A');
	printf("%c\n", root->_data);
	

}
int main()
{
	/*BTDataType* arr[] = { "A","B","D","#","#","E","#","H","#","#","C","F","#","#","G","#","#"};*/
	BTDataType arr[] = "ABD##E#H##CF##G##";
	int n = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	BTNode* root = BinaryTreeCreate(arr, n, &i);
	test(root);
	/*test1(root);*/
	system("pause");
	return 0;
}