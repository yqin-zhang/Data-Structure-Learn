#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
	// 友元函数声明，任意位置都可以，一般放在最开头
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 2020, int month = 1, int day = 1);
	bool CheckDate()const;

	//剩下三种可不用实现
	//没有申请资源
	//根据年月判断天数
	//短小的函数，直接定义在类中，内联函数，不展开栈帧
	int GetMonthDay(int year, int month) const
	{
		assert(month > 0 && month < 13);
		static int monthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//四年一润，百年不润，四百年一润
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return monthday[month];
	}
	//运算符重载，除了赋值运算符必须重载在类里面，其他可重载在外面
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	// d1 += 天数
	Date& operator+=(int day);
	Date operator+(int day) const;
	// d1 -= 天数
	Date& operator-=(int day);
	Date operator-(int day) const;
	// d1 - d2
	int operator-(const Date& d) const;
	// ++d1 -> d1.operator++()
	Date& operator++();
	// d1++ -> d1.operator++(0)
	// 为了区分，构成重载，给后置++，强行增加了一个int形参
	// 这里不需要写形参名，因为接收值是多少不重要，也不需要用
	// 这个参数仅仅是为了跟前置++构成重载区分
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	// 流插入
	// 不建议，因为Date* this占据了⼀个参数位置，使用d<<cout不符合习惯
	//void operator<<(ostream& out);

private:
	int _year;
	int _month;
	int _day;
};
//iostream不支持拷贝，只能引用
ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);