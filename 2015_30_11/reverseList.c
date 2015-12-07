#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
};
struct test
{
	int input[30];
	int size;
	int output[30];
}
testCase[10] = 
{ 
	{ { 1729 }, 1, { 1729 } }, 
	{ { 1, 1 }, 2, { 1, 1 } }, { { -1 }, 1, { -1 } }, 
	{ { -34, 53, -83, -53 ,-34}, 5, {-34,-53,-83,53,-34} } 
	{{ 1, 2, 3, 4, 5,6,7,8, }, 5, {8,7,6, 5, 4, 3, 2, 1 }}
};
struct node * create(struct node * head, int *givenList, int size)
{
	int i, n;
	struct node *prev;
	for (i = 0; i < size; i++)
	{
		struct node * new = (struct node*)malloc(sizeof(struct node));
		new->num = givenList[i];
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
int compare(struct node *expecHead, struct node *obserHead)
{
	int flag = 0;
	struct node * temp = expecHead;
	while (temp!=NULL)
	{
		if (temp->num != obserHead->num)
		{
			flag++;
			break;
		}
		temp = temp->next;
		obserHead = obserHead->next;
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
void testMethods()
{
	int i, x;
	struct node *head = NULL, *givenList, *expecList, *obsList;
	for (i = 0; i<5; i++)
	{
		givenList = create(head, testCase[i].input, testCase[i].size);
		obsList = reverse(givenList);
		head = NULL;
		expecList = create(head, testCase[i].output, testCase[i].size);
		x = compare(expecList, obsList);
		x? printf("\n Passed"):printf("\n Failed");
	}
}
int main()
{
	testMethods();
	getchar();
	return 0;
}

