#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 10

int queue[MAXNUM];
int head = -1;
int tail = -1;

static int is_queue_empty();
static int is_queue_full();
static int enqueue(int data);
static int dequeue();
static void display();

int main()
{
	int choice = 0;
	int data = 0;
	int ret_val = 0;

	while (1)
	{
		printf("\nEnter 0 to exit the queue\n");
		printf("\nEnter 1 to push the data in the queue\n");
		printf("\nEnter 2 to pop the data from the queue\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				exit(1);
			case 1:
				printf("\nEnter the data that needs to be pushed in the queue\n");
				scanf("%d", &data);
				ret_val = enqueue(data);
				display();
				break;
			case 2:
				data = dequeue();
				display();
				break;
			default:
				break;
		}
	}

	return 0;
}

static int is_queue_empty()
{
	if ((head == -1) && (tail == -1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static int is_queue_full()
{
	if (tail == (MAXNUM - 1) && (head == 0))
	{
		return 1;
	}
	else if (head == (tail + 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static int enqueue(int data)
{
	if (is_queue_full())
	{
		printf("\nQueue overflow, cannot insert data in the queue\n");
		return -1;
	}
	else if (head == -1)
	{
		head = 0;
	}
	else if (tail == (MAXNUM - 1))
	{
		tail = -1;
	}
	queue[++tail] = data;

	return 0;
}

static int dequeue()
{
	int data = 0;

	if (is_queue_empty())
	{
		printf("\nQueue underflow, cannot remove anything from the queue\n");
		return -1;
	}
	else if (head == (MAXNUM - 1))
	{
		data = queue[head];
		head = 0;
	}
	else
	{
		data = queue[head++];
	}

	return data;
}

static void display()
{
	if (is_queue_empty())
	{
		printf("\nQueue empty, nothing to be displayed\n");
	}
	else
	{
		int index = 0;

		if (tail > head)
		{
			for (index = head; index <= tail; ++index)
			{
				printf("\n%d\n", queue[index]);
			}
		}
		else if (head > tail)
		{
			for (index = head; index < MAXNUM; ++index)
			{
				printf("\n%d\n", queue[index]);
			}
			for (index = 0; index <= tail; ++index)
			{
				printf("\n%d\n", queue[index]);
			}
		}
	}
}
