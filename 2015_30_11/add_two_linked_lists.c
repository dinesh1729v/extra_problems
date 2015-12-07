#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
};
struct test
{
	int ip1[30], len1, ip2[30], len2, len, op[30];
}
testCase[15] =
{ 
{ { 1, 2, 3 }, 3, { 1, 2, 3 }, 3, 3, { 2, 4, 6 } },
{ { 1, 1, 1 }, 3, { 0 }, 1, 3, { 1, 1, 1 } },
{ { 0, 0, 0 }, 3, { 0, 0, 0 }, 3, 1, { 0 } },
{ { 7, 8, 9 }, 3, { 5, 7, 5 }, 3, 4, { 1, 3, 6, 4 } },
{ { 0 }, 1, { 0 }, 1, 1, { 0 } },
{ { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 }, 10, { 1 }, 1, 11, { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
{ { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11, { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 }, 10, 11, { 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 } }
};
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
struct node * same_length(struct node *head1, struct node *head2, int *carry)
{
	int sum = 0;
	if (head1 == NULL)return head1;
	struct node*temp = (struct node *)malloc(sizeof(struct node));
	temp->next = addSameLength(head1->next, head2->next, carry);
	sum = head1->num + head2->num + *carry;
	*carry = sum / 10;
	temp->num = sum % 10;
	return temp;
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
int length(struct node *head)
{
	struct node *temp = head;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
void insert(struct node** head, int num)
{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = (*head);
	(*head) = newNode;
}
struct node* carryy(struct node *temp1, struct node *head1, int *carry, struct node *result)
{
	int sum;
	struct node*result1;
	if (head1 != temp1)
	{
		addCarry(temp1, head1->next, carry, result);
		sum = head1->num + (*carry);
		*carry = sum / 10;
		sum = sum % 10;
		insert(result, sum);
	}
}
void add(struct node *head1, struct node *head2, struct node **result)
{
	struct node *temp1 = head1, *temp2 = head2, *temp;
	int len1, len2, carry = 0, diff = 0;
	len1 = length(head1);
	len2 = length(head2);
	diff = abs(len2 - len1);
	if (len1<len2)
	{
		temp = head1;
		head1 = head2;
		head2 = temp;
	}
	for (temp1 = head1; diff--; temp1 = temp1->next);
	*result = same_length(temp1, head2, &carry);
	carryy(temp1, head1, &carry, result);
	if (carry == 1)	insert(result, carry);
}

void testMethods()
{
	int i, x;
	struct node *head = NULL, *givenList1, *givenList2, *should_be, *output;
	for (i = 0; i<7; i++)
	{
		givenList1 = create(head, testCase[i].ip1, testCase[i].len1);
		givenList2 = create(head, testCase[i].ip2, testCase[i].len2);
		add(givenList1, givenList2, &output);
		head = NULL;
		should_be = create(head, testCase[i].op, testCase[i].len);
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

