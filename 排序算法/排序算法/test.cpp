#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
#include<vector>
using namespace std;

////直接插入排序
//void InsertSort(vector<int>& arr)
//{
//	int len = arr.size();
//	for (int i = 1; i < len; i++)
//	{
//		int end = i - 1;
//		int tmp = arr[i];
//		while (end>=0&& arr[end] > tmp)
//		{
//			arr[end + 1] = arr[end];
//			end--;
//		}
//		arr[end + 1] = tmp;
//	}
//}
//
//
////希尔排序
//void ShellSort(vector<int>& arr)
//{
//	int len = arr.size();
//	int gap = len;
//	while (gap>1)
//	{
//		gap = gap / 3 + 1;//4 2 1
//		for (int i = 1; i <= len - gap; i++)
//		{
//			int end = i - 1;
//			int tmp = arr[end + gap];
//			while (end >= 0 && arr[end] > tmp)
//			{
//				arr[end + gap] = arr[end];
//				end -= gap;
//			}
//			arr[end + gap] = tmp;
//		}
//	}
//
//}

////直接选择排序
//void SelectSort(vector<int>& arr)
//{
//	int len = arr.size();
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

////直接选择排序--升级版
//void SelectSort(vector<int>& arr)
//{
//	int len = arr.size();
//	int begin = 0;
//	int end = len - 1;
//	//遍历mini找最小的元素
//	while (begin < end)
//	{
//		int mini = begin;
//		int maxi = end;
//		// 在 [begin, end] 范围内找最小和最大值
//		for (int i = begin + 1; i <= end; i++)
//		{
//			if (arr[i] < arr[mini])
//				mini = i;
//			if (arr[i] > arr[maxi])
//				maxi = i;
//		}
//
//		//两次交换，注意特殊处理
//		swap(arr[begin], arr[mini]);
//
//		//增加一个判断即可
//		if (begin == maxi)
//		{
//			maxi = mini;
//		}
//		swap(arr[end], arr[maxi]);
//
//		begin++;
//		end--;
//	}
//}
//
//void AdjustDown(vector<int>& arr,int size,int parent)
//{
//	int child = parent * 2 + 1;
//	while (child<size)
//	{
//		//>：找最小堆
//		//先确定左右孩子最小值
//		if (child + 1 <size&& arr[child] > arr[child + 1])
//		{
//			child++;
//		}
//		//如果比父亲节点还小就交换
//		if (arr[parent] > arr[child])
//		{
//			swap(arr[parent], arr[child]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			return;
//		}
//	}
//}
//
////堆排序
//void HeapSort(vector<int>& arr)
//{
//	int size = arr.size();
//	//向下调整算法
//	for (int i = (size - 1 - 1)/2; i >=0 ; i--)
//	{
//		AdjustDown(arr, size,i);
//	}
//
//	int end = size - 1;
//	while (end>0)
//	{
//		swap(arr[0], arr[end]);
//		//已经建好堆了，交换第一个元素到最后，end--，从下标为0开始向下调整
//		AdjustDown(arr, end, 0);
//		end--;
//	}
//}

//int _QuickSort(vector<int>& arr, int left, int right)
//{
//	int key = left;
//	left++;
//	while (left <= right)
//	{
//		while (left <= right&&arr[left] < arr[key])
//		{
//			left++;
//		}
//		while (left <= right&&arr[right] > arr[key])
//		{
//			right--;
//		}
//		if (left <= right)
//		{
//			swap(arr[left++], arr[right--]);
//		}
//	}
//	swap(arr[key], arr[right]);
//	return right;
//}

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

////挖坑法
//int _QuickSort1(vector<int>& arr, int left, int right)
//{
//	int hole = left;
//	int key = arr[hole];
//	int left = left;
//	int right = right;
//	while (left < right)
//	{
//		while (left < right && arr[right] > key)
//		{
//			right--;
//		}
//		arr[hole] = arr[right];
//		hole = right;
//		while (left < right && arr[left] < key)
//		{
//			left++;
//		}
//		arr[hole] = arr[left];
//		hole = left;
//
//	}
//	arr[hole] = key;
//	return hole;
//}

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


int main()
{
	vector<int> arr = { 6,1,2,7,9,3,4,5,10,8 };
	//InsertSort(arr);
	//ShellSort(arr);
	//SelectSort(arr);
	QuickSort(arr, 0, arr.size()-1);
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
	return 0;
}