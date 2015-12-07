#include<stdio.h>
struct test
{
	int n1, n2, k, ans;
}testCase[10] = 
{  { 6, 7, 1, 6 }, { 64, 128, 2, 128 }, { 13, 15, 3, 26 }, { 27, 36, 5, 81 },
{ 2, 3, 6, 9 }, { 3, 5, 6, 10 }, { 465, 64, 646, 36416 }, { 684, 874, 569, 223744 } };
int gcd(int n, int m)
{
	if(n==0)return m;
	if(m==0)return n;
	return gcd(m, n%m);
}
int findKthElement(int n1, int n2, int k)
{
	if (k <= 0)return -1;
	int lcm,l,h,mid,r,count;
	lcm = (n1*n2) / gcd(n1, n2);
	l = 0; h = (n1*k)+1;
	while (h - l>1)
	{
		mid = (h + l) / 2;
		count = (mid / n1) + (mid / n2) - (mid / lcm);
		if (count >= k)
			h = mid;
		else l = mid;
	}
	return h;
}
void testMethods()
{
	for (int i = 0; i < 10; i++)
		findKthElement(testCase[i].n1, testCase[i].n2, testCase[i].k)== testCase[i].ans? printf("\nPassed"): printf("\nFailed");
}
int main()
{
	testMethods();
	getch();
	return 0;
}
