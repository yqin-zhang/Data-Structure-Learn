#define  _CRT_SECURE_NO_WARNINGS    1	
#include"SeqList.h"

//初始化
void SLInit(SL* ps)
{
	ps->capacity = ps->size = 0;
	ps->alist = NULL;
}
//销毁
void SLDestroy(SL* ps)
{
	if (ps->alist != NULL)
	{
		free(ps->alist);
	}
	ps->alist = NULL;
	ps->capacity = ps->size = 0;
}
//打印
void SLPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->alist[i]);
	}
	printf("\n");
}

//扩容
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		//先不要直接在alist上面扩容，有可能扩容失败
		//一般建议扩容为前者的两倍，两倍不是固定的，是实际上来说最合适的
		//考虑capacity为0的情况
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tamp = (SLDataType*)malloc(sizeof(SLDataType) * newcapacity);
		if (tamp == NULL)
		{
			exit(-1);
		}
		// 复制旧数据
		//注意拷贝旧数据到新内存
		if (ps->alist != NULL && ps->size > 0)
		{
			memcpy(tamp, ps->alist, ps->size * sizeof(SLDataType));
			free(ps->alist);  // 释放旧内存
		}

		ps->alist = tamp;
		ps->capacity = newcapacity;

	}
}

//头插
//向后移一位
//再插入
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	//从后面开始移动
	for (int i = ps->size; i > 0; i--)
	{
		ps->alist[i] = ps->alist[i - 1];
	}
	ps->alist[0] = x;
	ps->size++;
}
//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	//从后面开始移动
	ps->alist[ps->size++] = x;

}
//头删
void SLPopFront(SL* ps)
{
	assert(ps);
	//注意
	assert(ps->size > 0);
	//直接覆盖
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->alist[i] = ps->alist[i + 1];
	}
	ps->size--;
}
//尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}

//pos之前插入
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	assert(pos >= 0 && pos <= (ps->size));
	//先后移
	for (int i = ps->size; i > pos; i--)
	{
		ps->alist[i] = ps->alist[i - 1];

	}
	ps->alist[pos] = x;
	ps->size++;
}
//pos位置删除数据
void SLDelete(SL* ps, int pos)
{
	assert(ps);
	assert(ps->size > 0);

	assert(pos >= 0 && pos < (ps->size));
	//先后移
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->alist[i] = ps->alist[i + 1];

	}
	ps->size--;
}