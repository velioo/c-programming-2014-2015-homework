#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STARTING_SIZE 100
struct stack_t {
int *data, top, size;
};
	void stack_init(struct stack_t*);
	void stack_destroy(struct stack_t*);
	int stack_get_size(struct stack_t*);
	int stack_increase_size(struct stack_t*);
	int stack_reduce_size(struct stack_t*);
	int stack_resize(struct stack_t*);
	void transfer_data(int*, int, int*);
	void stack_push(struct stack_t*, int value);
	int stack_pop(struct stack_t*);
	void stack_copy(struct stack_t *from, struct stack_t *to);

int main()
{
	struct stack_t stack;
	int res,i,val1,val2,val,j;	
	char ops[STARTING_SIZE];

	printf("Enter math expression:\n");
	scanf("%s",ops);
	stack_init(&stack);
	j = strlen(ops);
	for(i = 0; i <= j; i++)
	{
		if (ops[i] >= '0' && ops[i] <= '9')
		{
			val = ops[i] - '0';
			stack_push(&stack, val);
		}
		else
			if((ops[i] == '+') || (ops[i] == '-') || (ops[i] == '*') || (ops[i] == '/'))
			{
				if(stack_get_size(&stack) < 2)
				return INT_MIN;
			}
			else
			{
				val2 = stack_pop(&stack);
				val1 = stack_pop(&stack);
				switch(ops[i])
				{
					case '+':
						res = val1 + val2;
						break;

					case '-':
						res = val1 - val2;
						break;

					case '*':
						res = val1 * val2;
						break;

					case '/':
						res = val1 / val2;
						break;
				}
				stack_push(&stack, res);
			}
	}
	if (stack_get_size(&stack) == 1)
		printf("Result: %d\n", res);
	else
		return INT_MAX;
	stack_destroy(&stack);
	return 0;
}

void stack_init(struct stack_t* s) {
	s->size = STARTING_SIZE;
	s->top = 0;
	s->data = (int*) malloc(s->size * sizeof(int));
}
void stack_destroy(struct stack_t* s){
	free(s->data);
	s->size = 0;
	s->top = 0;
}
int stack_get_size(struct stack_t* s) {
	return s->top;
}
void stack_push(struct stack_t* s, int value) {
	if (s->top == s->size)
	stack_increase_size(s);
	s->data[s->top++] = value;
}
int stack_pop(struct stack_t* s) {
	if(s->top == 0)
		return INT_MIN; //for error returns the minimum value of int, because it is the least possible number to actually be in the stack
	if(s->top <= s->size / 2 && s->size > STARTING_SIZE)
		stack_reduce_size(s);
	return s->data[--s->top];
}
void transfer_data(int *old_data, int old_data_size, int *new_data)
{
	int i;
	for(i = 0; i < old_data_size; ++i)
	new_data[i] = old_data[i];
	}
//returns: 0 if it worked out OK and -1 if something went wrongZ
int stack_increase_size(struct stack_t *s)
{
		s->size *= 2;
		if(stack_resize(s) == -1)
			return -1;
		return 0;
}
//returns: 0 if it worked out OK and -1 if something went wrong
int stack_reduce_size(struct stack_t *s)
{
		s->size /= 2;
		if(stack_resize(s) == -1)
			return -1;
		return 0;
}
//returns: 0 if it worked out OK and -1 if something went wrong
int stack_resize(struct stack_t *s)
{
	int *new_data = (int*)malloc(sizeof(int) * s->size);
	transfer_data(s->data, s->size, new_data);
	free(s->data);
	s->data = new_data;
	if(s->data == NULL)
		return -1;
	return 0;
}
void stack_copy(struct stack_t *from, struct stack_t *to)
{
	to->data = (int*)malloc(from->size * sizeof(int));
	transfer_data(from->data, from->size, to->data);
	to->size = from->size;
	to->top = from->top;
}
