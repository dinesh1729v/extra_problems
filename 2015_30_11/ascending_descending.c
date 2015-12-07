#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
};
struct test
{
	int ip[30], size, op[30];
}testCase[10] =
{
	{ { 1, 2, 6, 4 }, 4, { 1, 2, 4, 6 } },
	{ { 1, 2, 3, 4, 5 }, 5, { 1, 2, 3, 4, 5 } },
	{ {1,2,3,4,5,6,10,9,8,7}, 10,{1,2,3,4,5,6,7,8,9,10} },
	{ { 1, 2, 3, 4, 7, 6 }, 6, { 1, 2, 3, 4, 6, 7 } },
	{ { 1, 2, 7, 30, 25, 20 }, 6, { 1, 2, 7, 20, 25, 20 } },
	{ { 1, 6, 5, 4 }, 4, { 1, 4, 5, 6 } },
	{ { 1, 2, 3, 6, 5, 4 }, 6, { 1, 2, 3, 4, 5, 6 } },
	
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
int compare(struct node *given, struct node *output)
{
	int flag = 0;
	struct node * temp = given;
	while (temp != NULL)
	{
		if (temp->num != output->num)
		{
			flag++;
			break;
		}
		temp = temp->next;
		output = output->next;
	}
	if (flag>0)return 0;
	else return 1;
}
struct node * reverse(struct node *head1)
{
	struct node *temp;
	if (head1->next == NULL || head1 == NULL)
		return head1;
	temp = reverse(head1->next);
	head1->next->next = head1;
	head1->next = NULL;
	return temp;
}
struct node *ascDesc(struct node *head)
{
	struct node *temp = head, *rev, *prev = head;
	int flag = 0, flag1 = 0;
	while (temp != NULL&&temp->next != NULL)
	{
		if (temp->num <= temp->next->num)
		{
			flag1++;
			prev = temp;
			temp = temp->next;
		}
		else
		{
			flag = 1;
			rev = reverse(temp);
			if (flag1 == 0)return rev;
			break;
		}
	}
	if (flag)prev->next = rev;
	return head;
}
void testMethods()
{
	int i, x;
	struct node *head = NULL, *given, *should_be, *output;
	for (i = 0; i<7; i++)
	{
		given = create(head, testCase[i].ip, testCase[i].size);
		output = ascDesc(given);
		head = NULL;
		should_be = create(head, testCase[i].op, testCase[i].size);
		x = compare(should_be, output);
		x ? printf("\n Passed") : printf("\n Failed");
	}
}
int main()
{
	testMethods();
	getchar();
	return 0;
}
