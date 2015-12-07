#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
};
struct test
{
	
	int ip[30],size, node, op[30];

}
testCase[11] = 
{ { { 1, 2, 3, 3, 3, 4, 5, 5 }, 8, 4, }, { { 1, 2, 3, 4 }, 4, 5, { 1, 2, 3, 4, 5 } },

{ { 2, 3, 4, 5 }, 4, 1, { 1, 2, 3, 4, 5 } }, { { 1, 3, 4, 5 }, 4, 2, { 1, 2, 3, 4, 5 } },
 { { 1, 2, 4, 5 }, 4, 3, {1, 2, 3, 4, 5} },

 { { 2, 2, 2, 2, 3 }, 2, 2, { 2, 2, 2, 2, 2, 3 } } ,{ { 1, 2, 3, 5 }, 4, 4, { 1, 2, 3, 4, 5 } },
 { { 1, 1, 1 }, 3, 1, { 1, 1, 1, 1 } }, { 1, 2, 3, 3, 3, 4, 4, 5, 5 },
 { { 1, 2, 2, 3 }, 4, 2, { 1, 2, 2, 2, 3 } },
 { { 1, 2, 3, 3, 3 }, 5, 3, { 1, 2, 3, 3, 3, 3 } }, };

struct node * create(struct node * head, int *given, int size)
{
	int i, n;
	struct node *temp;
	if (size == 0)return head;
	struct node * new;
	for (i = 0; i < size; i++)
	{
		new = (struct node*)malloc(sizeof(struct node));
		new->num = given[i];
		if (head == NULL)
		{
			head = new;
			temp = head;
		}
		temp->next = new;
		temp = new;
		new->next = head;
	}
	return head;
}
int compare(struct node *given, struct node *result)
{
	struct node * start = given;
	while (given!=start)
	{
		if (given->num != result->num)return 0;
		given = given->next;
		result = result->next;
	}
	return 1;
}
struct node * insert(struct node *head,int val)
{
	struct node *cur, *prev;
	cur = head; prev = head;
	int flag = 0, fn = 0;
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->num = val;
	if (head == NULL)
	{
		head = new;
		new->next = head;
	}
	else
	{
		while (cur->next != head)
		{
			if (cur == head && new->num < head->num)fn++;
			else if (new->num <= cur->num && cur != head && fn == 0)
			{
				prev->next = new;
				new->next = cur;
				flag++;
				break;
			}
			prev = cur;
			cur = cur->next;
		}
		if (fn==1)
		{
			new->next = head;
			head = new;
			cur->next = head;
		}
		else if (flag==0)
		{
			if (new->num <= cur->num)
			{
				prev->next = new;
				new->next = cur;
			}
			else
			{
				cur->next = new;
				new->next = head;
			}
		}
	}
	return head;
}
void testMethods()
{
	int i, x;
	struct node *head = NULL, *given,*should_be,*output;
	for (i = 0; i<10; i++)
	{
		given = create(head, testCase[i].ip, testCase[i].size);
		output = insert(given,testCase[i].node);
		head = NULL; 
		should_be = create(head, testCase[i].op, (testCase[i].size) + 1);
		x = compare(should_be, output);
		x?printf("\n Passed"):printf("\n Failed");
	}
}
int main()
{
	testMethods();
	getchar();
	return 0;
}
