#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
};
struct test
{
	int ip1[30],len1,ip2[30],len2,size, op[30];
}
testCase[10] = {
	{ {1,2,3},3, {4,5,6},3, 6,{1,2,3,4,5,6} },
	{ {1,2,6},3, {3,4,5},3,6 ,{1,2,3,4,5,6} },
	{ {7,8,9,10},4 ,{1,2,3},3 ,7,{1,2,3,7,8,9,10} },
	{ { -3, -2, -1 }, 3, { -6, -5, -4 }, 3, 6, {-6,-5,-4,-3,-2,-1} },
	{ {-6,-1},2, {-5,-4,-3,-2},5,7 ,{-6,-5,-4,-3,-2,-1} }
};
struct node * create(struct node * head, int *given, int size)
{
	int i, n;
	struct node *prev;
	for (i = 0; i < size; i++)
	{
		struct node * newNode = (struct node*)malloc(sizeof(struct node));
		newNode->num = given[i];
		if (head == NULL)
		{
			head = newNode;
			prev = head;
		}
		prev->next = newNode;
		prev = newNode;
		newNode->next = NULL;
	}
	return head;
}
struct node* merge(struct node *h1, struct node *h2)
{
	struct node *res=NULL;
	if (h1 == NULL)return h2;
	if (h2 == NULL)return h1;
	if (h1->num < h2->num)
	{
		res = h1;
		res->next = merge(h1->next, h2);
	}
	else
	{
		res = h2;
		res->next = merge(h1, h2->next);
	}
	return res;
}
/*
method 2 : using insertion.
*/
struct node * merge2(struct node *h1, struct node *h2)
{
	struct node *start1 = h1, *prev=h1, *start2 = h2;
	int ins = 0, flag = 0;
	while (h2 != NULL)
	{
		while (h1 != NULL && (h2->num <= h1->num))
		{
			flag++;
			prev = h1;
			h1 = h1->next;
		}
		if (h1 == NULL)
		{
			prev->next = h2;
			break;
		}
		if (flag != 0)
		{
			prev->next = h2;
			h2->next = h1;
		}
		else
		{
			h2->next = start1;
			start1 = h2;
		}
		h2 = h2->next;
	}
	return h2;
}
int compare(struct node *given, struct node *result)
{
	int flag = 0;
	struct node * temp = given;
	while (temp != NULL)
	{
		if (temp->num != result->num)
		{
			flag++;
			break;
		}
		temp = temp->next;
		result = result->next;
	}
	if (flag>0)return 0;
	else return 1;
}
void testMethods()
{
	int i, x;
	struct node *head = NULL, *given1,*given2 ,*should_be, *output;
	for (i = 0; i<6; i++)
	{
		given1 = create(head, testCase[i].ip1, testCase[i].len1);
		given2 = create(head, testCase[i].ip2, testCase[i].len2);
		output = merge(given1, given2);
		head = NULL;
		should_be = create(head, testCase[i].op, testCase[i].size);
		x = compare(should_be, output);
		x?printf("Passed\n"):printf("\n failed");
	}
}
int main()
{
	testMethods();
	getchar();
	return 0;
}
