#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
	int visit;
};
struct test
{
	int input[30];
	int size;
	float output;
}testCase[10] = { { { 4, 2 }, 2, 3.0 }, { {250},1,250.0},
{ { 234, -32, 31, 17, 123, 135 }, 6, 24.0}, {{124,232,420,10310,23445},5,420.0},
{ { -10, -10, 0 }, 3, -10.0} };

struct node * create(struct node * head,int *arr,int size)
{
	int i, n;
	struct node *prev;
	for (i = 0; i < size; i++)
	{
		struct node * new = (struct node*)malloc(sizeof(struct node));
		new->num = arr[i];
		if (head == NULL)
		{
			head = new;
			prev = head;
		}
		prev->next = new;
		prev = new;
		new->next = NULL;
	}
	return head;
}
int compare(float expected,float observed )
{
	if (expected == observed)return 1;
	else return 0;
}
float median2(struct node * head)
{
	struct node *one, *two, *prev;
	one = head;
	two = head;
	prev = head;
	if (head == NULL)return -1;
	if (head->next == NULL)return head->num;
	while (two != NULL && two->next != NULL)
	{
	prev = one;
	one = one->next;
	two = two->next->next;
	}
	if (two == NULL)return (((prev->num) + (one->num)))*(1.0) / 2;
	return one->num;
}

void testMethods()
{
	int i,x;
	float median;
	struct node *head=NULL,*arr;
	for (i = 0; i < 5; i++)
	{
		arr = create(head, testCase[i].input, testCase[i].size);
		median = median2(arr);
		x = compare(testCase[i].output, median);
		x?printf("\n Passed"):printf("\n Failed");
	}
}
int main()
{
	testMethods();
	getchar();
	return 0;
}



