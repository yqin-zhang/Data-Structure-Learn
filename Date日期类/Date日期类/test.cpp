#include"Date.h"

int main()
{
	Date d1;
	d1 += 1;
	cout << d1;
	cin >> d1;
	Date* p = &d1;
	cout << &d1 << endl;
	return 0;
}