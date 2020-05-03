#include <stdio.h>
#include <stdlib.h>

struct queue
{
	int head;
	int tail;
	int *queue_array;
	int queue_capacity;
};

static int is_queue_empty(struct queue *q);
static int is_queue_full(struct queue *q);
static void enqueue(struct queue *q, int data);
static int dequeue(struct queue *q);
struct queue *create_queue(int capacity);
static void delete_queue(struct queue *q);
static void display(struct queue *q);

int main()
{
	struct queue *q = NULL;
	int capacity = 0;
	int choice = 0;
	int data = 0;

	printf("\nEnter the capacity of the queue\n");
	scanf("%d", &capacity);
	printf("\nThe queue capacity is: %d\n", capacity);

	q = create_queue(capacity);

	while (1)
	{
		printf("\nEnter 0 to exit the queue\n");
		printf("\nEnter 1 to enqueue\n");
		printf("\nEnter 2 to dequeue\n");
		printf("\nEnter 3 to display the queue\n");

		printf("\nEnter the choice\n");
		scanf("%d", &choice);

		switch (choice)
		{
			case 0:
				delete_queue(q);
				exit(1);
			case 1: 
				printf("\nEnter the data that needs to be pushed in the queue\n");
				scanf("%d", &data);
				enqueue(q, data);
				break;
			case 2:
				data = dequeue(q);
				printf("\nThe dequeued element is: %d\n", data);
				break;
			case 3: 
				display(q);
				break;
			default:
				break;
		}
	}

	return 0;
}

static int is_queue_empty(struct queue *q)
{
	if (q->head == q->tail)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static int is_queue_full(struct queue *q)
{
	if ((q->head == (q->tail + 1)))
	{
		return 1;
	}
	else if ((q->head == 0) && (q->tail == (q->queue_capacity - 1)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static void enqueue(struct queue *q, int data)
{
	if (is_queue_full(q))
	{
		printf("\nQueue is full, cannot insert anything in the queue\n");
	}
	else
	{
		q->queue_array[q->tail] = data;
		if (q->tail == (q->queue_capacity - 1))
		{
			q->tail = 0;
		}
		else
		{
			q->tail = q->tail + 1;
		}
	}
}

static int dequeue(struct queue *q)
{
	int data = 0;

	if (is_queue_empty(q))
	{
		printf("\nQueue is empty, cannot remove anything from the queue\n");
	}

	else
	{
		data = q->queue_array[q->head];
		if (q->head == (q->queue_capacity - 1))
		{
			q->head = 0;
		}
		else
		{
			q->head = q->head + 1;
		}
	}

	return data;
}

struct queue *create_queue(int capacity)
{
	struct queue *q = NULL;

	q = (struct queue *)malloc(sizeof(struct queue));

	q->head = 0;
	q->tail = 0;
	q->queue_capacity = capacity;
	q->queue_array = (int *)malloc(capacity * sizeof(int));

	return q;

}

static void display(struct queue *q)
{
	int index = 0;

	for (index = q->head; index < q->tail; ++index)
	{
		printf("\n%d\n", q->queue_array[index]);
	}
}

static void delete_queue(struct queue *q)
{
	free(q->queue_array);
	free(q);
}
