#include "sort.h"

void InsertSort(int* a, int n)
{
	int end;
	int temp=a[end+1];
	while (end <= 0)
	{
		if (temp < a[end])
		{
			a[end + 1] = a[end];
		}
		else
		{
			break;
		}

	}
	a[end + 1] = temp;
}