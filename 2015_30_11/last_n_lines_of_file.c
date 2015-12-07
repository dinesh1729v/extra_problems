#include<stdio.h>
#include<stdlib.h>
char * lastKLines(FILE *f,int n)
{
	char *str = (char *)malloc(100l * sizeof(char)),s[100];
	FILE *f1,*t;
	f = fopen(s, "r");
	if (n <= 0)return '\0';
	int cnt = 0,i=0,flag=0;
	char ch;
	while ((ch = fgetc(f)) != EOF)
	{
		if (ch == '\n')cnt++;
	}
	
	fseek(f, 0, SEEK_SET);
	if (cnt <= n)
	{
		while ((ch = fgetc(f)) != EOF)
		{
			str[i] = ch;
			i++;
		}
		str[i] = '\0';
	}
	else
	{
		int diff = cnt - n;
		while (diff > 0)
		{
			ch = fgetc(f);
			if (ch == '\n')diff--;
		}
		while ((ch = fgetc(f)) != EOF)
		{
			str[i] = ch;
			i++;
		}
		str[i] = '\0';
	}

	
	return str;
}
int main()
{
	char *s;
	FILE *fp;
	int k;
	printf("enter the filename:");
	scanf("%s", s);
	fp = fopen(s, "r");
	printf("Enter the value of K:");
	scanf("%d",&k);
	s = lastKLines(fp,k);
	printf("Last n line are:\n%s",s);
	getch();
	return 0;
}