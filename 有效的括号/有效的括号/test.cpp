#define  _CRT_SECURE_NO_WARNINGS    1	
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

typedef char STDataType;

class Stack
{
public:
	//初始化
	void STInit( )
	{
		arr = NULL;
		top = capacity = 0;
	}
	// 销毁栈
	void STDestroy( )
	{
		if (arr)
		{
			free(arr);
		}
		arr = NULL;
		top = capacity = 0;
	}

	// 入栈
	void STPush(  STDataType x)
	{
		if (top == capacity)
		{
			int newcapacity = capacity == 0 ? 4 : capacity * 2;
			//realloc申请一块连续的空间，空间不够异地扩容然后
			STDataType* tmp = (STDataType*)realloc(arr, sizeof(STDataType) * newcapacity);
			if (tmp == NULL)
			{
				perror("realloc fail\n");
				return;
			}
			arr = tmp;
			capacity = newcapacity;
		}
		arr[top++] = x;
	}
	//出栈
	void STPop( )
	{
		assert(!STEmpty());

		top--;
	}
	//取栈顶元素
	STDataType STTop( )
	{
		assert(!STEmpty( ));

		return arr[top - 1];
	}
	//获取栈中有效元素个数
	int STSize( )
	{
		return top;
	}
	//栈是否为空
	bool STEmpty( )
	{
		return top == 0;
	}


private:
	STDataType* arr;
	int top;
	int capacity;

};
class Solution {
public:
	bool isValid(string s) {
		int len = s.size();
		if (len % 2 == 1) return false;
		Stack st ;
		st.STInit();
		int i = 0;
		while (i < len)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				st.STPush(s[i]);
			}
			else
			{
				if (st.STEmpty())
				{
					return false;
				}
				if ( 
					(s[i] == ')' && st.STTop() == '(') ||
					(s[i] == ']' && st.STTop() == '[') ||
					(s[i] == '}' && st.STTop() == '{')
					)
				{
					st.STPop();
				}
				else
				{
					return false;
				}
			}
			i++;
		}
		return st.STEmpty();
	}
};

int main()
{
	string s = { "(){}}{" };
	Solution s1;
	bool ret=s1.isValid(s);
	

	return 0;
}