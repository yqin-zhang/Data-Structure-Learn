#define  _CRT_SECURE_NO_WARNINGS    1	
#include"SeqList.h"


int main()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);

	SLInsert(&sl, 0, 99);
	SLPrint(&sl);
	SLInsert(&sl, 3, 100);
	SLPrint(&sl);

	SLDelete(&sl, 0);
	SLPrint(&sl);

	SLDelete(&sl, 2);
	SLPrint(&sl);

	SLDestroy(&sl);
	return 0;
}






