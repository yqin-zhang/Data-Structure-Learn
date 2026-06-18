#include"Heap.h"
//初始化
void HeapInit(HNode* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}
//销毁
void HeapDestroy(HNode* php)
{
	if (php->a)
	{
		free(php->a);
	}
	php->a = NULL;
	php->size = php->capacity = 0;
}
//入堆
void HeapPush(HNode* php, HDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HDataType* tmp = (HDataType*)realloc(php->a, sizeof(HDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			return;
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size++] = x;
	AdjustUp(php->a, php->size - 1);
}
// 删除堆顶的数据
int HeapPop(HNode* php)
{
	assert(php);
	assert(!HPEmpty(php));
	int ret = php->a[0];
	std::swap(php->a[0], php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size,0);
	return ret;
}

// 判空
bool HPEmpty(HNode* php)
{
	assert(php);
	return php->size == 0;
}
//求size
int HPSize(HNode* php)
{
	assert(php);
	return php->size;
}
void AdjustUp(HDataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		//小堆，大堆换为>
		if (arr[child] < arr[parent])
		{
			std::swap(arr[child], arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			return;
		}
	}
}
//向下调整算法
//交换：堆顶和最后一个数据交换
void AdjustDown(HDataType* arr, int size,int parent)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		// 需要先判断右孩子是否存在，如果存在且大于左孩子，则child指向右孩子

		if (child + 1 < size && arr[child + 1] < arr[child])
		{
			child++;
		}
		//<:建小堆
		if (arr[child] < arr[parent])
		{
			std::swap(arr[child], arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			return;
		}
	}
}


