#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 10

int queue[MAXNUM];
int head = 0;
int tail = 0;

static int is_queue_empty()
{
	if (head == tail)
		return 1;
	else
		return 0;
}

static int is_queue_full()
{
	if ((head == 0) && (tail == (MAXNUM - 1)))
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

static void head_enqueue(int data)
{
	if (is_queue_full())
	{
		printf("\nQueue full, cannot insert anything in the queue\n");
	}
	else
	{
		if (head == 0)
		{
			head = (MAXNUM - 1);
		}
		else
		{
			head = (head - 1);
		}
		queue[head] = data;
	}
}

static int head_dequeue()
{
	int data = 0;

	if (is_queue_empty())
	{
		printf("\nQueue empty, cannot remove anything from the queue\n");
	}
	else
	{
		data = queue[head];
		if (head == (MAXNUM - 1))
		{
			head = 0;
		}
		else
		{
			head = (head + 1);
		}
	}

	return data;
}

static void tail_enqueue(int data)
{
	if (is_queue_full())
	{
		printf("\nQueue full, cannot insert anything in the queue\n");
	}
	else
	{
		queue[tail] = data;
		if (tail == (MAXNUM - 1))
		{
			tail = 0;
		}
		else
		{
			tail = (tail + 1);
		}
	}
}

static int tail_dequeue()
{
	int data = 0;

	if (is_queue_empty())
	{
		printf("\nQueue empty, nothing can be removed from the queue\n");
	}
	else
	{
		if (tail == 0)
		{
			tail = (MAXNUM - 1);
		}
		else
		{
			tail = (tail - 1);
		}
		data = queue[tail];
	}

	return data;
}

static void display()
{
	int index = 0;

	if (head < tail)
	{
		printf("\n__LINE__: %d\t head: %d\t tail: %d\n", __LINE__, head, tail);
		for (index = head; index < tail; ++index)
		{
			printf("\n%d\n", queue[index]);
		}
	}
	else if (tail < head)
	{
		printf("\n__LINE__: %d\t head: %d\t tail: %d\n", __LINE__, head, tail);
		for (index = 0; index <= tail; ++index)
		{
			printf("\n%d\n", queue[index]);
		}
		for (index = head; index <= (MAXNUM - 1); ++index)
		{
			printf("\n%d\n", queue[index]);
		}
	}
}

int main()
{
	int choice = 0;
	int data = 0;

	while (1)
	{
		printf("\nEnter 0 to exit\n");
		printf("\nEnter 1 to head enqueue\n");
		printf("\nEnter 2 to head dequeue\n");
		printf("\nEnter 3 to tail enqueue\n");
		printf("\nEnter 4 to tail dequeue\n");
		printf("\nEnter 5 to display\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch (choice)
		{
			case 0:
				exit(1);
			case 1:
				printf("\nEnter the data that needs to be pushed at the head of the queue\n");
				scanf("%d", &data);
				head_enqueue(data);
				break;
			case 2:
				data = head_dequeue();
				printf("\nThe dequeued data is: %d\n", data);
				break;
			case 3:
				printf("\nEnter the data that needs to be pushed at the tail of the queue\n");
				scanf("%d", &data);
				tail_enqueue(data);
				break;
			case 4:
				data = tail_dequeue();
				printf("\nThe dequeued data is: %d\n", data);
				break;
			case 5:
				display();
				break;
			default:
				break;
		}
	}

	return 0;
}
