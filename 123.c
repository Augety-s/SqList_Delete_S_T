#include<stdio.h>
#include<stdbool.h>
#define MaxSize 50
typedef struct{
	int data[MaxSize];
	int length;
}SqList;
void ListInit(SqList *L){
	L->length = 0;
	for (int i = 0; i < MaxSize; i++)
		L->data[i] = 0;

}
bool ListInsert(SqList* L, int i, int e) {
	if (i<1 || i>L->length + 1)
	{

		return false;
	}
	if (L->length >= MaxSize)
		return false;
	for (int j = L->length; j >= i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}

void List_Printf(SqList* L) {
	for (int i = 0; i < L->length; i++)
		printf("%d  ", L->data[i]);
	printf("\n顺序表的长度为%d\n\n\n", L->length);
}
//bool Delete_s_t(SqList* L, int s, int t) {                 //a pile of shit
//	if (L->length == 0 || t <= s)
//		return false;
//	int i, j;
//	for (i=0; L->data[i] < s; i++)
//		if (i > L->length-1)
//			return false;
//	for (j=0; L->data[j] < t; j++)
//		if (j > L->length-1)
//			j=L->length-1;
//	int temp1 = i;
//	int temp2 = j;
//	for (int temp = 0; temp < L->length - j + i - 1; temp++)
//	{
//		L->data[temp1] = L->data[temp2 + 1];
//		temp1++;
//		temp2++;
//	}
//
//	L->length -= j - i + 1;
//	return true;
//
//}
bool Delete_s_t(SqList* L, int s, int t) {
	int i, j;
	if (s >= t || L->length == 0)
		return false;
	for (i = 0; L->data[i] < s && i < L->length; i++);
	if (i >= L->length)
		return false;
	for (j = i; L->data[j]<=t && j < L->length; j++);
	for (; j < L->length; i++, j++)
		L->data[i] = L->data[j];
	L->length = i;
	return true;
}
int main()
{
	SqList list;
	SqList *L=&list;
	ListInit(L);
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);
	ListInsert(L, 4, 4);
	ListInsert(L, 5, 5);
	int value=0;
	int* a = &value;
	Delete_s_t(L, 3,5);
	List_Printf(L);
	return 0;
}
