#include<stdio.h>
#include<stdlib.h>
struct test
{
	int ip[30], size, opsize, op[30], sum;
}testCase[10] = 
{ 
{ { 1, 2, 3, 4, 5, -2, -3, -4, -20, 10 }, 10, 5, { 1, 2, 3, 4, 5 }, 15 },
{ { -1011, 3, -579, 24, 16, -165, 2, -765, 10, -563 }, 10, 2, { 24, 16 }, 40 },
{ { 1, 2, 3, 5, -10, 20, 40 }, 7, 7, { 1, 2, 3, 5, -10, 20, 40 }, 61 },
{ { 0, -989, -3212, 15600 }, 4, 1, { 15600 }, 15600 }, 
{ { 1, 2, 3, 4, 5, 6 }, 6, 6, {1, 2, 3, 4, 5, 6}, 21 } ,
{ { -1, -2, -3, -4, -5 }, 5, 1, { -1 }, -1 },
};
struct output
{
	int sub_set[30],max;
};
int *allocate(int *a, int l)
{
	int i, *r;
	r = (int*)malloc(l*sizeof(int));
	for (i = 0; i<l; i++)
		r[i] = a[i];
	return r;
}
struct output maxSumSubArray(int *array, int len)
{
	struct output out;
	int max2 = array[0],l=0,r=0;
	int max1 = 0,b,s,i;
	s = i = 0;
	for (i = 0; i < len; i++)
	{
		max1 += array[i];
		if (max1 > max2) 
		{
			max2 = max1;
			l = s;
			r = i;
		}
		if (max1 < 0) 
		{
			max1 = 0;
			s = i + 1;
		}
	}
	out.max = max2;
	int j = 0;
	for (i = l; i <= r; i++)
	{
		out.sub_set[j] = array[i];
		j++;
	}
	return out;
}

int compare(int *subSet, int *result, int size, int sum, int maxSum)
{
	int flag1 = 0, i;
	for (i = 0; i < size; i++)
	{
		if (subSet[i] != result[i])
		{
			flag1++;
			break;
		}
	}
	if (flag1 == 0 && (sum == maxSum))return 1;
	return 0;
}
void testMethods()
{
	int i, *given,result, x;
	struct output final;
	for (i = 0; i<6; i++)
	{
		given = allocate(testCase[i].ip, testCase[i].size);
		final = maxSumSubArray(given, testCase[i].size);
		result = allocate(testCase[i].op, testCase[i].opsize);
		x = compare(final.sub_set, result, testCase[i].opsize,testCase[i].sum,final.max);
		x?printf("\n Passed"):printf("\n Failed");
	}
}
int main()
{
	testMethods();
	getchar();
}
/*struct output maxSumSubarray(int *arr, int len)
{

int max1 = 0,i;
int max2 = 0;
int r = 0, l = 0;
struct output res;
for (i = 0; i < len; i++){
if ((max1 + arr[i])<0)
{
max1 = 0;
}
else if (arr[i] >(max1 + arr[i])){
max1 = arr[i];
r = i;
}
else{
max1 = max1 + arr[i];
}

if (max1 >= max2){
max2 = max1;
l = i;
}
}
res.maxSum = max2;
int k = 0;
for (i = r; i <=l; i++)
{
res.subSet[k] = arr[i];
k++;
}
return res;
}*/