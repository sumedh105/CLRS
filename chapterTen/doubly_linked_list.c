#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

static void insert_end(struct node **root_node, int data);
static void insert_beg(struct node **root_node, int data);
static int del_end(struct node **root_node);
static int del_beg(struct node **root_node);
static void display(struct node *root_node);

int main()
{
	int data = 0;
	int choice = 0;
	struct node *root_node = NULL;

	while (1)
	{
		printf("\nEnter 0 to exit\n");
		printf("\nEnter 1 to insert the data at the end\n");
		printf("\nEnter 2 to insert the data at the beginning\n");
		printf("\nEnter 3 to delete the node from the end\n");
		printf("\nEnter 4 to delete the node from the beginning\n");
		printf("\nEnter 5 to display the doubly linked list\n");
		printf("\nEnter the choice\n");
		scanf("%d", &choice);

		switch (choice)
		{
			case 0:
				exit(1);
			case 1:
				printf("\nEnter the data that needs to be inserted\n");
				scanf("%d", &data);
				insert_end(&root_node, data);
				break;
			case 2:
				printf("\nEnter the data that needs to be inserted\n");
				scanf("%d", &data);
				insert_beg(&root_node, data);
				break;
			case 3:
				data = del_end(&root_node);
				printf("\nThe deleted data is: %d\n", data);
				break;
			case 4:
				data = del_beg(&root_node);
				printf("\nThe deleted data is: %d\n", data);
				break;
			case 5:
				display(root_node);
				break;
			default:
				break;

		}
	}

	return 0;
}

static void insert_end(struct node **root_node, int data)
{	
	struct node *cur = NULL;
	struct node *prev = NULL;

	cur = (struct node *)malloc(sizeof(struct node));
	cur->data = data;
	cur->next = NULL;
		
	if (*root_node == NULL)
	{
		cur->prev = NULL;
		*root_node = cur;
	}
	else
	{
		prev = *root_node;
		while (prev->next != NULL)
		{
			prev = prev->next;
		}
		prev->next = cur;
		cur->prev = prev;
	}
}

static void insert_beg(struct node **root_node, int data)
{
	struct node *temp = NULL;
	struct node *prev = NULL;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->prev = NULL;

	if (*root_node == NULL)
	{
		*root_node = temp;
	}
	else
	{
		prev = *root_node;
		temp->next = prev;
		prev->prev = temp;
		*root_node = temp;
	}
}

static int del_end(struct node **root_node)
{
	int data = 0;
	struct node *temp = NULL;
	struct node *prev = NULL;

	if (*root_node == NULL)
	{
		printf("\nList is empty, nothing can be removed from the list\n");
	}
	else
	{
		temp = *root_node;
		while (temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		data = temp->data;

		prev->next = NULL;
		free(temp);
	}

	return data;
}

static int del_beg(struct node **root_node)
{
	int data = 0;
	struct node *temp = NULL;
	struct node *prev = NULL;

	if (*root_node == NULL)
	{
		printf("\nList is empty, cannot remove anything from the list\n");
	}
	else
	{
		temp = *root_node;
		prev = temp->next;
		prev->prev = NULL;
		*root_node = prev;
		data = temp->data;
		free(temp);
	}

	return data;
}

static void display(struct node *root_node)
{
	struct node *temp = NULL;
	temp = root_node;

	while (temp != NULL)
	{
		printf("\n%d\n", temp->data);
		temp = temp->next;
	}
}
