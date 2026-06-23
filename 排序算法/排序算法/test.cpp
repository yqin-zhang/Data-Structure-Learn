#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
#include<vector>
using namespace std;

//直接插入排序
void InsertSort(vector<int>& arr)
{
	int len = arr.size();
	for (int i = 1; i < len; i++)
	{
		int end = i - 1;
		int tmp = arr[i];
		while (end>=0&& arr[end] > tmp)
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = tmp;
	}
}


//希尔排序
void ShellSort(vector<int>& arr)
{
	size_t len = arr.size();
	int gap = len;
	while (gap>1)
	{
		gap = gap / 3 + 1;//4 2 1
		for (int i = 1; i <= len - gap; i++)
		{
			int end = i - 1;
			int tmp = arr[end + gap];
			while (end >= 0 && arr[end] > tmp)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = tmp;
		}
	}

}

////直接选择排序
//void SelectSort(vector<int>& arr)
//{
//	size_t len = arr.size();
//	for (int i = 0; i < len; i++)
//	{
//		int mini = i+1;//基于i
//		int tmp = i;
//		//遍历mini找最小的元素
//		while (mini<len)
//		{
//			//当前的最小值作比较
//			if (arr[tmp]> arr[mini])
//			{
//				tmp = mini;
//			}
//			mini++;
//		}
//		swap(arr[i], arr[tmp]);
//	}
//}

//直接选择排序--升级版
void SelectSort(vector<int>& arr)
{
	size_t len = arr.size();
	int begin = 0;
	int end = len - 1;
	//遍历mini找最小的元素
	while (begin < end)
	{
		int mini = begin;
		int maxi = end;
		// 在 [begin, end] 范围内找最小和最大值
		for (int i = begin + 1; i <= end; i++)
		{
			if (arr[i] < arr[mini])
				mini = i;
			if (arr[i] > arr[maxi])
				maxi = i;
		}

		//两次交换，注意特殊处理
		swap(arr[begin], arr[mini]);

		//增加一个判断即可
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(arr[end], arr[maxi]);

		begin++;
		end--;
	}
}

void AdjustDown(vector<int>& arr,int size,int parent)
{
	int child = parent * 2 + 1;
	while (child<size)
	{
		//>：找最小堆
		//先确定左右孩子最小值
		if (child + 1 <size&& arr[child] > arr[child + 1])
		{
			child++;
		}
		//如果比父亲节点还小就交换
		if (arr[parent] > arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

//堆排序
void HeapSort(vector<int>& arr)
{
	int size = arr.size();
	//向下调整算法
	for (int i = (size - 1 - 1)/2; i >=0 ; i--)
	{
		AdjustDown(arr, size,i);
	}

	int end = size - 1;
	while (end>0)
	{
		swap(arr[0], arr[end]);
		//已经建好堆了，交换第一个元素到最后，end--，从下标为0开始向下调整
		AdjustDown(arr, end, 0);
		end--;
	}
}

int _QuickSort(vector<int>& arr, int left, int right)
{
	int key = left;
	left++;
	//重复值也进入循环，直接再交换一遍
	while (left <= right)
	{
		while (left <= right&&arr[left] < arr[key])
		{
			left++;
		}
		while (left <= right&&arr[right] > arr[key])
		{
			right--;
		}
		if (left <= right)
		{
			swap(arr[left++], arr[right--]);
		}
	}
	swap(arr[key], arr[right]);
	return right;
}

//双指针法
int _QuickSort2(vector<int>& arr, int left, int right)
{
	int prev = left;
	int cur = prev + 1;
	int key = left;
	while (cur <= right)
	{
		if (arr[cur] <= arr[key] && ++prev != cur)
		{
			swap(arr[prev], arr[cur]);
		}
		++cur;
	}
	swap(arr[prev], arr[key]);
	return prev;
}

//挖坑法
int _QuickSort1(vector<int>& arr, int left, int right)
{
	int hole = left;
	int key = arr[hole];

	while (left < right)
	{
		//有重复值时直接跳过
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		arr[hole] = arr[right];
		hole = right;
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		arr[hole] = arr[left];
		hole = left;

	}
	arr[hole] = key;
	return hole;
}

//快速排序
void QuickSort(vector<int>& arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	//找基准值
	int keyi = _QuickSort2(arr, left, right);
	//二分
	//[left,keyi-1] keyi [keyi+1,right]
	//[0,2] 3 [4,5]
	QuickSort(arr, left, keyi - 1);
	QuickSort(arr, keyi + 1, right);
}
// 归并排序 - 分治合并
void _MergeSort(vector<int>& arr, int left, int right, vector<int>& tmp)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;

	// 递归分解左右两部分
	_MergeSort(arr, left, mid, tmp);      // 左区间 [left, mid]
	_MergeSort(arr, mid + 1, right, tmp); // 右区间 [mid+1, right]

	// 合并 [left, mid] 和 [mid+1, right]
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;  // 临时数组的起始索引

	// 合并两个有序子数组到临时数组
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}

	// 处理剩余元素
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}

	// 将临时数组数据拷贝回原数组
	for (int i = left; i <= right; i++)
	{
		arr[i] = tmp[i];
	}
}

// 归并排序入口
void MergeSort(vector<int>& arr)
{
	int n = arr.size();
	if (n <= 1) return;

	vector<int> tmp(n);  // 创建临时数组
	_MergeSort(arr, 0, n - 1, tmp);
}

//计数排序
void CountSort(vector<int>& arr)
{
	int n = arr.size();
	if (n <= 1) return;
	int min = arr[0], max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	//此时min,max已经知道
	//建立数组
	int range = max - min + 1;
	vector<int> count(range);

	//存入count计数
	for (int i = 0; i < n; i++)
	{
		count[arr[i] - min]++;
	}
	//还原到arr中
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			arr[j++] = i + min;
		}
	}

}

void TestOP()
{
	srand(time(0));
	const int N = 100000;
	vector<int> a1(N);
	vector<int> a2(N);
	vector<int> a3(N);
	vector<int> a4(N);
	vector<int> a5(N);
	vector<int> a6(N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		//a7[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2);
	int end2 = clock();
	int begin3 = clock();
	SelectSort(a3);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4);
	int end4 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	int begin6 = clock();
	MergeSort(a6);
	int end6 = clock();
	int begin7 = clock();
	//BubbleSort(a7, N);
	//int end7 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);


}
int main()
{

	TestOP();

	return 0;
}
//InsertSort:22917
//ShellSort : 37
//SelectSort : 32668
//HeapSort : 42
//QuickSort : 29
//MergeSort : 38