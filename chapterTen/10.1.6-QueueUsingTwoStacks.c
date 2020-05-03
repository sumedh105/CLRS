#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 10

int original_stack[MAXNUM];
int copied_stack[MAXNUM];
int original_stack_top = -1;
int copied_stack_top = -1;

static void original_stack_push(int data);
static void copied_stack_push(int data);
static int original_stack_pop();
static int copied_stack_pop();
static int pop();
static void display();
static int is_stack_full();
static int is_stack_empty();

int main()
{
	int data = 0;
	int choice = 0;

	while (1)
	{
		printf("\nEnter 0 to exit\n");
		printf("\nEnter 1 to push data in the stack\n");
		printf("\nEnter 2 to remove the data from the stack\n");
		printf("\nEnter 3 to display the stack\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				exit(1);
			case 1:
				printf("\nEnter the data that needs to be entered in the stack\n");
				scanf("%d", &data);
				original_stack_push(data);
				break;
			case 2:
				data = pop();
				printf("\nThe data popped from the stack is: %d\n", data);
				break;
			case 3: 
				display();
				break;
			default:
				break;
		}
	}

	return 0;
}

static void original_stack_push(int data)
{
	if (is_stack_full())
	{
		printf("\nStack is full, cannot push elements in the stack\n");
	}
	else
	{
		original_stack[++original_stack_top] = data;
	}
}

static void copied_stack_push(int data)
{
	copied_stack[++copied_stack_top] = data;
}

static int original_stack_pop()
{
	int data = 0;

	data = original_stack[original_stack_top--];
	return data;
}

static int pop()
{
	int data = 0;

	if (is_stack_empty())
	{
		printf("\nOriginal stack is empty, cannot remove elements from the stack\n");
	}
	else
	{
		while (original_stack_top != -1)
		{
			copied_stack_push(original_stack_pop());
		}
		data = copied_stack_pop();
		while (copied_stack_top != -1)
		{
			original_stack_push(copied_stack_pop());
		}
	}

	return data;
}

static int copied_stack_pop()
{
	int data = 0;

	data = copied_stack[copied_stack_top--];

	return data;
}

static void display()
{
	int index = 0;

	for (index = 0; index <= original_stack_top; ++index)
	{
		printf("\n%d\n", original_stack[index]);
	}
}

static int is_stack_full()
{
	if (original_stack_top == (MAXNUM - 1))
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
	if (original_stack_top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
