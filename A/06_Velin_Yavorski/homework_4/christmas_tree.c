#include<stdio.h>

void christmas(int height)
{
	int i,j,n;
	for(i=0;i<height;i++)
	{
		j=i;
		while(j!=height-1)
		{
			printf(" ");
			j++;
		}	
		n=i+i+1;
		for(j=0;j<n;j++)
		{
		printf("*");
		}
 		printf("\n");
	}
}

int main()
{
	christmas(4);
	christmas(7);
	christmas(11);	
	return 0;
}
