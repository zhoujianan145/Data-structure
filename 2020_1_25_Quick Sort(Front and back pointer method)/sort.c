//三数取中，优化排序，最坏的情况
int GetMidIndex(int*a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[end])
	{
		if (a[mid]<a[begin])
		{
			return mid;
		}
		else if (a[end] < a[mid])
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
	//a[begin]>=a[end]
	else
	{
		if (a[end] > a[mid])
		{
			return end;
		}
		else if (a[mid] > a[begin])
		{
			return begin;
		}
		else
		{
			return mid;
		}
	}
}
//单趟排序
int  PartSort(int *a, int begin, int end)
{
	//之前就像进行排序，最坏的情况不会出现了。所以这个优化版本时间复杂度就忽略最坏，那么就成了O（n*log N）
	int midIndex = GetMidIndex(a, begin, end);
	int kIndex = end;
	Swap(&a[midIndex], &a[kIndex]);
	
	while (begin < end)
	{
		//begin向右走找比标记值大的，找到停下来，找不到就++
		//晕了，一开始用的if语句，第一次就把人家末尾给交换了,你的需求是一起走找到值停下来在交换。
		while (begin<end && a[begin] <=a[kIndex])
		{
			//找不到a[begin]>a[k]就一直走
			begin++;
		}
		//end找小
		//假如在这里面不加上begin<end,那么最后一步满足while条件的话,end就继续--，而不是我们想的在相遇点停下来
		while (begin<end && a[end] >= a[kIndex])
		{
			end--;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[kIndex]);
	//分割两个区间的位置
	return begin;
}

void QuickSort(int *a, int left, int right)
{
	// 闭区间
	assert(a);
	if (left>=right)
		return;
	//先排第一趟      [left    div   right] 
	int div = PartSort(a, left, right);
	//排左边的区间   [left,div-1]
	QuickSort(a,left,div);
	//排右边的区间   [right,div+1]
	QuickSort(a, div + 1, right);
}