#include<stdio.h>

void E();
void T();
void E1();
void T1();
void F();

char s[100];
int i, SIGN;

int main()
{
	printf("请输入一个语句，以#号结束语句（直接输入#号推出）\n");
	while( 1 )
	{
		SIGN = 0;
		i=0;
		
		scanf("%s",&s);

		if( s[0] == '#')
			return 0;

		E();
		
		if(s[i]=='#')
			printf("正确语句！\n");

		printf("请输入一个语句，以#号结束语句\n");

	}
	return 1;
}

void E()
{
	if(SIGN==0)
	{
		T();
		E1();
	}
}

void E1()
{
	if(SIGN==0)
	{
		if(s[i]=='+')
		{
			++i;
			T();
			E1();
		}
		else if(s[i]!='#'&&s[i]!=')')
		{
			printf("语句有误！\n");
			SIGN=1;
		}
	}
}

void T()
{
	if(SIGN==0)
	{
		F();
		T1();
	}
}

void T1()
{
	if(SIGN==0)
	{
		if(s[i]=='*')
		{
			++i;
			F();
			T1();
		}
		else if(s[i]!='#'&&s[i]!=')'&&s[i]!='+')
		{
			printf("语句有误！\n");
			SIGN=1;
		}
	}
}

void F()
{
	if(SIGN==0)
	{
		if(s[i]=='(')
		{
			++i;
			E();
			if(s[i]==')')
				++i;
			else if(s[i]== '#')
			{
				printf("语句有误！\n");
				SIGN=1;
				++i;
			}
		}
		else if(s[i]=='i')
			++i;
		else
		{
			printf("语句有误！\n");
			SIGN=1;
		}
	}
}
