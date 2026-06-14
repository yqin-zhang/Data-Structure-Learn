#include"Stack.h"
//初始化
void STInit(ST* ps)
{
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}
// 销毁栈
void STDestroy(ST* ps)
{
	assert(ps);
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}

// 入栈
void STPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//realloc申请一块连续的空间，空间不够异地扩容然后
		STDataType* tmp = (STDataType*)realloc(ps->arr, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			return;
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
	ps->arr[ps->top++] = x;
}
//出栈
void STPop(ST* ps)
{
	assert(!STEmpty(ps));

	ps->top--;
}
//取栈顶元素
STDataType STTop(ST* ps)
{
	assert(!STEmpty(ps));

	return ps->arr[ps->top - 1];
}
//获取栈中有效元素个数
int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
//栈是否为空
bool STEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}