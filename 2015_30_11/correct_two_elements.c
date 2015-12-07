#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
};
struct test
{
	int ip[30],len,op[30];
}
testCase[10] = 
{
	{ { 1, 2, 3, 4, 5, 6, 7, 9, 8 }, 9, { 1, 2, 3, 4, 5, 6, 7, 8, 9 } },
	{ { 1, 2, 3, 5, 4, 6, 7, 8 }, 8, { 1, 2, 3, 4, 5, 6, 7, 8 } },
	{ { 9, 2, 3, 4, 5, 6, 7, 8, 1 }, 9, { 1, 2, 3, 4, 5, 6, 7, 8, 9 } },
	{ { 2, 1, 3, 4, 5, 6, 7, 8, 9 }, 9, {1, 2, 3, 4, 5, 6, 7, 8, 9} },
	{ { 1, 8, 3, 4, 5, 6, 7, 2, 9 }, 9, { 1, 2, 3, 4, 5, 6, 7, 8, 9 } },
	{ { -1, -8, -7, -6, -5, -4, -3, -2, -9 }, 9, { -9, -8, -7, -6, -5, -4, -3, -2, -1 } },
	{ { -9, -2, -7, -6, -5, -4, -3, -8, -1 },9, { -9, -8, -7, -6, -5, -4, -3, -2, -1 } },
	{ {3,-2,-1,0,1,2,-3}, 7,{-3,-2,-1,0,1,2,3} }
};
void swap(int *num1, int *num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
struct node * create(struct node * head, int *givenList, int len)
{
	int i, n;
	struct node *prev;
	for (i = 0; i < len; i++)
	{
		struct node * newNode = (struct node*)malloc(sizeof(struct node));
		newNode->num = givenList[i];
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
struct node * correcTwo(struct node *head)
{
	struct node *cur1 = head, *prev1 = head, *sprev1 = head, *cur2, *prev2, *next2;
	int flag1 = -1, flag2 = -1, temp;
	while (cur1 != NULL)
	{
		if (prev1->num > cur1->num)
		{
			flag1++;
			break;
		}
		prev1 = cur1;
		cur1 = cur1->next;
	}
	if (flag1 == -1)return head;
	prev2 = cur1;
	cur2 = cur1->next;
	while (cur2 != NULL)
	{
		if (prev2->num > cur2->num)
		{
			flag2++;
			break;
		}
		prev2 = cur2;
		cur2 = cur2->next;
	}
	if (flag1 != -1 && flag2 != -1)
		swap(&(prev1->num), &(cur2->num));
	else if (flag1 != -1 && flag2 == -1)
		swap(&(prev1->num), &(cur1->num));
	return head;
}
int compare(struct node *expecHead, struct node *obserHead)
{
	int flag = 0;
	struct node * temp = expecHead;
	while (temp != NULL)
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

void testMethods()
{
	int i, ans;
	struct node *head = NULL, *givenList, *expecList, *obsList;
	for (i = 0; i<8; i++)
	{
		givenList = create(head, testCase[i].ip, testCase[i].len);
		obsList = correcTwo(givenList);
		head = NULL;
		expecList = create(head, testCase[i].op, testCase[i].len);
		ans = compare(expecList, obsList);
		ans?	printf("\n Passed"):printf("\n Failed");
	}
}
int main()
{
	testMethods();
	getchar();
	return 0;
}
