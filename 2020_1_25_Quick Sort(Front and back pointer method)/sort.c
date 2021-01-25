//����ȡ�У��Ż�����������
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
//��������
int  PartSort(int *a, int begin, int end)
{
	//֮ǰ�������������������������ˡ���������Ż��汾ʱ�临�ӶȾͺ��������ô�ͳ���O��n*log N��
	int midIndex = GetMidIndex(a, begin, end);
	int kIndex = end;
	Swap(&a[midIndex], &a[kIndex]);
	
	while (begin < end)
	{
		//begin�������ұȱ��ֵ��ģ��ҵ�ͣ�������Ҳ�����++
		//���ˣ�һ��ʼ�õ�if��䣬��һ�ξͰ��˼�ĩβ��������,���������һ�����ҵ�ֵͣ�����ڽ�����
		while (begin<end && a[begin] <=a[kIndex])
		{
			//�Ҳ���a[begin]>a[k]��һֱ��
			begin++;
		}
		//end��С
		//�����������治����begin<end,��ô���һ������while�����Ļ�,end�ͼ���--�����������������������ͣ����
		while (begin<end && a[end] >= a[kIndex])
		{
			end--;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[kIndex]);
	//�ָ����������λ��
	return begin;
}

void QuickSort(int *a, int left, int right)
{
	// ������
	assert(a);
	if (left>=right)
		return;
	//���ŵ�һ��      [left    div   right] 
	int div = PartSort(a, left, right);
	//����ߵ�����   [left,div-1]
	QuickSort(a,left,div);
	//���ұߵ�����   [right,div+1]
	QuickSort(a, div + 1, right);
}