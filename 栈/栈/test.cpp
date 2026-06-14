#include"Stack.h"


int main()
{
	ST st;
	STInit(&st);
	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);

	STDataType a = STTop(&st);
	printf("%d ", a);
	int t = STSize(&st);
	printf("%d ", a);

	STPop(&st);
	STPop(&st);
	STPop(&st);

	STDestroy(&st);
	return 0;
}