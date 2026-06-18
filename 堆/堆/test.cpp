#include"Heap.h"
//O(N*logN)
void HeapSort(int* arr, int n)
{
	//建立一个有效的堆(小堆)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, n, i);
	}
	//堆排序
	int end = n - 1;
	while (end>0)
	{
		std::swap(arr[0], arr[end]);//堆顶放在末尾
		AdjustDown(arr, end, 0);//调整剩余元素
		end--;
	}
}
void test()
{
	int arr[] = { 10, 20, 15, 30, 40, 25, 5, 1, 100, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "排序前: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// 调用堆排序
	HeapSort(arr, n);

	cout << "排序后: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}
int main()
{

	test();
	return 0;
}

//int main()
//{
//	HNode ph;
//	HeapInit(&ph);
//	HeapPush(&ph, 1);
//	HeapPush(&ph, 2);
//	HeapPush(&ph, 3);
//	HeapPush(&ph, 4);
//	//升序小堆，降序大堆
//	while (!HPEmpty(&ph))
//	{
//		printf("%d ", HeapPop(&ph));
//	}
//	
//
//	HeapDestroy(&ph);
//	return 0;
//}