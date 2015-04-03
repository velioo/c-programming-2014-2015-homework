#include<stdio.h>
#include<string.h>
#define MAXSTACK 100
#define EMPTYSTACK 0
int top = EMPTYSTACK;
char skobi[MAXSTACK];

void push(char);
char pop();
	

int main()
{
	
	int i,j,k = 0;
	char ch[100];
	scanf("%s", ch);
	j = strlen(ch);
	
	for (i = 0; i <= j; i++)
	{
		if((ch[i] =='(') || (ch[i] =='{') || (ch[i] =='['))
		{
			push(ch[i]);
			k++;
		}
		else
			if((ch[i] == ')') || (ch[i] == '}') || (ch[i] == ']'))
			switch(ch[i])
			{	
				case ')':
					if(pop() == '(')
						k--;	
					else 
					{
						printf("Nebalansirani skobi !\n");
						return -1;
					}
					break;
				case '}':
					if(pop() == '{')
						k--;	
					else 
					{
						printf("Nebalansirani skobi !\n");
						return -1;
					}
					break;
				case ']':
					if(pop() == '[')
						k--;	
					else 
					{
						printf("Nebalansirani skobi !\n");
						return -1;
					}
					break;
				default:
					break;
				
			}
				
	}
	if(k != 0)
			printf("Nebalansirani skobi\n");
		else
			printf("Balansirani skobi\n");

return 0;
}

void push(char c){
	skobi[top] = c;
	top++;
}

char pop () {
	return skobi[--top];
}

