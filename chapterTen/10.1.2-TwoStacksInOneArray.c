#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 10
#define STACKONE 1
#define STACKTWO 2

int stack[MAXNUM];
int stack_one_top = -1;
int stack_two_top = MAXNUM;

static void push(int stack_number, int data);
static int pop(int stack_number);
static void display(int stack_number);
static int is_stack_full();
static int is_stack_empty();

int main()
{
	int data = 0;
	int choice = 0;
	int stack_number = 0;

	while (1)
	{
		printf("\nEnter 0 to exit\n");
		printf("\nEnter 1 to push an element in the stack\n");
		printf("\nEnter 2 to pop an element from the stack\n");
		printf("\nEnter 3 to display the stack\n");
		printf("\nEnter the choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				exit(1);
			case 1:
				printf("\nEnter the stack number on which the data must be pushed\n");
				scanf("%d", &stack_number);
				printf("\nEnter the data that needs to be pushed\n");
				scanf("%d", &data);
				push(stack_number, data);
				break;
			case 2:
				printf("\nEnter the stack number from which the stack must be popped\n");
				scanf("%d", &stack_number);
				data = pop(stack_number);
				printf("\nThe popped element is: %d\n", data);
				break;
			case 3:
				printf("\nEnter the stack number that needs to be displayed\n");
				scanf("%d", &stack_number);
				display(stack_number);
				break;
			default:
				break;
		}
	}

	return 0;
}

static void push(int stack_number, int data)
{
	if (is_stack_full())
	{
		printf("\nStack is full, cannot push anything in the stack\n");
	}	
	else if (stack_number == STACKONE)
	{
		stack[++stack_one_top] = data;
	}
	else if (stack_number == STACKTWO)
	{
		stack[--stack_two_top] = data;
	}
}

static int pop(int stack_number)
{
	int data = 0;

	if (is_stack_empty())
	{
		printf("\nStack is empty, nothing can be removed from the stack\n");
	}
	else if (stack_number == STACKONE)
	{
		data = (stack[stack_one_top--]);
		return data;
	}
	else if (stack_number == STACKTWO)
	{
		data = (stack[stack_two_top--]);
		return data;
	}
}

static void display(int stack_number)
{
	int index = 0;
	printf("\nstack_one_top: %d\t stack_two_top: %d\n", stack_one_top, stack_two_top);

	if (is_stack_empty())
	{
		printf("\nStack is empty, nothing can be displayed\n");
	}
	else if (stack_number == STACKONE)
	{
		for (index = 0; index <= stack_one_top; ++index)
		{
			printf("\n%d\n", stack[index]);
		}
	}
	else if (stack_number == STACKTWO)
	{
		for (index = stack_two_top; index < MAXNUM ; ++index)
		{
			printf("\n%d\n", stack[index]);
		}
	}
}

static int is_stack_full()
{
	if ((stack_two_top - stack_one_top) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static int is_stack_empty()
{
	if ((stack_one_top == -1) && (stack_two_top == MAXNUM))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
