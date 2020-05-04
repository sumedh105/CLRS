#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 10

int orig_queue[MAXNUM];
int copied_queue[MAXNUM];
int orig_queue_head = 0;
int copied_queue_head = 0;
int orig_queue_tail = 0;
int copied_queue_tail = 0;

static int is_copied_queue_full();
static int is_copied_queue_empty();
static int is_orig_queue_full();
static int is_orig_queue_empty();
static void orig_queue_push(int data);
static void copied_queue_push(int data);
static void push(int data);
static int orig_queue_pop();
static int copied_queue_pop();
static int pop();
static void display();

static int is_copied_queue_full()
{
	if (copied_queue_tail == (MAXNUM - 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static int is_copied_queue_empty()
{
	if (copied_queue_head == copied_queue_tail)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


static int is_orig_queue_full()
{
	if (orig_queue_tail == (MAXNUM - 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static int is_orig_queue_empty()
{
	if (orig_queue_head == orig_queue_tail)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static void orig_queue_push(int data)
{
	if (is_orig_queue_full())
	{
		printf("\nQueue is full, cannot push the data into the stack\n");
	}
	else
	{
		orig_queue[orig_queue_tail++] = data;
	}
}

static void copied_queue_push(int data)
{
	copied_queue[copied_queue_tail++] = data;
}

static void push(int data)
{
	while (is_orig_queue_empty() == 0)
	{
		copied_queue_push(orig_queue_pop());
	}
	orig_queue_head = orig_queue_tail = 0;

	orig_queue_push(data);

	while (is_copied_queue_empty() == 0)
	{
		orig_queue_push(copied_queue_pop());
	}
	copied_queue_head = copied_queue_tail = 0;
}

static int orig_queue_pop()
{
	int data = 0;
	data = orig_queue[orig_queue_head++];
	return data;
}

static int copied_queue_pop()
{
	int data = 0;
	data = copied_queue[copied_queue_head++];
	return data;
}

static int pop()
{
	int data = 0;

	if (is_orig_queue_empty())
	{
		printf("\nStack underflow, nothing can be popped from the stack\n");
	}
	else
	{
		data = orig_queue_pop();
	}

	return data;
}

static void display()
{
	int index = 0;

	for (index = orig_queue_head; index < orig_queue_tail; ++index)
	{
		printf("\n%d\n", orig_queue[index]);
	}
}

int main()
{
	int choice = 0;
	int data = 0;

	while (1)
	{
		printf("\nEnter 0 to exit\n");
		printf("\nEnter 1 to push the data into the stack\n");
		printf("\nEnter 2 to pop the data from the stack\n");
		printf("\nEnter the choice\n");
		scanf("%d", &choice);

		switch (choice)
		{
			case 0:
				exit(1);
			case 1:
				printf("\nEnter the data that needs to be pushed in the stack\n");
				scanf("%d", &data);
				push(data);
				display();
				break;
			case 2:
				data = pop();
				display();
				break;
			default:
				break;
		}
	}

	return 0;
}
