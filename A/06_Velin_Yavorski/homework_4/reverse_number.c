#include<stdio.h>

void reverse(int number)
{
	int i;
	while(number!=0)
	{
		i=number%10;
		printf("%d",i);
		number=number/10;
	}
	printf("\n");
}	

int main()
{
	reverse(5170984);
	reverse(406567);
	reverse(368750);
	reverse(2369510);
	reverse(2183293);
return 0;
}
